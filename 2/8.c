#include <stdio.h>

int rightrot(unsigned int x, int n);

int main(void){

unsigned int x = 0x100000F0;
int n = 5;

printf("\nResult of rotating %x right %d bits, wrapping the bits around = %x\n\n", x, n, rightrot(x, n));

}

int rightrot(unsigned int x, int n){

/*Find out the number of bits in an integer on this system in number of bits.*/

	unsigned int y = 1;
	int i = 0;
	while((y << (i)) != 0)
		i++;

return (x << (i-n)) | (x >> n);
}
