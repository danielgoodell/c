/* 	Write the function strend(s,t), which returns 1 if the string t
	occurs at the end of the string s, and zero otherwise.
*/
#include <stdio.h>

int strend(char *s, char *t)
{
	char *c = t;
	while(*s++)
		;
	while(*t++)
		;
	while(t!=c){
		if (*--s != *--t)
			return 0;
	}
	return 1;
}

int main(void)
{
	char s[40] = "First String!";
	char t[] = "ing!";
	
	printf("1: %s\n", s);
	printf("2: %s\n", t);
	
	printf("Does string 2 occur a the end of string 1?: %s\n", strend(s, t) ? "YES" : "NO");
	
}
