#include <stdio.h>

// Replace backspace with \b, \ with \\, and tab with \t
// Doesn't seem to work right with backspaces due to the terminal input handling.
// Also I don't completely understand how getchar works. I can hit CTRL-D and sometimes I have to hit it twice. enter also ends the input. It must have something to do with the terminal.

int main(){
	int c, d;
	printf("\n");	
	while((c=getchar()) != EOF){
		d = 0;
		if(c == '\t'){
			printf("\\t");
			d = 1;
		}
		if(c == '\b'){
			printf("\\b");
			d = 1;
		}
		if(c == '\\'){
			printf("\\\\");
			d = 1;
		}
		if(d == 0)
			putchar(c);
	}
	printf("\n");
}
			
