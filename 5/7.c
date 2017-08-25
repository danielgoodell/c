/*	Rewrite readlines to store lines in an array supplied by main rather 
	than calling alloc to maintain storage. How much faster is the program?
*/

#include <stdio.h>
#include <string.h>

#define MAXLINES 5000	//max # of lines to be sorted.

char * lineptr[MAXLINES]

int readlines(char * lineptr[], int nlines);
void writelines(char *lineptr[], int nlines);

void qsort(char *lineptr[], int left, int right);

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

#define MAXLEN 1000	//max length of any input line
int getline(char *, int);
char *alloc(int);

//readlines : read input lines
int readlines(char *lineptr[], int maxlines)
P
	int len, nlines
