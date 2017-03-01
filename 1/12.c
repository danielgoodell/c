#include <stdio.h>

#define IN 1
#define OUT 0

//this program prints its input one word per line, ignoring whitespace and whatnot.

int main(){
	int c, state;
	c=0;
	state = OUT;
	while((c=getchar())!=EOF){
		if(c==' ' || c=='\t' || c=='\n'){
			if(state==IN){
				putchar('\n');
				state = OUT;
			}
		}
		else{
			putchar(c);
			state = IN;
		}
	}
}	
		
		
		
	
