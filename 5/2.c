/*	getfloat, the floating point analog of getint. What type does 
	getfloat return as its value?
*/

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

#define BUFSIZE 100

int getch(void);
void ungetch(int);

char buf[BUFSIZE];	//buffer for ungetch
int bufp;		//next free position in buf

//getint: get the next integer from the input into *pn 
int getint(double *pn)
{
	int c;
	char s[100];
	int i = 0;
	
	while (isspace(c = getch()))	//skip whitespace
		;
	if (!isdigit(c) && c != EOF && c != '+' && c != '-' && c != '.'){
		ungetch(c);	//it's not a number
		return 0;
	}		
	if (c == '+' || c == '-'){
		s[i++] = c;
		if (c=getch(), isdigit(c) || c == '.'){
			ungetch(s[--i]);
			return 0;
		}
	}
	ungetch(c);		
	while (c=getch(), isdigit(c) || c == '.')
		s[i++] = c;
	s[i] = '\0';
	*pn = atof(s);
	if (c != EOF)
		ungetch(c);
	return(c);
}

int main(void)
{	
	double *pn, n;
	int c;
	pn = &n;

	while((c = getint(pn)) != EOF)
		if (c > 0)
			printf("Float is %f\n", *pn);
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
