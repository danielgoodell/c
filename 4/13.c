/* Write a recursive version of the function reverse(s), which
	reverses the string s in place.
*/

#include <stdio.h>

void reverse(char s[]);

int main(void){
	
	char s[] = "string to reverse";
	char x[] = "second string to reverse";
	
	printf("%s\n", s);
	reverse(s);
	printf("%s\n", s);
	
	printf("%s\n", x);
	reverse(x);
	printf("%s\n", x);
}	

void reverse(char s[]){
	static int i, n;
		
	if (s[i] == '\0')
		n = i-1;
	else{	
		char c = s[i++];
		reverse(s);
		s[n - --i] = c;
	}
}
