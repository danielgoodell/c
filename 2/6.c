#include <stdio.h>

int setbits(unsigned int x, int p, int n, unsigned int y);

int main(void){

unsigned char x = 0xF0;
unsigned char y = 0x04;
int n = 3;
int p = 7;

printf("\n x = %x\n", x);
printf("\n y = %x\n", y);
printf("\n n = %d\n", n);
printf("\n p = %d\n", p);

printf("\n Result of setbits = %x\n", setbits(x, p, n, y));

}

int setbits(unsigned int x, int p, int n, unsigned int y){
	
return ((x & ~(~(~0 << n) << (p-n+1))) | ((y & ~(~0 << n)) << (p-n+1)));

}

