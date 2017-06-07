// The chapter 3 itoa doesn't display the larget negative number because the largest negative number is one 
//larger than the largest positive number. When we take a large negative number we make it positive 
//before performing the calculation and then we add the negative sign back at the end. This number cannot be stored as a positive. 
//A way to fix this would be to store it in a different unsigned integer and then it will have plenty of space.

/* itoa: convert n to characters in s -- Handles -(2^(wordsize-1)) correctly now. */
#include <stdio.h>
#include <string.h>

void reverse(char s[]);
void itoa(int n, char[]);

void itoa(int n, char s[]){
	unsigned int m;
	int i, sign;

	if ((sign = n) < 0) //record sign
		m = -n;
	else
		m = n;
	i = 0;
	do{		// generate digits
		s[i++] = m % 10 + '0'; // get next digit
	} while ((m /= 10) > 0);  //delete itoa
	if (sign < 0)
		s[i++] = '-';
	s[i] = '\0';
	reverse(s);
}

/*reverse: reverse a string of length len*/
void reverse(char s[])
{
	int c, i, j;
	
	for(i=0, j = (strlen(s)-1); i < j; i++, j--) {
		c = s[i];
		s[i] = s[j];
		s[j] = c;
	}	
}

int main(void){

	int i = -2147483648;
	char s[20];

	itoa(i, s);

	printf("\nOriginal number = %i\n", i);
	
	printf("Converted to Ascii text = %s\n", s);

	return 0;
}
	
	
	
