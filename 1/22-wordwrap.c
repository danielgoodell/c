#include <stdio.h>

#define COLUMNWIDTH 78
#define TABSTOP 4

int printline(char linebuffer[], int lastspace, int len);

int main (void){
	int lastspace=COLUMNWIDTH;
	int i = 0;
	char c;
	char linebuffer[COLUMNWIDTH];

	while((c=getchar()) != EOF){
		if(c == '\n'){
			i = printline(linebuffer, COLUMNWIDTH, i-1);
			lastspace = COLUMNWIDTH;}
		else if (i == COLUMNWIDTH && c != ' ' && c!='\t'){
			i = printline(linebuffer, lastspace, COLUMNWIDTH);
			linebuffer[i]=c;
			lastspace = COLUMNWIDTH;
			i++;}
		else if (i == COLUMNWIDTH && c==' '){
			i = printline(linebuffer, COLUMNWIDTH, COLUMNWIDTH);
			linebuffer[i]=c;
			lastspace = COLUMNWIDTH;
			i++;}
		else if (i == COLUMNWIDTH && c=='\t'){
			i = printline(linebuffer, COLUMNWIDTH, COLUMNWIDTH);
			linebuffer[i]=c;
			lastspace = COLUMNWIDTH;
			i = i + TABSTOP - (i - (i/TABSTOP)* TABSTOP);}
		else if (c == ' '){
			linebuffer[i] = c;
			lastspace = i;
			i++;}
		else if (c == '\t'){
			linebuffer[i] = c;
			lastspace = i;
			i = i + TABSTOP - (i - (i/TABSTOP)* TABSTOP);
			if (i > COLUMNWIDTH-1)
				i = COLUMNWIDTH;}
		else{
			linebuffer[i] = c;
			i++;}
	}
}

int printline(char linebuffer[], int lastspace, int len){

	printf("LASTSPACE = %d\n", lastspace);
	printf("LEN = %d\n", len);

	int i = 0;
	int end = 0;

	if (len < COLUMNWIDTH-1)
		end = len;
	else if (len == COLUMNWIDTH-1 && lastspace == COLUMNWIDTH)
		end = len;
	else if (len == COLUMNWIDTH && lastspace <= COLUMNWIDTH)
		end=lastspace;
	while(i <= end && i<=(COLUMNWIDTH-1)){
		putchar(linebuffer[i]);
		if (linebuffer[i]=='\t'){
			i = i + TABSTOP - (i-(i/TABSTOP)*TABSTOP);
				if (i > COLUMNWIDTH-1)
					i = COLUMNWIDTH;}
		else
			i++;}
	putchar('\n');

	if (linebuffer[lastspace] == ' ' || (linebuffer[lastspace]=='\t' && TABSTOP+((lastspace/TABSTOP)*TABSTOP)<COLUMNWIDTH)){
		i=lastspace;
		while(i < COLUMNWIDTH-1){
			if (linebuffer[i+1]!='\t'){
				linebuffer[i-lastspace] = linebuffer[i+1];
				i++;}
			else
				i = i + TABSTOP - (i-(i/TABSTOP)*TABSTOP);
		}
		printf("Return Value = %d\n", COLUMNWIDTH-lastspace-1);
		return (i-lastspace);
	} else
		return 0;
}





