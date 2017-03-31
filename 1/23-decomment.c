#include <stdio.h>

int main(void){
	int insidecomment = 0;
	int insidequotes = 0;
	int insidedoublequotes = 0;
	char c = getchar();
	
	while(c != EOF){
		if((c == '\"') && (insidedoublequotes == 0) && (insidequotes == 0)){
			putchar(c);
			insidedoublequotes=1;
			c=getchar();
		}
		else if((c == '\'') && (insidequotes == 0) && (insidedoublequotes == 0)){
			putchar(c);
			insidequotes=1;
			c=getchar();
		}
		else if((c == '\"') && (insidedoublequotes == 1)){
			putchar(c);
			insidedoublequotes=0;
			c=getchar();
		}
		else if((c == '\'') && insidequotes== 1){
			putchar(c);
			insidequotes=0;
			c=getchar();
		}
		else if((insidequotes == 1 || insidedoublequotes == 1)){
			putchar(c);
			c = getchar();
		}
		else if((c == '/') && (insidequotes == 0) && (insidedoublequotes == 0)){
			if((c=getchar()) == '/'){
				insidecomment = 1;
				while((c = getchar()) != '\n')
					;
				insidecomment = 0;
				putchar('\n');
				c=getchar();
			}
			else if(c == '*'){
				insidecomment = 1;
				while(insidecomment == 1){
					if (c!='*')
						c=getchar();
					if (c=='*')
						if ((c=getchar())=='/')
							insidecomment = 0;
				}
			c=getchar();
			}
			else {
				putchar('/');
				 }
		}
		else{
			putchar(c);
			c=getchar();
		}
	}

}




