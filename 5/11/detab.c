#include <stdio.h>

int main()
{
	char c;
	int i=0;
	int tabspace=4 /* Width of tab stops */;

	for(;(c=getchar()) != EOF; i++){
		if (c == '\n'){
			putchar('\n');
			i=0;}
		else if (c == '\t')
			for(;printf(" "), i < tabspace; i++);
		else putchar(c);
		if (i == tabspace)
			i=0;
	}
}

