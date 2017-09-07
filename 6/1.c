/*	6-1: our version of getword does not properly handle underscores, string constants, 
	comments, or preprocessor control lines. Write a better version. 
	
	>This problem doesn't have much to do with structures. I did it anyway, though.
	
	>Adding support for underscores is easy, where we normally chkec for letters we must also 
	include underscores.
	>String literal: ignore everything after a " until we get to another " without a \ in front 
	of it.
	>Comments are easy, ignore everything after // until we get to a /n. Also ignore everything
	after a '/ *' until we get to a '* /'
	> Preprocessor directives are easy, ignore everything after a # until we get to a newline.
	
	I found it easiest to return nothing when get a comment, preprocessor directive or 
	character string and let loop call getword again to get the next word.

*/

#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAXWORD 100
#define NKEYS (sizeof keytab / sizeof keytab[0])
#define BUFSIZE  1000

char buf[BUFSIZE];	//buffer for ungetch
int bufp = 0;		//next free position in buf

 
char *keytab[] = {"auto", "double", "int", "struct", "break", "else", "long", "switch", "case", 
		"enum", "register", "typedef", "char", "extern", "return", "union", "const", 
		"float", "short", "unsigned", "continue", "for", "signed", "void", "default", 
		"goto", "sizeof", "volatile", "do", "if", "static", "while"};

int getword(char *, int);
int binsearch(char *, struct key *, int);

//Count C keywords
int main(void)
{
	int n;
	char word[MAXWORD];
	
	while(getword(word, MAXWORD) != EOF){
		if isalpha(word[0]){
			if ((n = binsearch(word, keytab, NKEYS)) >= 0)
				keytab[n].count++;
			}
	}
	for  (n = 0; n < NKEYS; n++)
		if (keytab[n].count > 0)
			printf("%4d %s\n", keytab[n].count, keytab[n].word);
	return 0;
}

//binsearch, find word in tab[0]...tab[n-1]
int binsearch(char * word, struct key tab[], int n)
{
	int cond;
	int low, high, mid;
	low = 0;
	high = n-1;
	
	while ( low <= high) {
		mid = (low+high) / 2;
		if ((cond = strcmp(word, tab[mid].word)) < 0)
			high = mid - 1;
		else if (cond > 0)
			low = mid+1;
		else 
			return mid;
	}
	return -1;
}

//getword: get next word or character from input
int getword(char * word, int lim)
{	
	int c, getch(void);
	void ungetch(int);
	char *w = word;
	
	w[0] = '\0';	//clear out word so we don't get repeated words after finding string comment, etc.
	while (isspace(c = getch()))
		;		
	if (c == '/'){
		if ((c = getch()) == '/'){
			while((c = getchar())!='\n')
				;
			return 0;
		}
		else if (c == '*'){
			while ((c = getchar()))
				if (c == '*')
					if ((c = getchar()) == '/')
						return 0;
		}
		else{
			*w++ = '/';
			*w = '\0';
			return '/';
		}
	}	
	else if (c == '\"'){
		while ((c = getchar())){
			if (c == '\\')
				getchar();
			else if (c == '\"')
				return 0;
		}
	}
	else if (c == '\''){
		while ((c = getchar())){
			if (c == '\\')
				getchar();
			else if (c == '\'')
				return 0;
		}
	}
	else if (c == '#'){
		while ((c = getchar()) != '\n')
			;
		return 0;
	}	
	else if (c != EOF)
		*w++ = c;
					
	if (!isalpha(c) && c != '_') {	//underscore support
		*w = '\0';
		return c;
	}
	
	for ( ; --lim > 0; w++){
		if (!isalnum(*w = getch()) && *w != '_') {  //underscore support
			ungetch(*w);
			break;
		}
	}
	*w = '\0';
	
	return word[0];
}
	
int getch(void)
{
	return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c) // push character back to input
{
	if (bufp >= BUFSIZE)
		printf("ungetch: too many characters\n");
	else
		buf[bufp++] = c;
}
