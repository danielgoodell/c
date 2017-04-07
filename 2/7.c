#include <stdio.h>

int invert(unsigned int x, int p, int n);

int main(void){

unsigned char x = 0xF0;
int n = 3;
int p = 4;

printf("\n Result of invert inverting the %d bits at position %d of %x = %x\n", n, p, x, invert(x, p, n));

}

int invert(unsigned int x, int p, int n){
	
return (x ^ (~(~0 << n) << (p-n+1)));

}
