#include <stdio.h>
#define MAXLINE 1000 /* maximum input line size*/

int getline(char line[], int maxline);
void cleanline(char line[], int len);

/* print the longest input line */
int main(void)
{
	int len;			/* current line length */
	char line[MAXLINE];

	while ((len = getline(line, MAXLINE)) > 0)
	{
		cleanline(line, len);
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
/*cleanline: removes trailing spaces/tabs for each line and deletes any completely blank lines*/
void cleanline(char line[], int len)
{
	for (; (line[len] == '\t' || line[len] == ' ' || line[len] == '\n' || line[len] == '\0') && len > 0; len--);
	if(len > 0 && line[len] != '\n'){
		len++;
		line[len] = '\n';
	}
	len++;
	line[len] = '\0';
}

