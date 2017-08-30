/*	Modify the programs entab and detab to accept a list of tab stops as arguments.
	Use the default tab settings if there are no arguments.
	
	I created a function tabstop to replace the previous variable tabstop to make modifying 
	the previous program as simple as possible. A variable j was added to keepo track of 
	the tabstop that we are currently in.
*/
#include <stdio.h>
#include <stdlib.h>
#define TABDEFAULT 8

int tabspace(int, char*[], int);

int main(int argc, char *argv[])
{
	char c;
	int i=1; // holds the current character within a column.
	int j=0; // Holds the current column

	for(;(c=getchar()) != EOF; i++){
//		printf("i = %d\n", i);
		if (c == '\n'){
			putchar('\n');
			i=0;
			j=0;
		}
		else if (c == '\t'){
			for(;printf(" "), i < tabspace(argc, argv, j); i++)
				;
		}
		else 
			putchar(c);			
		if (i == tabspace(argc, argv, j)){
			i=0;
			j++;
		}
	}
}

//tabspace: Returns the correct number of spaces
int tabspace(int argc, char *argv[], int j)
{
	int rv; 
	if (argc < 2)
		rv = TABDEFAULT;
	else if (argc == 2)
		rv = atoi(*(argv+1));
	else if (j >= (argc-1))
		rv = TABDEFAULT;
	else
		rv = atoi(*(argv+j+1));
		
//	printf("rv=%d, j = %d\n", rv, j);
	return rv;
}
