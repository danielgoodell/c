#include <stdio.h>

// Counts blanks, tabs, and newlines

int main(){
	int tabs=0;
	int newlines=0;
	int blanks=0;
	int c;
	
	while((c = getchar()) != EOF){
		if(c == ' ')
			++blanks;
		if(c == '\t')
			++tabs;
		if(c == '\n')
			++newlines;
	}
	printf("blanks = %d, tabs = %d, and newlines = %d\n", blanks, tabs, newlines);
}
			
		
