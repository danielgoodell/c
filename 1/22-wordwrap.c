#include <stdio.h>

#define COLUMNWIDTH 80
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

	int i = 0;
	int end = 0;
	int firstchar=0;

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
		if (linebuffer[lastspace] == '\t')
			firstchar = lastspace + TABSTOP - (lastspace-(lastspace/TABSTOP)*TABSTOP);
		else
			firstchar = lastspace+1;
		i = firstchar;
		while(i < COLUMNWIDTH){
			if (linebuffer[i]!='\t'){
				linebuffer[i-firstchar] = linebuffer[i];
				i++;}
			else{
				linebuffer[i-firstchar] = linebuffer[i];
				i = i + TABSTOP - (i-(i/TABSTOP)*TABSTOP);}
		}
		return (i-firstchar);
	} else
		return 0;
}
