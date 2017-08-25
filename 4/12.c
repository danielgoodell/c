/* 	Adapt the ideas of printd to write a recursive version of itoa; 
	this is, convert an integer into a string by calling a recursive routine.
*/
#include <stdio.h>

void itoa(char s[], int n);

int main(void){
	char s[20];
	int n = -123456;
	
	itoa(s, n);
	printf("%s\n", s);
	
	return 0;
}

void itoa(char s[], int n)
{
	static int i = 0;
	
	if (n < 0){
		s[i++] = '-';
	 	n = -n;
	 }
	 
	 if (n/10){
	 	itoa(s, n/10);
	  }
	s[i++] = (n % 10 + '0');
	s[i] = '\0';
	 	 
}

