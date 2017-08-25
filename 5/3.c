/* 	Write a pointer version of the function strcat that we showed in Chapter 2: strcat(s, t) 
	copies the string t to the end of s.
*/
#include <stdio.h>

void strcat(char *s, char *t)
{
	while(*s++)
		;
	s--; // decrement s so that we overwrite the first \0
	while((*s++ = *t++))
		;
}

int main(void)
{
	char s[40] = "First String!";
	char t[] = "Second string!";
	
	printf("%s\n", s);
	printf("%s\n", t);
	
	printf("Combined strings:\n");
	
	strcat(s, t);
	
	printf("%s\n", s);
}
