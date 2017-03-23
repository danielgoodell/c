#include <stdio.h>

int main()
{
	char c;
	int i=0; /* Line location for tabstop calculations */
	int tabspace=4;/* Width of tab stops */;
	int whitespace=0; /*Size of accumulated whitepsace */

	while((c=getchar()) != EOF){
		
		if (c == ' '){
			whitespace++;
			i++;}
		else if (c == '\t'){
			whitespace = whitespace + tabspace - (i -(i/tabspace)*tabspace);
			i = i + tabspace - (i - (i/tabspace)*tabspace)-1;}
		else{
			while(whitespace > 0){
				if ((i -(i/tabspace)*tabspace == 0) || (whitespace > tabspace)){
					putchar('\t');
					whitespace = whitespace - (tabspace - ((i-whitespace) - ((i-whitespace)/tabspace)*tabspace));}
				else {
					putchar(' ');
					whitespace--;}
			}
			if (c == '\n'){
				putchar('\n');
				i = 0;}
			else{
				putchar(c);
				i++;}
		}
	}
}l
