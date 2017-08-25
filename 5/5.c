/* 	Write versions of the library functions strncpy, strncat, and strncmp
	which operates on at most the first n characeters of their argument strings.
*/
#include <stdio.h>

void strncpy(char *s, char *t, int n)
{
	while((*s++ = *t++) && n--)
		;
}

void strncat(char *s, char *t, int n)
{
	while(*s++)
		;
	s--; // decrement s so that we overwrite the first \0
	while((*s++ = *t++) && n--)
		;
}

int strncmp(char *s, char *t, int n)
{
	while(n--, *s++ == *t++){
		if (n == 0 || *s == 0)
			return 0;
	}
		return *--s - *--t;
}

int main(void)
{
	char s[40] = "First String!";
	char t[] = "ing!";
	int n = 3;
	
	printf("1: %s\n", s);
	printf("2: %s\n", t);
	
	strncpy(s, t, n);
	
	printf("First %i chars of t copied to s = %s\n\n", n, s);
	
	strncat(s, t, n);
	
	printf("Now, the first %i chars of t added to the end of s = %s\n\n", n, s);
	
	
	char p[] = "124567";
	char q[] = "123";
	int c;
	n = 3;
	
	if ((c = strncmp(p, q, n)) == 0)
		c = '=';
	else if (c < 0)
		c = '<';
	else if (c > 0)
		c = '>';
	
	printf("1: %s\n", p);
	printf("2: %s\n", q);
		
	printf("1 %c 2 (first %i chars only)\n", c, n);
	

}	


