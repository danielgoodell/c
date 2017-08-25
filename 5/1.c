/* 	As written, getint treats a + or - not followed by a digit as a valid 
	representation of zero. Fix it to push such a character back on the input.
*/

#include <ctype.h>
#include <stdio.h>

#define BUFSIZE 100

int getch(void);
void ungetch(int);

char buf[BUFSIZE];	//buffer for ungetch
int bufp;		//next free position in buf

//getint: get the next integer from the input into *pn 
int getint(int *pn)
{
	int c, sign;
	
	while (isspace(c = getch()))	//skip whitespace
		;
	if (!isdigit(c) && c != EOF && c != '+' && c != '-'){
		ungetch(c);	//it's not a number
		return 0;
	}
	sign = (c == '-') ? -1 : 1;
	if (c == '+' || c == '-'){
		c = getch();
		if (!isdigit(c)){
			ungetch((sign > 0) ? '+' : '-');
			return 0;
		}
	}
	for (*pn = 0; isdigit(c); c = getch())
		*pn = 10 * *pn + (c - '0');
	*pn *= sign;
	if (c != EOF)
		ungetch(c);
	return(c);
}

int main(void)
{
	
	int *pn, n;
	int c;
	pn = &n;

	while((c = getint(pn)) != EOF)
		if (c > 0)
			printf("integer is %i\n", *pn);
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
