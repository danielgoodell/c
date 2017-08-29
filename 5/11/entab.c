#include <stdio.h>

int tabspace(int, int, char*[]);

int main(int argc, char *argv[])
{
	char c;
	int i=0; /* Line location for tabstop calculations */
	int j=0;
	; /* Width of tab stops */;
	int whitespace=0; /*Size of accumulated whitepsace */

	while((j++, c=getchar()) != EOF){
		
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
}

int tabspace(int index, int argc, char *argv[]);
{

	if (argc < 2 || index > argc-1)	//if no list of tab stops given or if the tab stops
		return 4;
	if (argc == 2)
		return atoi((*argv)[]);
}
