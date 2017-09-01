/*	5-18: Make dcl recover from input errors.

	I am not really sure I understand this question. I assume 'recover' means to still print an
	out put even with input errors. There's no way it can it right in all cases because you sort
	of need most things.
	
	Added
	Recovers from a missing parentheses. (doesn't always give the right answer because of ambiguity. but it RECOVERS.
	Recovers from a missing bracket.
*/

#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define	MAXTOKEN 100
#define BUFSIZE 100

enum {NAME, PARENS, BRACKETS};

void dcl(void);
void dirdcl(void);
void ungetch(int);
int getch();

int gettoken(void);
int tokentype;		// type of last token
char token[MAXTOKEN];	// last token string
char name[MAXTOKEN];	// identifier name
char datatype[MAXTOKEN];// datatype = char, int, etc.
char out[1000];		// output string
char err = 0;		// 1 if error is found.
char fix;		// token necessary to fix input

char buf[BUFSIZE];	//buffer for ungetch
int bufp;		//next free position in buf

int main() //convert declaration to words.
{
	while (gettoken() != EOF) {
		strcpy(datatype, token);
		out[0] = '\0';
		dcl();	// parse the rest of the line.
		if (tokentype != '\n')
			printf("syntax error\n");
		printf("%s: %s %s\n", name, out, datatype);
	}
	return 0;
}

//dcl: parse a declarator
void dcl(void)
{
	int ns;
	
	for (ns = 0; gettoken() == '*';)	//count *'s
		ns++;
	dirdcl();
	while (ns-- > 0)
		strcat(out, " pointer to");
}

//dirdcl: parse a direct declarator
void dirdcl(void)
{
	int type;
	
	if (tokentype == '(') {	//dcl
		dcl();
		if (tokentype != ')'){
			printf("error: missing )\n");
			err = 1;
			fix = ')';
		}
	} 
	else if (tokentype == NAME)	//variable name
		strcpy(name, token);
	else
		printf("error: expected name or (dcl)\n");
	while ((type = gettoken()) == PARENS || type == BRACKETS){
		if (type == PARENS)
			strcat(out, " function returning");
		else {
			strcat(out, " array");
			strcat(out, token);
			strcat(out, " of");
		}
	}
}

int gettoken(void)	//return next token
{
	int c, getch(void);
	void ungetch(int);
	char *p = token;
	
	if(err == 1){
		err = 0;
		return tokentype = fix;
	}	
	while ((c = getch()) == ' ' || c == '\t')
		;
	if (c == '(') {
		if ((c = getch()) == ')' || c == '\n') {
			strcpy(token, "()");
			if(c == '\n'){
				printf("error: missing )\n");
				ungetch(c);
				}
			return tokentype = PARENS;
		} else {
			ungetch(c);
			return tokentype = '(';
		}
	} else if (c == '[') {
		for (*p++ = c; (*p= getch()) != ']' && isdigit(*p); p++)
			;
		if (*p != ']')
			printf("missing ]\n");
		ungetch(*p);
		*p++ = ']';
		*p = '\0';
		return tokentype = BRACKETS;
	} else if (isalpha(c)) {
		for (*p++ = c; isalnum(c = getch()); )
			*p++ = c;
		*p = '\0';
		ungetch(c);
		return tokentype = NAME;
	} else
		return tokentype = c;
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
