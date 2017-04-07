#include <stdio.h>

int any(char s1[], char s2[]);

int main(void){

	char s[] = "This is the string to find the first matching char in.";
	char t[] = "z";
	int i = any(s, t);

	
	printf("\nFinding the first matching char n this string: \"%s\"\n", s);
	printf("\nString with chars to match: \"%s\"\n", t);
	printf("\nThe index location of the first matching char: %d\n", i);

}


int any(char s1[], char s2[]){
	int i, j;

	for(i = 0; s1[i] != '\0'; i++){
		for (j = 0; s2[j] != '\0' ; j++){
			if(s1[i] == s2[j])
				return i;
		}
	}
	return -1;
}







