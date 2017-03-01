#include <stdio.h>

/* print Fahrenheit-Celsius table
   for fahr = 0, 20, ..., 300; floating point version */
   
int main()
{ 
	double fahr, celsius;
	int lower, upper, step;
	
	lower = 0;	/*lower limit of temperature table*/
	upper = 300;	/*upper limit of temp table*/
	step = 20;	/*step size*/
	fahr = lower;
	printf("Conversion Table\n   °F     °C\n");
	
	while (fahr <= upper){
		celsius = (5.0/9.0) * (fahr-32.0);
		printf("%5.0f %6.1f\n", fahr, celsius);
		fahr = fahr + step;
	}	
	return 0;
}


