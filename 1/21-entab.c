#include <stdio.h>
#define MAXLINE 1000 /* maximum input line size*/

void convertline(char line[], int len);
int getline(char s[], int lim);
void copy(char to[], char from[]);

int main(void)
{
	int len; /* Current Line Length */
	char line[MAXLINE];

	while ((len = getline(line, MAXLINE)) > 0)
	{
		convertline(line[], len);
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
void convertline(char line[], int len)
{
	char buffer[len];
	int tabspace=4;    /* Width of tab stops */
	int spacelength=0; /*Accumulated spaces in current chunk of whitespace*/
	int spacechars=0;  /*Number of chars */
	int i = 0; /* Index for line */
	int j = 0  /* Index for the buffer */

	while((line[i] != '\0'; ){

		if (line[i] != '\t' && line[i] != ' ' && spacelength == 0)
			buffer[j] = line[i];
		else if (spacelength > 0){
			j=i-spacechars
			while(spacelength > 0){
				if(spacechars >= tabspace)
				 printf
			}
		else if (line[i] == '\t' || line[i] == ' ' && spacelength == 0)
	
		}
	i++
	j++
	}
	copy(line, buffer);
}

/* copy: copy 'from' into 'to'; assume to is big enough */
void copy(char to[], char from[])
{
	int i;
	i = 0;	
	while((to[i] = from[i]) != '\0')
		++i;
}

