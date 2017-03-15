#include <stdio.h>

float c_to_f(float deg_c);

int main(){
	float celsius;
	int step, lower, upper;
	
	lower=0;
	upper=100;
	step=10;
	celsius=lower;
	
	printf("Conversion Table\n   °C     °F\n");
	
	while(celsius <= upper){
		printf("%5.0f %6.1f\n", celsius, c_to_f(celsius));
		celsius = celsius + step;
	}
}

/* c_to_f: converts a float in deg C to a float in deg F. */

float c_to_f(float deg_c)
{
	return (32.0 + ((9./5.) * deg_c));
}


	
	
