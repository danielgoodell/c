/*	Rewrite readlines to store lines in an array supplied by main rather 
	than calling alloc to maintain storage. How much faster is the program?
	
	NOTE: This is the version of the sort program from the book to use 
	as a speed comparison to the version that does not use alloc.
	The only change was to increase ALLOCSIZE to allow us to sort 5000
	lines of Moby Dick to make for a better time comparison.
*/

#include <stdio.h>
#include <string.h>

#define MAXLEN 1000	//max length of any input line
#define MAXLINES 5000	//max # of lines to be sorted.
#define ALLOCSIZE 10000000 // size of available space

char * lineptr[MAXLINES];
static char allocbuf[ALLOCSIZE];	// storage for alloc
static char *allocp = allocbuf;		//next free position

int readlines(char * lineptr[], int nlines);
void writelines(char *lineptr[], int nlines);
int getline(char *, int);
char *alloc(int);
void qsort(char *lineptr[], int left, int right);
void swap(char *v[], int i, int j);
int strncomp(char *s, char *t);

// sort input lines

int main(void)
{
	int nlines;	//number of input lines read
	
	if ((nlines = readlines(lineptr, MAXLINES)) >= 0) {
		qsort(lineptr, 0, nlines-1);
		writelines(lineptr, nlines);
		return 0;
	} else {
		printf("error: input too big to sort\n");
		return 1;
	}
}

//readlines : read input lines
int readlines(char *lineptr[], int maxlines)
{
	int len, nlines;
	char *p, line[MAXLINES];
	
	nlines = 0;
	while ((len = getline(line, MAXLEN)) > 0)
		if (nlines >= maxlines || (p = alloc(len)) == NULL)
			return -1;
		else {
			line[len-1] = '\0';	//delete newline
			strcpy(p, line);
			lineptr[nlines++] = p;
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

char *alloc(int n)	// return pointer to n characters.
{
	if (allocbuf + ALLOCSIZE - allocp >= n) {// it fits
		allocp += n;
		return allocp - n; //old p
	} else	//not enough room
	return 0;
}

int strncomp(char *s, char *t)
{
	while(*s++ == *t++){
		if (*s == 0)
			return 0;
	}
		return *--s - *--t;
}

