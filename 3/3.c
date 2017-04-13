#include <stdio.h>

void expand(char s1[], char s2[]);
char nextchar(char buffer[3], char c);

int main(void){
	char s1[] = "a-ka-l  1-9";
	char s2[1000];
	
	expand(s1, s2);
	
	printf("\nOriginal string: \"%s\"", s1);
	printf("\nExpanded string: \"%s\"\n", s2);
}

void expand(char s1[], char s2[]){
	char buffer[3];
	int i = 0;
	int j = 0;
	char d = 0;
	
	buffer[0] = s1[i++], buffer[1] = s1[i++], buffer[2] = s1[i++];

	do{
		if(buffer[1] == '-'){

			if(buffer[0] >= 'a' && buffer[0] <= 'z' && buffer[2] >= 'a' && buffer[2] <= 'z' && buffer[2] > buffer[0]){
				if (d!='\0')
					s2[j++] = d;
				for(int k = 0;k<=buffer[2]-buffer[0]; j++, k++)
					s2[j] = buffer[0] + k;	
				if (d=nextchar(buffer, s1[i++]) == '\0')
					break;
				if (d=nextchar(buffer, s1[i++]) == '\0')
					break;
				if (d=nextchar(buffer, s1[i++]) == '\0')
					break;
			}				
			else if(buffer[0] >= 'A' && buffer[0] <= 'Z' && buffer[2] >= 'A' && buffer[2] <= 'Z' && buffer[2] > buffer[0]){
				for(int k = 0;k<=buffer[2]-buffer[0]; j++, k++)
					s2[j] = buffer[0] + k;
				if (d=nextchar(buffer, s1[i++]) == '\0')
					break;
				if (d=nextchar(buffer, s1[i++]) == '\0')
					break;
				if (d=nextchar(buffer, s1[i++]) == '\0')
					break;
			}	
			else if(buffer[0] >= '0' && buffer[0] <= '9' && buffer[2] >= '0' && buffer[2] <= '9' && buffer[2] > buffer[0]){
				for(int k = 0;k<=buffer[2]-buffer[0]; j++, k++)
					s2[j] = buffer[0] + k;	
				if (d=nextchar(buffer, s1[i++]) == '\0')
					break;
				if (d=nextchar(buffer, s1[i++]) == '\0')
					break;
				if (d=nextchar(buffer, s1[i++]) == '\0')
					break;
			}
			else if(buffer[0] >= 'a' && buffer[0] <= 'z' && buffer[2] >= 'a' && buffer[2] <= 'z' && buffer[2] < buffer[0]){
				for(int k = buffer[0]-buffer[2];k>=0; j++, k--)
					s2[j] = buffer[2] + k;	
				if (d=nextchar(buffer, s1[i++]) == '\0')
					break;
				if (d=nextchar(buffer, s1[i++]) == '\0')
					break;
				if (d=nextchar(buffer, s1[i++]) == '\0')
					break;
			}
			else if(buffer[0] >= 'A' && buffer[0] <= 'Z' && buffer[2] >= 'A' && buffer[2] <= 'Z' && buffer[2] < buffer[0]){
				for(int k = buffer[0]-buffer[2];k>=0; j++, k--)
					s2[j] = buffer[2] + k;	
				if (d=nextchar(buffer, s1[i++]) == '\0')
					break;
				if (d=nextchar(buffer, s1[i++]) == '\0')
					break;
				if (d=nextchar(buffer, s1[i++]) == '\0')
					break;
			}
			else if(buffer[0] >= '0' && buffer[0] <= '9' && buffer[2] >= '0' && buffer[2] <= '9'&& buffer[2] < buffer[0]){
				for(int k = buffer[0]-buffer[2];k>=0; j++, k--)
					s2[j] = buffer[2] + k;
				if (d=nextchar(buffer, s1[i++]) == '\0')
					break;
				if (d=nextchar(buffer, s1[i++]) == '\0')
					break;
				if (d=nextchar(buffer, s1[i++]) == '\0')
					break;
			}
			else 
				s2[++j] = nextchar(buffer, s1[i]);
			}
		else
			s2[j++] = d;
//	printf("\nbuffer = \"%c%c%c\"\n", buffer[0], buffer[1], buffer[2]);
	} while((d=nextchar(buffer, s1[i++])) != '\0');
//	printf("\nbuffer = \"%c%c%c\"\n", buffer[0], buffer[1], buffer[2]);
	s2[j++] = nextchar, s2[j++] = buffer[1], s2[j++] = buffer[2];
	s2[j] = '\0';

}

char nextchar(char buffer[3], char c, int n){
	char d = buffer[0];
	buffer[0] = buffer[1], buffer[1] = buffer[2], buffer[2] = c;
	if (c == '\0')
		return '\0';
	else{

		return d;
	}
}
/*int refill_buffer(char buffer[3], char s[], int i){
	
	for(int k = 0, k<3, k++){
		if (s[i] = '\0')
			break;
		buffer[0] = buffer[1], buffer[1] = buffer[2], buffer[2] = s[i++]*/
	
		


}

