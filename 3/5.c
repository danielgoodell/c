#include <stdio.h>
#include <string.h>

/* itob: convert n to characters in s -- Handles -(2^(wordsize-1)) correctly now. */

void reverse(char s[]);
void itoa(int n, char[], int b);

void itoa(int n, char s[], int b){
	unsigned int m;
	int i, sign;

	if ((sign = n) < 0) //record sign
		m = -n;
	else
		m = n;
	i = 0;
	do{		// generate digits
			if(m % b <= 9)
				s[i++] = m % b + '0';
			else if (m % b > 9)
				s[i++] = m % b + 'a';
	} while ((m /= b) > 0);
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

	int i = -100;
	char s[20];
	int b = 2;

	itoa(i, s, b);

	printf("\nOriginal number = %i\n", i);
	
	printf("Converted to base %d Ascii text = %s\n", b, s);

	return 0;
}
	
	
	
