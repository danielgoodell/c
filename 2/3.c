#include <stdio.h>
#include <string.h>
#include <math.h>

int htoi(char hex[]);

int main(void){

	char hex[] = "0x208";

	printf("\nHex string to convert is: %s\n", hex);
	
	printf("\nInteger value of the string after conversion is %d\n", htoi(hex));

	return 0;

}

int htoi(char hex[]){
	int i = 0;
	int j = 0;
	int length = strlen(hex)-1;
	int prefix = 0;
	printf("\nSTRLEN = %d\n", length);

	while (hex[i] != '\0'){
		if(hex[i] == '0' && prefix==0 && length > 0){
			i++;
			prefix = 1;
			if (hex[i] == 'x' || hex[i] == 'X'){
				i++;
			}
		}
		if		('0' <= hex[i] && hex[i] <= '9')
			j = j * 16 +(hex[i] - '0');
		else if ('a' <= hex[i] && hex[i] <= 'f')
			j = j * 16 + (hex[i] - 'a' + 10);
		else if ('A' <= hex[i] && hex[i] <= 'F')
			j = j * 16 + (hex[i] - 'A' + 10);
		else{
			printf("\nHex to integer conversion failed, non valid character detected\n");
			return 0;}
		i++;
	}
	return j;
}
			


