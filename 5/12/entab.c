/*	Extend entab and detab to accept the shorthand:
		entab -m +n
	to mean tab stops every n columnus, starting at column m. Choose convenient default behavior.
	
	Answer: I decided to modify problem 11 since it was already pretty close. The only thing I 
	needed to do was to modify tabspace to check for the command line parameters -m +n the first time
	is called and from then on it will use those tab stops. This operation is ensured using static
	variables in tabstop(). If the -n option is not present on the command line the program operation
	will remain the same as in problem 5-11.
*/

#include <stdio.h>
#include <stdlib.h>
#define TABDEFAULT 8

int tabspace(int, char*[], int);

int main(int argc, char *argv[])
{
	
	char c;
	int i=0; /* Line location for tabstop calculations */
	int j=0; // Current tabstop number.
	int whitespace=0; /*Size of accumulated whitespace */
	
	c = tabspace(argc, argv, j);
	
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
	static int m = 0;
	static int n = 0;
	
	if(n == 0){
		while(argv++, --argc > 0){
			if ((*argv)[0] == '-')
				m = atoi((*argv)+1);
			if ((*argv)[0] == '+')
				n = atoi((*argv)+1);
		}
		if(n == 0)
			n = -1;
	}
	if (n != -1 && n !=0){
		if(j == 0)
			rv = m;
		else 
			rv = n;	
	}			
	else if (argc < 2)
		rv = TABDEFAULT;
	else if (argc == 2)
		rv = atoi(*(argv+1));
	else if (j >= (argc-1))
		rv = TABDEFAULT;
	else
		rv = atoi(*(argv+j+1));
	return rv;
}
