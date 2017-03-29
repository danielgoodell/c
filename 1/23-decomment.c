#include <stdio.h>

int main(void){
	int insidecomment = 0;
	int insidequotes = 0;
	int insidedoublequotes = 0;
	char c;
	
	while((c=getchar()) != EOF){
		if((c == '\\') && (insidedoublequotes == 1)){
			putchar(c);
			c = getchar();
			putchar(c);}
		else if((c == '\\') && (insidequotes == 1)){
			putchar(c);
			c = getchar();
			putchar(c);}
		else if((c == '\"') && (insidedoublequotes == 0) && (insidequotes == 0)){
			putchar(c);
			insidequotes=1;}
		else if((c == '\'') && (insidequotes == 0) && (insidedoublequotes == 0)){
			putchar(c);
			insidequotes=1;}
		else if((c == '\"') && (insidedoublequotes == 1)){
			putchar(c);
			insidedoublequotes=0;}
		else if((c == '\'') && insidequotes== 1){
			putchar(c);
			insidequotes=0;}
		else if((c == '/') && (insidequotes == 0) && (insidedoublequotes == 0)){
			if((c=getchar()) == '/'){
				insidecomment = 1;
				while((c = getchar()) != '\n')
					;
				insidecomment = 0;
				putchar('\n');}
			else if(c == '*'){
				insidecomment = 1;
				while(insidecomment == 1){
					while ((c=getchar()) != '*');
					if((c=getchar()) == '/')
						insidecomment = 0;}}
					else if (c == '*')
						
			else {
				putchar('/');
				putchar(c); }
		}
		else
			putchar(c);
	}
//printf("\nComment' = %d", insidecomment);
//printf("\nDoubleQuotes = %d", insidedoublequotes);
//printf("\nQuotes = %d", insidequotes);
}




