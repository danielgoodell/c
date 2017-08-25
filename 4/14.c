/* 	Define a macro swap(t,x,y) that interchanges two arguments of type t
	(Block structure will help)
*/

#include <stdio.h>

#define swap(t,x,y) {t i; i = x; x = y; y = i;}

int main(void){

	int a = 123;
	int b = 12;
	
	printf("a = %d, b = %d\n", a, b);
	swap(int,a,b);
	printf("after swap:\na = %d, b = %d\n", a, b);

}

