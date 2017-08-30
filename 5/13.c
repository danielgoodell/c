/*	Write the program tail, which prints the last n lines of its input.
	By default, n is 10, let us say, but it can be changed by an optional argument, so that
		tail -n
	prints the last n lines.
*/

#include <stdio.h>
#include <stdlib.h>

#define TAIL_DEFAULT 10
#define TAIL_MAX 1000
#define MAX_LINE 100

int initialize_tail(int argc, char *argv[]);
int getline(char *, int);

int main(int argc, char *argv[])
{
	int tail = initialize_tail(argc, argv);
	int i = 0, len;
	char *p[TAIL_MAX] = {NULL};
	char buffer[TAIL_MAX*MAX_LINE];
	char *pbuffer = buffer;
	
	while((len = getline(pbuffer, MAX_LINE)) != 0){
		if (i+1 > TAIL_MAX){
			i = 0;
			pbuffer = buffer;
		}
		p[i] = pbuffer;
		pbuffer += len+1;
		i++;
	}	
	
	do{
		printf("%s\n", p[i - tail]);
		if(i-1 < 0)
			i = TAIL_MAX;
	}while(--tail);
}

int initialize_tail(int argc, char *argv[])
{
	while(--argc != 0){
		if ((*++argv)[0] == '-')
			return atoi((*argv)+1);
	}
	return TAIL_DEFAULT;
}

int getline(char s[], int lim)
{
	int c, i;

	for(i=0; (c=getchar())!=EOF && c!='\n'; ++i){
		if (i<lim-1)
			s[i] = c;
	}
	if (i>lim-1){	
		if (c == '\n') {
			s[lim-1] = ' ';
			++i;
 		}
		s[lim]= '\0';
	}
	else{
		if (c == '\n') {
			s[i] = ' ';
			++i;
		}
		s[i]='\0';
	}
	return i;
}

