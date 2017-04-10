#include <stdio.h>
#define length 100

void escape(char s[], char t[]);
void reverse_escape(char s[], char z[]);

int main(void){

char s[length] = "This is a \t\t bunch of crap \n\n ";
char t[length] = "";
char z[length] = "";

printf("\nOriginal string: \n\"%s\"", s);
escape(s, t);
printf("\nNew string after performing escape: \n\"%s\"\n", t);
reverse_escape(t, z);
printf("\nNew string after performing reverse_escape: \n\"%s\"\n", z);


}

void escape(char s[], char t[]){

	int i = 0;
	int j = 0;

	while(s[i] != '\0'){
		switch (s[i]) {
			case '\t':
				t[j++] = '\\';
				t[j++] = 't';
				i++;	
				break;	
			case '\n':
				t[j++] = '\\';
				t[j++] = 'n';
				i++;	
				break;
			default:
				t[j++] = s[i++];
				break;
		}
	}
	s[j] = '\0'; 
}

void reverse_escape(char s[], char z[]){

	int i = 0;
	int j = 0;

	while(s[i] != '\0'){
		//printf(" j = %d, i = %d \n", j, i);
		if(s[i] == '\\'){	
			switch (s[++i]) {
				case 't':
					z[j++] = '\t';
					i++;	
					break;	
				case 'n':
					z[j++] = '\n';
					i++;	
					break;
				default:
					z[j++] = '\\';
					i++;
					break;
			}
		}
		else
			z[j++] = s[i++];
	}
	z[j] = '\0'; 
}
