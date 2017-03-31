#include <stdio.h>
#include <limits.h>
#include <float.h>

int main(void){
	printf("Datatype ranges from the c headers:\n");

	printf("\nUnsigned char max =\t%d\n", UCHAR_MAX);
	printf("Signed char min =\t%d\n", CHAR_MIN);
	printf("Signed char max =\t%d\n", CHAR_MAX);
	
	printf("\nUnsigned short max =\t%d\n", USHRT_MAX);
	printf("Signed short min =\t%d\n", SHRT_MIN);
	printf("Signed short max =\t%d\n", SHRT_MAX);

	printf("\nUnsigned int max =\t%u\n", UINT_MAX);
	printf("Signed int min =\t%d\n", INT_MIN);
	printf("Signed int max =\t%d\n", INT_MAX);

	printf("\nUnsigned long max =\t%lu\n", ULONG_MAX);
	printf("Signed long min =\t%ld\n", LONG_MIN);
	printf("Signed long max =\t%ld\n", LONG_MAX);

	printf("\nDatatype ranges from direct computation\n");

	unsigned char uc = 0;
	printf("\nUnsigned char max =\t%d\n", --uc);
	
	char c = 0;
	while(--c<0);
	printf("Signed char min =\t%d\n", ++c);
	c=0;
	while(++c>0);
	printf("Signed char max =\t%d\n", --c);

	unsigned short us = 0;
	printf("\nUnsigned short max =\t%d\n", (--us));
	
	short s = 0;
	while(--s < 0);
	printf("Signed short min =\t%d\n", ++s);
	s=0;
	while(++s>0);
	printf("Signed short max =\t%d\n", --s);

	unsigned int ui = 0;
	printf("\nUnsigned int max =\t%d\n", (--ui));
	
	int i = 0;
	while(--i < 0);
	printf("Signed int min =\t%d\n", ++i);
	i=0;
	while(++i>0);
	printf("Signed int max =\t%d\n", --i);

	unsigned long ul = 0;
	printf("\nUnsigned int max =\t%lu\n", (--ul));
	
	long l = 0;
	while(--l < 0);
	printf("Signed long min =\t%ld\n", ++l);
	l=0;
	while(++l>0);
	printf("Signed int max =\t%ld\n", --l);
	
}
