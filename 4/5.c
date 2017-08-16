/* 	Add commands to print the top element of the stack without popping to duplicate it, 
*	and to swap the top two elements. Add a command to clear the stack.
*/  

#include <stdio.h>
#include <stdlib.h>	//for atof()
#include <ctype.h>

#define MAXOP	100	//max size of operand or operator
#define	NUMBER	'0'	//signal that a number was found
#define MAXVAL 	100 	// maximum depth of the stack
#define BUFSIZE	100
#define MATH	'1'

int getch(void);
void ungetch(int);
int getop(char []);
void push(double);
double pop(void);
void print_top(void);		//added function to print the current stack value without popping it
void clear_stack(void);		//added function to clear the stack
void handle_math(char []);

int sp = 0; //next free stack position
double val[MAXVAL];
char buf[BUFSIZE];	//buffer for ungetch
int bufp = 0;		//next free position in buf

/*reverse Polish calculator */
int main()
{
	int type;
	double op2, op3;
	char s[MAXOP];

	while ((type = getop(s)) != EOF) {
		switch (type) {
		case NUMBER:
			push(atof(s));
			break;
		case MATH:
			handle_math(s);
			break;
		case '^':			//added ^ command to clear the stack
			clear_stack();
			break;
		case '?':			//added ? command to print the current stack value without popping it
			print_top();
			getop(s);
			break;
		case '~':			//added ~ command to swap the top two elements on the stack.
			op2 = pop();
			op3 = pop();
			push(op2);
			push(op3);	
			break;		
		case '+':
			push(pop() + pop());
			break;
		case '*':
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
		case '\n':
			printf("\t%.8g\n", pop());
			break;
		default:
			printf("error: unknown command %s\n", s);
			break;
		}
	}
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
int getop(char s[])
{
	int i, c;
	
	while ((s[0] = c = getch()) == ' ' || c == '\t')
		;
	s[1] = '\0';
	if (!isalpha(c))
		while(isalpha(s[++i[ = c = getch()));
			;
		return
	if (!isdigit(c) && c != '.' && c != '-')		//added exception for the negative sign
		return c; //not a number
	i = 0;
	if (isdigit(c) || c == '-')	//collect integer part	//added - negative sign this is copied over to the final string like a digit
		while(isdigit(s[++i] = c = getch()))
			;
	if (c == '.')	//collect fraction part
		while(isdigit(s[++i] = c = getch()))
			;
	s[i] = '\0';
	if (c != EOF)
		ungetch(c);
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
void print_top()
{
	printf("\t%.8g\n", val[sp-1]);
}
void clear_stack()
{
	for( ; val[sp] > 0; val[sp--] = 0)
		;
}

void handle_math()
{
//handle the math here.
}

	
