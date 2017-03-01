#include <stdio.h>

int main(){
	float fahr, celsius;
	int step, lower, upper;
	
	lower=0;
	upper=100;
	step=10;
	celsius=lower;
	
	printf("Conversion Table\n   °C     °F\n");
	
	while(celsius <= upper){
		fahr = 32.0 + ((9./5.) * celsius);
		printf("%5.0f %6.1f\n", celsius, fahr);
		celsius = celsius + step;
	}
}
	
	
	

