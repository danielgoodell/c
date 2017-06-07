#include <stdio.h>

int print_expansion(int i, int j, char s1[], char s2[]);
void expand(char s1[], char s2[]);

void expand(char s1[], char s2[]){
	int i = 0;
	int j = 0;

	for(i = 0; s1[i+2]!='\0'; i++){
		if((s1[i] >= 'a' && s1[i] <= 'z') && s1[i+1] == '-' && (s1[i+2] >= 'a' && s1[i+2] <= 'z')){
			j = print_expansion(i, j, s1, s2);
			i=i+2;
		}
		else if((s1[i] >= 'A' && s1[i] <= 'Z') && s1[i+1] == '-' && (s1[i+2] >= 'A' && s1[i+2] <= 'Z')){
			j = print_expansion(i, j, s1, s2);
			i=i+2;
		}
		else if((s1[i] >= '0' && s1[i] <= '9') && s1[i+1] == '-' && (s1[i+2] >= '0' && s1[i+2] <= '9')){
			j = print_expansion(i, j, s1, s2);
			i=i+2;
		}
		else	{	
			s2[j] = s1[i];	
			j++;
		}
	}			
}

int print_expansion(int i, int j, char s1[], char s2[]){
	for(int k = 0; k <= (s1[i+2]-s1[i]); k++)
		s2[j++] = s1[i]+k;
	return j;
}

int main(void){
	char s1[] = "-a-ka-n 1-9  -A-Z";
	char s2[1000];
	
	expand(s1, s2);
	
	printf("\nOriginal string: \"%s\"", s1);
	printf("\nExpanded string: \"%s\"\n", s2);
}

