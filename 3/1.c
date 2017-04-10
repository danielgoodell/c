#include <stdio.h>
#include <time.h>
#define MAXI 1000000

int binsearch(int x, int v[], int n);

int binsearch2(int x, int v[], int n);

int main(void){

	int v[MAXI];
	int n = 499;
	

	for(int i = 0; i<MAXI; i++)
		v[i] = i;
	
	clock_t start, end;
	double cpu_time_used;
     
	start = clock();
	for(int i = 1; i < 1000000; i++)
		binsearch(n, v, MAXI);
	end = clock();
	cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
	printf("\n binsearch CPU Time Used = %f secs", cpu_time_used);

	start = clock();
	for(int i = 1; i < 1000000; i++)
		binsearch2(n, v, MAXI);
	end = clock();
	cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
	printf("\n binsearch2 CPU Time Used = %f secs\n", cpu_time_used);


return 0;
}

int binsearch(int x, int v[], int n){
	
	int low, high, mid;

	low = 0;
	high = n - 1;
	while(low <= high) { 
		mid = (low + high)/2;
		if (x < v[mid])
			high = mid -1;
		else if(x > v[mid])
			low = mid + 1;
		else /*found match*/
			return mid;
	}
		return -1; /* no match */
}

int binsearch2(int x, int v[], int n){

	int low, high, mid;

	low = 0;
	high = n - 1;
	mid = (low + high)/2;

	while(low < high) { 
		if (x <= v[mid])
			high = mid;
		else 
			low = mid+1;
		mid = (low + high)/2;
		}

		if (v[mid] == x)
			return x;
		else
			return -1; /* no match */
}
			


