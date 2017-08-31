/*	Write the program tail, which prints the last n lines of its input. By default, n is 10, 
	let us say, but it can be changed by an optional argument, so that:
		tail -n
	prints the last n lines.
*/

#include <stdio.h>
#include <stdlib.h>

#define TAIL_DEFAULT 10
#define TAIL_MAX 100
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

	/*This while loop gets lines and places them in the buffer array
	as compactly as possible. It also sets each element of *p[] to point 
	to the beginning point of each string. Once *p[] is full we set it
	back to the beginning so we can handle and infinite number of input 
	lines.
	*/	
	while((len = getline(pbuffer, MAX_LINE)) >= 0){
		if (i+1 >= TAIL_MAX){		
			i = 0;			
			pbuffer = buffer;
		}
		p[i] = pbuffer;
		pbuffer += len;
		i++;
	}
	/* This do{}while loop can will print the last n lines, where n = tail.
	since the buffer wraps around when 
	*/
	do{
		printf("%s", p[i - tail]);
		if(i == 0)
			i = TAIL_MAX;
	}while(--tail);
}

/*initialize_tail: gives either the tail length from the arguments or the 
	default. It won't return a value larger than TAIL_MAX.
*/
int initialize_tail(int argc, char *argv[])
{
	while(--argc != 0){
		if ((*++argv)[0] == '-'){
			int tail = atoi((*argv)+1);
			if (tail > TAIL_MAX)
				return TAIL_MAX;
			return tail;
		}
	}
	return TAIL_DEFAULT;
}

/*getline: simplified get line, returns line length (including \0) and -1 if no 
	characters gotten. and puts the gotten line in s[]; If nothing is 
	gotten, s[] doesn't change.
*/
int getline(char s[], int lim)
{
	int c, i;

	for(i=0; (c=getchar()) !=EOF && c != '\n' && c != '\0' && i < lim-1; i++){
		s[i] = c;
	}
	if (i == 0) // If we didn't get an chars return -1 so we know that we are done.
		return -1;
	s[i++] = '\n';
	s[i++] = '\0';

	return i;
}

