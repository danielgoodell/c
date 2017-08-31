/*	Rewrite readlines to store lines in an array supplied by main rather 
	than calling alloc to maintain storage. How much faster is the program?
	
	Note: I used a large array declared in main and passed onto readlines.
	readlines just increments the pointed in the array each time a line is read.
	
	Speed comparison:
	daniel@daniel-VirtualBox:~/c/5$ time ./7-bookver < mobydick.txt 
		real	0m0.506s
		user	0m0.008s
		sys	0m0.004s
		
	daniel@daniel-VirtualBox:~/c/5$ time  ./7 < mobydick.txt		
		real	0m0.508s
		user	0m0.008s
		sys	0m0.004s
		
	The speed difference is very minor. Partly I think skipping alloc doesn't
	really save that much time and partly maybe the program is limited more by I/O
	than by time required to allocate memory and return the pointer.
*/

#include <stdio.h>
#include <string.h>

#define MAXLEN 1000	//max length of any input line
#define MAXLINES 5000	//max # of lines to be sorted.
#define ALLOCSIZE 10000000 // size of available space

char * lineptr[MAXLINES];

int readlines(char *lineptr[], int nlines, char *allocbuf);
void writelines(char *lineptr[], int nlines);
int getline(char *, int);
void qsort(char *lineptr[], int left, int right);
void swap(char *v[], int i, int j);
int strncomp(char *s, char *t);

// sort input lines

int main(void)
{
	int nlines;	//number of input lines read
	static char allocbuf[ALLOCSIZE]; 	//array to be passed by main.
	
	
	if ((nlines = readlines(lineptr, MAXLINES, allocbuf)) >= 0) {
		qsort(lineptr, 0, nlines-1);
		writelines(lineptr, nlines);
		return 0;
	} else {
		printf("error: input too big to sort\n");
		return 1;
	}
}

//readlines : read input lines
int readlines(char *lineptr[], int maxlines, char * allocbuf)
{
	int len, nlines;
	char *p, line[MAXLINES];
	
	nlines = 0;
	p = allocbuf;
	while ((len = getline(line, MAXLEN)) > 0){
		if (nlines >= maxlines)
			return -1;
		else {
			line[len-1] = '\0';	//delete newline
			strcpy(p, line);
			lineptr[nlines++] = p;
			p += len;
		}
	}
	return nlines;
}

//writelines: write output lines
void writelines(char *lineptr[], int nlines)
{
	int i;

	for (i = 0; i< nlines; i++)
		printf("%s\n", lineptr[i]);
}

//qsort: sort v[left]...v[right] int increasing order 
void qsort(char *v[], int left, int right)
{
	int i, last;

	
	if (left >= right)	//Do nothing if array contains
		return;		//fewer than two elements
	swap(v, left, (left + right)/2);
	last = left;
	for (i = left+1; i <= right; i++)
		if (strncomp(v[i], v[left]) < 0)
			swap(v, ++last, i);
	swap(v, left, last);
	qsort(v, left, last-1);
	qsort(v, last+1, right);
}

//swap: interchange v[i], and v[j]
void swap(char *v[], int i, int j)
{
	char *temp;
	
	temp = v[i];
	v[i] = v[j];
	v[j] = temp;
}

int getline(char s[], int lim)
{
	int c, i;

	for(i=0; (c=getchar())!=EOF && c!='\n'; ++i){
		if (i<lim-1)
			s[i] = c;
	}
	if (i>lim-1){
	if (c == '\n') {
		s[lim-1] = ' ';
		++i;
 	}
	s[lim]= '\0';
	}
	else{
	if (c == '\n') {
		s[i] = ' ';
		++i;
	}
		s[i]='\0';
	}
	return i;
}

int strncomp(char *s, char *t)
{
	while(*s++ == *t++){
		if (*s == 0)
			return 0;
	}
		return *--s - *--t;
}

