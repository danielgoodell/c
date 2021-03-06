/*	Modify the programs entab and detab to accept a list of tab stops as arguments.
	Use the default tab settings if there are no arguments.
	
	I created a function tabstop to replace the previous variable tabstop to make modifying 
	the previous program as simple as possible. A variable j was added to keepo track of 
	the tabstop that we are currently in.
*/

#include <stdio.h>
#include <stdlib.h>
#define TABDEFAULT 8

int tabspace( int, char*[], int);

int main(int argc, char *argv[])
{
	char c;
	int i=0; /* Line location for tabstop calculations */
	int j=0; //Current tabstop number.
	int whitespace=0; /*Size of accumulated whitespace */

	while((c=getchar()) != EOF){
		if (c == ' '){
			whitespace++;
			i++;
		}
		else if (c == '\t'){
			whitespace = whitespace + tabspace(argc, argv, j) - (i -(i/tabspace(argc, argv, j))*tabspace(argc, argv, j));
			i = i + tabspace(argc, argv, j) - (i - (i/tabspace(argc, argv, j))*tabspace(argc, argv, j))-1;
			j++;
		}
		else{
			while(whitespace > 0){
				if ((i - (i/tabspace(argc, argv, j))*tabspace(argc, argv, j) == 0) || (whitespace > tabspace(argc, argv, j))){
					putchar('\t');
					whitespace -= (tabspace(argc, argv, j) - ((i-whitespace) - ((i-whitespace)/tabspace(argc, argv, j))*tabspace(argc, argv, j)));
					//whitespace = whitespace - (tabspace - ((i-whitespace) - ((i-whitespace)/tabspace)*tabspace));
					j++;
				}
				else {
					putchar(' ');
					whitespace--;
				}
			}
			if (c == '\n'){
				putchar('\n');
				i = 0;
				j = 0;
				whitespace = 0;
			}
			else{
				putchar(c);
				i++;
			}
		}
	}
}
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
