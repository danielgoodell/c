/* 	Add the -d "directory order"_ option, which makes comparisons only on letters numbers, 
	and blanks. make sure it works in conjunction with -f
	
	Had to make more dramatic modifications to strcomp to get this to work. Now, if directory=1
	strcomp skips all chars that are not a number, letter, or space when performing comparisons.
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define MAXLINES 5000	//max lines to be sorted.
#define MAXLEN 1000
#define ALLOCSIZE MAXLINES*MAXLEN
#define qsort qsort2	//override the qsort that's in stdlib

char *lineptr[MAXLINES];
static char allocbuf[ALLOCSIZE];	// storage for alloc
static char *allocp = allocbuf;		//next free position
char reverse = 0;			//1 if reverse sorted.
char fold = 0;				//treat upper and lower case the same.
char directory = 0;			//directory order

int readlines(char *lineptr[], int nlines);
void writelines(char *lineptr[], int nlines);
int getline(char s[], int lim);
char *alloc(int);
void qsort(void *lineptr[], int left, int right, int (*comp)(void *, void *));
int numcmp( char *, char *);
int strcomp( char *s, char *t);

// sort input lines

int main(int argc, char *argv[])
{
	int nlines;		// number of input lines read
	int numeric = 0;	// 1 if numeric sorted
	
	if (argc > 1 ){
		for (int i = 1; i < argc; i++){
			if (strcomp(argv[i], "-n") == 0)
				numeric = 1; 
			else if (strcomp(argv[i], "-f") == 0)
				fold = 1;
			else if (strcomp(argv[i], "-r") == 0)
				reverse = 1;
			else if (strcomp(argv[i], "-d") == 0)
				directory = 1;

		}
	}	
	
	
	if ((nlines = readlines(lineptr, MAXLINES)) >= 0) {
		qsort((void **)lineptr, 0, nlines-1, (int (*)(void*,void*))(numeric ? numcmp : strcomp));
		writelines(lineptr, nlines);
		return 0;
	} else { 
		printf("input too big to sort\n");
		return 1;
	}
}

//qsort: sort v[left]..v[right] into increasing order
void qsort(void *v[], int left, int right, int (*comp)(void*,void*))
{
	int i, last;
	void swap(void *v[], int, int);
	
	if (left >= right) //do nothing if the array contains fewer than two elements
		return;
	swap(v, left, (left+right)/2);
	last = left;
	for (i = left+1; i<= right; i++)
		if ((*comp)(v[i], v[left]) < 0)
			swap(v, ++last, i);
	swap(v, left, last);
	qsort(v, left, last-1, comp);
	qsort(v, last+1, right, comp);
}

//numcmp: compare s1 and s2 numerically
int numcmp(char *s1, char *s2)
{
	double v1, v2;
	int rv;
	
	v1 = atof(s1);
	v2 = atof(s2);
	if (v1 < v2)
		rv = -1;
	else if (v1 > v2)
		rv =  1;
	else
		rv = 0;
	return reverse ? -rv : rv;
}

void swap(void *v[], int i, int j)
{
	void *temp;
	temp = v[i];
	v[i] = v[j];
	v[j] = temp;
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

char *alloc(int n)	// return pointer to n characters.
{
	if (allocbuf + ALLOCSIZE - allocp >= n) {// it fits
		allocp += n;
		return allocp - n; //old p
	} else	//not enough room
	return 0;
}

int strcomp(char *s, char *t)
{	
	char u;
	char v;
	
	do{	
		if(directory){
			while(!isalnum(*s) && *s != ' ' && *s != 0)
				s++;
			while(!isalnum(*t) && *t != ' ' && *t != 0)
				t++;
		}
		
		if (*s == 0 && *t == 0)
			return 0;
			
		u = fold ? toupper(*s++) : *s++;
		v = fold ? toupper(*t++) : *t++;
			
	} while(u == v);
	
	return reverse ? v - u : u - v;
		
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
	
