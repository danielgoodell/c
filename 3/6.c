#include <stdio.h>
#include <string.h>



void reverse(char s[]);
void itoa(int n, char[], int w);

/* itoa: convert n to characters in s -- Handles -(2^(wordsize-1)) correctly now. */
void itoa(int n, char s[], int w){
	unsigned int m;
	int i, sign;

	if ((sign = n) < 0) //record sign
		m = -n;
	else
		m = n;
	i = 0;
	do{		// generate digits
		s[i++] = m % 10 + '0'; // get next digit
		w--;
	} while ((m /= 10) > 0);  //delete itoa
	if (sign < 0){
		s[i++] = '-';
		w--;
	}
	while(w>0){
		s[i++] =  ' ';
		w--;
	}
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
	int w = 10;

	itoa(i, s, w);

	printf("\nOriginal number = %i\n", i);
	
	printf("Converted to Ascii text (min field width %d) =\"%s\"\n", w, s);

	return 0;
}
