#include <stdio.h>
#include <limits.h>
#include <float.h>

int main(void){
	printf("Datatype ranges from the c headers:\n");

	printf("\nUnsigned char max =\t\t%d\n", UCHAR_MAX);
	printf("Signed char min =\t\t%d\n", CHAR_MIN);
	printf("Signed char max =\t\t%d\n", CHAR_MAX);
	
	printf("\nUnsigned short max =\t\t%d\n", USHRT_MAX);
	printf("Signed short min =\t\t%d\n", SHRT_MIN);
	printf("Signed short max =\t\t%d\n", SHRT_MAX);

	printf("\nUnsigned int max =\t\t%u\n", UINT_MAX);
	printf("Signed int min =\t\t%d\n", INT_MIN);
	printf("Signed int max =\t\t%d\n", INT_MAX);

	printf("\nUnsigned long max =\t\t%lu\n", ULONG_MAX);
	printf("Signed long min =\t\t%ld\n", LONG_MIN);
	printf("Signed long max =\t\t%ld\n", LONG_MAX);

	printf("\nUnsigned long long max =\t%llu\n", ULLONG_MAX);
	printf("Signed long long min =\t\t%lld\n", LLONG_MIN);
	printf("Signed long long max =\t\t%lld\n", LLONG_MAX);

	printf("\nFloat Max =\t\t\t%.*g\n", FLT_DECIMAL_DIG, FLT_MAX);
	printf("Double Max =\t\t\t%.*lg\n", DBL_DECIMAL_DIG, DBL_MAX);
	printf("Long Double max =\t\t%.*Lg\n", LDBL_DECIMAL_DIG, LDBL_MAX);


	printf("\nDatatype ranges from direct computation\n");

	unsigned char uc = 0;
	printf("\nUnsigned char max =\t\t%d\n", --uc);
	
	char c = 0;
	while(--c<0);
	printf("Signed char min =\t\t%d\n", ++c);
	c=0;
	while(++c>0);
	printf("Signed char max =\t\t%d\n", --c);

	unsigned short us = 0;
	printf("\nUnsigned short max =\t\t%d\n", (--us));
	
	short s = 0;
	while(--s < 0);
	printf("Signed short min =\t\t%d\n", ++s);
	s=0;
	while(++s>0);
	printf("Signed short max =\t\t%d\n", --s);

	unsigned int ui = 0;
	printf("\nUnsigned int max =\t\t%u\n", (--ui));
	
	ui = 1;
	while(ui << 1 >= ui)
		ui = ui << 1;
	printf("Signed int min =\t\t%d\n", (int)ui);
	--ui;
	printf("Signed int max =\t\t%d\n", (int)ui);

	unsigned long ul = 0;
	printf("\nUnsigned long max =\t\t%lu\n", (--ul));
	
	ul = 1;
	while((ul << 1) >= ul){
		ul = ul << 1;}
	printf("Signed long min =\t\t%ld\n", (long)ul);
	--ul;
	printf("Signed long max =\t\t%lu\n", (long)ul);
	
	unsigned long long ull = 0;
	printf("\nUnsigned long long max =\t%llu\n", (--ull));
	
	ull = 1;
	while((ull << 1) >= ull){
		ull = ull << 1;}
	printf("Signed long long min =\t\t%lld\n", (long long)ull);
	--ul;
	printf("Signed long long max =\t\t%llu\n", (long long)ull);
	
}
