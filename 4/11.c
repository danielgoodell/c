/* 	Modify getop so that it doesn't need to use ungetch. Hint: use 
	an internal static variable.
*/  

#include <stdio.h>
#include <stdlib.h>	//for atof()
#include <ctype.h>
#include <string.h>	// for strcmp
#include <math.h>

#define MAXOP	100	//max size of operand or operator
#define	NUMBER	'0'	//signal that a number was found
#define MAXVAL 	100 	// maximum depth of the stack
#define BUFSIZE	100
#define MATH	'1'
#define VAR	'2'

int getch(void);
int getop(char []);
void push(double);
double pop(void);
void print_top(void);		//added function to print the current stack value without popping it
void clear_stack(void);		//added function to clear the stack
void handle_math(char []);
void update_var(void);
void use_vars(void);


int sp = 0; //next free stack position
double val[MAXVAL];
char buf[BUFSIZE];	//buffer for ungetch
int bufp = 0;		//next free position in buf
double var[28]	;	//array to hold variable values
int var_last[2] = {27,27};	// holds the last two variables entered.
int spv = 27;			//variable pointer.
double last_val = 0.0;


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
		case MATH:			// added to handle math library functions
			use_vars();
			handle_math(s);
			break;
		case VAR:			//set the var pointer to the correct variable
			spv = s[0] - 'A';
			update_var();
			break;
		case '!':
			push(last_val);
			break;			
		case '=':
			var[spv] = pop();
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
			use_vars();
			push(pop() + pop());
			break;
		case '*':
			use_vars();
			push(pop() * pop());
			break;
		case '-':
			use_vars();
			op2 = pop();
			push(pop() - op2);
			break;
		case '/':
			use_vars();
			op2 = pop();
			if (op2 != 0.0)
				push(pop() / op2);
			else
				printf("error: zero divisor");
			break;
		case '%':				// added modulus operator
			use_vars();				
			op2 = pop();
			if (op2 != 0.0)
				push((int)pop() % (int)op2); 
			else
				printf("error: zero divisor");
			break;				
		case '\n':
			if (spv != 27){
				printf("\t%c=%.8g\n", (spv+'A'), var[spv]);
				last_val = var[spv];
				spv = 27;
				var_last[0] = 27;
				var_last[1] = 27;
			}
			else{
				last_val = pop();
				printf("\t%.8g\n", last_val);
			}
			break;
		default:
			printf("error: unknown command: %c %s\n", type, s);
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
	static char d;
	i = 0;
	c = ' ' ;
	
	if(d != 0)
		c = d;
	
	while(c == ' ' || c == '\t')
		s[0] = c = getchar();
		
	s[1] = '\0';
	
	if (isalpha(c)){
		while(isalpha(s[++i] = c = getch()))
			;
		s[i] = '\0';
		d = c;
		if (strlen(s) == 1){
			s[0] = toupper(s[0]);
			return VAR;
		}
		else		
			return MATH;
	}
	if (!isdigit(c) && c != '.' && c != '-'){		//added exception for the negative sign
		d = 0;
		return c; //not a number or letter
	}
	if (c == '-'){
		if (!isdigit(c = getch())){
			d = 0;
			return '-';
		}
		else {
			s[++i] = '-';
			while(isdigit(s[++i] = c = getch()))
			;
		}
	}
	else if (isdigit(c))	//collect integer part	//added - negative sign this is copied over to the final string like a digit
		while(isdigit(s[++i] = c = getch()))
			;
	if (c == '.')	//collect fraction part
		while(isdigit(s[++i] = c = getch()))
			;
	s[i] = '\0';
	d = 0;
	return NUMBER;
}

int getch(void)
{
	return getchar();
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

void handle_math(char s[])
{
//handle the math here.
	double op2;
	if ( strcmp(s, "sin") == 0 || strcmp(s, "SIN") == 0)
		push(sin(pop()));
	else if ( strcmp(s, "exp") == 0 || strcmp(s, "EXP") == 0)
		push(exp(pop()));
	else if ( strcmp(s, "pow") == 0 || strcmp(s, "POW") == 0){
		op2 = pop();
		push(pow(pop(), op2));
	}
	else
		printf("Unknown operator : \"%s\"\n", s);
}
void update_var(){
	var_last[0] = var_last[1];
	var_last[1] = spv;
	
}
void use_vars(void){
	if(var_last[0]!=27)
		push(var[var_last[0]]);
	if(var_last[1] != 27)
		push(var[var_last[1]]);
	var_last[0] = 27;
	var_last[1] = 27;
	spv = 27;
}


