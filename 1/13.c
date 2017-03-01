//This program prints a histogram of the lengths of the words that are input

#include <stdio.h>
#define IN 1
#define OUT 0
#define MAXWORDLEN 20 // formatting falls apart with maxwordlen>100

int main(){
	int lengths[MAXWORDLEN];
	int length = 0;
	int state = OUT;
	int i, c;
	
/* 
This section counts the length of every word from the input and puts 
it into an array of length 10. The number of one-letter words are stored at lengths[0].
Words ten letter or longer are stored at lengths[9] 
*/
	
	for(i = 0; i<MAXWORDLEN; i++)
		lengths[i]=0;
	
	while((c=getchar())!=EOF){
		if((c==' ' || c=='\n' || c=='\t') && state==IN){
			if(length>=MAXWORDLEN)
				++lengths[MAXWORDLEN-1];
			else
				++lengths[length-1];
			length=0;
			state=OUT;
			}
		else if((c==' ' || c=='\n' || c=='\t') && state==OUT)
			;			
		else if(state==OUT){
			length=1;
			state=IN;
		}
		else if(state==IN)
			length++;
	}
			
// This section prints the histogram once all the lengths are counted

	for(i=0;i<MAXWORDLEN-1;i++){
		printf("%2d  ",i+1);
		for(c=0;c<lengths[i];c++)
			putchar('*');
		putchar('\n');
	}
	printf(" +  ");
	for(c=0;c<lengths[MAXWORDLEN-1];c++)
		putchar('*');
	putchar('\n');
}				

