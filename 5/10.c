/* 	Write the program expr, which evaluates a reverse Polish expresson from the command line, 
	where each operator or operand is a separate argument.
		
	I will use problem 4-3 as the basis for this function. I chose that because it has most 
	of the commonarithmatic operators and non of the extra stuff like variables.
	Also, the version that uses getline (4-10) would be more difficult to use because the 
	arguments would have to combined together into a single string first.
*/  

#include <stdio.h>
#include <stdlib.h>	//for atof()
#include <ctype.h>

#define MAXOP	100	//max size of operand or operator
#define	NUMBER	'0'	//signal that a number was found
#define MAXVAL 	100 	// maximum depth of the stack
#define BUFSIZE	100

int getch(void);
void ungetch(int);
int getop(char [], char *arg[]);
void push(double);
double pop(void);

int sp = 0; //next free stack position
double val[MAXVAL];
char buf[BUFSIZE];	//buffer for ungetch
int bufp = 0;		//next free position in buf

/*reverse Polish calculator */
int main(int argc, char *argv[])
{
	int type;
	double op2;
	char s[MAXOP];
	
	if (argc < 2){
		printf("Reverse polish notation calculator.\nUsage example: 10 2 2 x 10 +\nNote, use x instead of * for multiplication\n");
		return 0;
	}
	
	while (--argc > 0){
		type = getop(s, ++argv);
		switch (type) {
		case NUMBER:
			push(atof(s));
			break;
		case '+':
			push(pop() + pop());
			break;
		case 'x':
			push(pop() * pop());
			break;
		case '-':
			op2 = pop();
			push(pop() - op2);
			break;
		case '/':
			op2 = pop();
			if (op2 != 0.0)
				push(pop() / op2);
			else
				printf("error: zero divisor");
			break;
		case '%':				// added modulus operator
			op2 = pop();
			if (op2 != 0.0)
				push((int)pop() % (int)op2); 
			else
				printf("error: zero divisor");
			break;				

		default:
			printf("error: unknown command %s\n", s);
			break;
		}
	}
	printf("\t%.8g\n", pop());
	return 0;
}

//push: push f onto the value stack
void push(double f)
{
	if (sp < MAXVAL)
		val[sp++] = f;
	else
		printf("error: stack full, can't push %g\n", f);
}

//pop: pop and return top value from stack
double pop(void)
{
	if (sp > 0)
		return val[--sp];
	else {
		printf("error: stack empty\n");
		return 0.0;
	}
}

//getop: get next operator or numeric operand

int getop(char s[], char *arg[])
{

	int i, c, j = 0;
	
	while ((s[0] = c = (*arg)[j++]) == ' ' || c == '\t')
		;
	s[1] = '\0';
	i = 0;
	if (!isdigit(c) && c != '.' && c != '-')		//added exception for the negative sign
		return c; //not a number or letter

	if (c == '-'){
		if (!isdigit(c = (*arg)[j++])){
			return '-';
		}
		else {
			s[++i] = '-';
			while(isdigit(s[++i] = c = (*arg)[j++]))
			;
		}
	}
	else if (isdigit(c))	//collect integer part	//added - negative sign this is copied over to the final string like a digit
		while(isdigit(s[++i] = c = (*arg)[j++]))
			;
	if (c == '.')	//collect fraction part
		while(isdigit(s[++i] = c = (*arg)[j++]))
			;
	s[i] = '\0';
	return NUMBER;
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

	
