#include <stdio.h>

void squeeze(char s[], const char t[]);

int main(void){

	
	char s[] = "This is the string characters are going to be removed from";
	const char t[] = "set";

	
	printf("\nChars being removed from the below string: \"%s\"\n", t);
	printf("\nString to remove chars from: \t\"%s\"\n", s);
	squeeze(s, t);

	printf("\nResulting string: \t\t\"%s\"\n", s);
}

void squeeze(char s[], const char t[]){
	int i, j, k;
	for(i = j = 0; s[i] != '\0'; i++){
		for (k = 0; t[k] != '\0'; k++){
			if(s[i] == t[k])
				i++;
		}
		s[j++] = s[i];
	}
	s[j] = '\0';
}
		
	
