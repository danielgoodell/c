
//1.	this line has to be longer than 80 charsthis line has to be longer than 80 charsthis line has to be longer than 80 charsthis line has to be longer than 80 charsthis line has to be longer than 80 charsthis line has to be longer than 80 charsthis line has to be longer than 80 chars

#include <stdio.h>
#define MAXLINE 1000 /* maximum input line size*/

int getline(char line[], int maxline);
void copy(char t[], char from[]);

/* print the longest input line */
int main(void)
{
	int len;			/* current line length */
	char line[MAXLINE];

	while ((len = getline(line, MAXLINE)) > 0)
		if (len > 79) {
			printf("%s\n", line);
		}		
	
	return 0;
}

/* getline: read a line into s, return length */
int getline(char s[], int lim)
{
	int c, i;

	for (i=0; (c=getchar())!=EOF && c!='\n'; ++i){
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

/* copy: copy 'from' into 'to'; assume to is big enough */
void copy(char to[], char from[])
{
	int i;

	i = 0;	
	while((to[i] = from[i]) != '\0')
		++i;
}
//2.	this line has to be longer than 80 charsthis line has to be longer than 80 charsthis line has to be longer than 80 charsthis line has to be longer than 80 charsthis line has to be longer than 80 charsthis line has to be longer than 80 charsthis line has to be longer than 80 chars

