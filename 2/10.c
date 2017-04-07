#include <stdio.h>

char lower(char c);

int main(void){

char s[] = "This is the STRING where UPPERCASE will be converted to lowercase.";

printf("String to make lowercase = \n %s \n", s);

for(int i = 0; s[i] != '\0'; i++)
	s[i] = lower(s[i]);

printf("String after making lowercase = \n %s \n", s);

}

char lower(char c){
	(c >= 'A' && c <= 'Z') ? (c += 'a'-'A') : c;
	return c;
}

	


