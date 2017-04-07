/* x & (x-1) deletes the rightmost bit because subtracting 1 actually inverts all the least significant bits starting at the last 1. 
When an "&" is performed with the original number the inverted bits will all evaluate to zero while the higher bits are untouched. 
Observe:
	11100110
	-      1
-------------------
=	11100101
&   11100110
-------------------
=	11100100                 	   */


#include <stdio.h>

int bitcount(unsigned int x);

int main(void){

unsigned int x = 0x100200F0;


printf("\nNumber of bits in %x = %d \n", x, bitcount(x));

}

int bitcount(unsigned int x){

int i = 0;

while(x!=0){
	x&=(x-1);
	i++;}

return i;
}
