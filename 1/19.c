#include <stdio.h>
#define MAXLINE 1000 /* maximum input line size*/

int getline(char line[], int maxline);
void reverseline(char line[], int len);
void copy(char to[], char from[]);

/* print the longest input line */
int main(void)
{
	int len;			/* current line length */
	char line[MAXLINE];

	while ((len = getline(line, MAXLINE)) > 0)
	{
		reverseline(line, len);
		printf("%s", line);
	}
	return 0;
}

/* getline: read a line into s, return length */
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
/*reverseline: reverse a string of length len*/
void reverseline(char line[], int len)
{
	char buffer[len];
	int  i = len-2;
	copy(buffer, line);

	for(; i>=0; i--)
		line[(len-2)-i] = buffer[i];

	line[len-1] = '\n';

}

/* copy: copy 'from' into 'to'; assume to is big enough */
void copy(char to[], char from[])
{
	int i;

	i = 0;	
	while((to[i] = from[i]) != '\0')
		++i;
}




