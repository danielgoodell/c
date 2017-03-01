//This program prints a histogram of the frequencies of different characters in its input.

#include <stdio.h>

int main(){
	int c=0;
	int i=0;
	//"!" is the first ascii character, and "~" is the last. the array must be ("~"-"!") characters long.
	int character['~'-'!'+1];
	
	for(i=0;i<=('~'-'!');i++)
		character[i] = 0;
	
	while((c=getchar())!=EOF){
		if(c>='!'&&c<='~')
			++character[c-'!'];
	}
	
	for(c=0;c<=('~'-'!');c++){
		printf("%c :", (c+'!'));
		for(i=0;i<character[c];i++)
			putchar('*');
		putchar('\n');
	}
return 0;	
}
