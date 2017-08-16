#include <stdio.h>
#define MAXLINE 1000 /*maximum input line length*/

int getline(char line[], int max);
int strindex(char source[], char searchfor[]);

char pattern[] = "ould"; //pattern to search for

//find all lines matching pattern
int main()
{
	char line[MAXLINE];
	int found = 0;
	int position = 0;
	
	while (getline(line, MAXLINE)>0)
		if ((position=strindex(line, pattern)) >= 0) {
			printf("%s", line);
			for(int i = position; i>0;i--)
				printf(" ");
			printf("^Position = %d\n", position);
			found++;
		}
	return found;
}

// getline: get line into s, return length
int getline(char s[], int lim)
{
	int c, i;

	i = 0;
	c = 0;
	while (--lim> 0 && (c=getchar()) != EOF && c != '\n')
		s[i++] = c;
	if (c == '\n')
		s[i++] = c;
	s[i] = '\0';
	return i;
}

//strindex: return index of t in s, -1 if none
int strindex(char s[], char t[])
{
	int i, j, k;
	int slen, tlen;
	
	for (i=0; s[i] != '\0'; i++); // Count how long s is
	slen=--i;
	for (i=0; t[i] != '\0'; i++); // Count how long t is
	tlen=--i;
	
	for (i=slen; i>0; i--){
		for(j=i, k=tlen; k>=0 && s[j]==t[k]; j--, k--)
			;
		if (k<=0)
			return i-tlen;
	}
	return -1;
}
