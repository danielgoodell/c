#include <stdio.h>

char nextchar(char buffer[2]);
int isequal(char buffer[2], char condition[2]);

int main (void){
	char buffer[2] = {'0', '0'};
	char c;
	int incomment = 0;
	int indoublequotes = 0;
	int inquotes = 0;

	if(nextchar(buffer) == EOF)
		return 0 ;
	if(nextchar(buffer) == EOF)
		return 0 ;
	while((c = nextchar(buffer))!= EOF){
		if (isequal(buffer, "/*") && inquotes == 0 && indoublequotes == 0 && incomment == 0){
			putchar(c);
			while (isequal(buffer, "*/") == 0 && c != EOF)
				c = nextchar(buffer);
			nextchar(buffer);
//			nextchar(buffer);
		}
		else if (isequal(buffer, "//") && inquotes == 0 && indoublequotes == 0 && incomment == 0){
			putchar(c);
			while (buffer[1] != '\n' && buffer[1] != EOF)
				nextchar(buffer);
			putchar(buffer[1]);
			nextchar(buffer);
//			nextchar(buffer);
		}
		else
			putchar(c);
		}
	//if(incomment == 0){
//		putchar(buffer[0]);
		putchar(buffer[0]);//}
}

char nextchar(char buffer[2]){
	char d; 
	char c = getchar();
	if(c != EOF){
		d = buffer[0];
		buffer[0] = buffer[1];
		buffer[1] = c;
		return d;
	}
	else
		return c;
}

int isequal(char buffer[2], char condition[2]){
	if(buffer[0] == condition[0] && buffer[1] == condition[1])
		return 1;
	else 
		return 0;
}
