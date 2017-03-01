#include <stdio.h>
	//condense multiple spaces in the input to just one space
	
int main(){
	int c; //current character
	int lc = ' '; //last character
	
	while((c = getchar()) != EOF){
		if(c != ' ')
			putchar(c);
		if(c == ' '){
			if(lc != ' ')
				putchar(c);
		}
		lc = c;
	}
} 
		
		
		
	
			
