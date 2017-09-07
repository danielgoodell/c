/*	6-2: Write a program that reads a C program and prints in alphabetical order each group of 
	variable names that are identical in the first 6 characters, but different somewhere
	thereafter. Don't count words within strings and comments. Make 6 a parameter that can be 
	set from the command line.
	
	I'll use the word counting program given in the immediately preceding section with the 
	following changes:
	> Ignore the word count in the strcut.
	> Eliminating functions and struct types is too tricky so I'll just allow count anything 
	except keywords. getword will compare the found word to any keywords in *keytab[] and only
	return stuff that isn't in it. We'll get function names and struct types. If I wanted to do
	it correctly I would have to make getword able to ignore words after struct and ignore words
	followed by a '('
	> Add some code to parse the arguments to see if there is a number and use that for the 
		comparison
	> Modify treeprint to add an extra '/n' if the preceeding printed string is different in the 
	first n characters.
*/

#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

#define MAXWORD 100
#define BUFSIZE  1000

char buf[BUFSIZE];	//buffer for ungetch
int bufp = 0;		//next free position in buf

char *keytab[] = {"auto", "double", "int", "struct", "break", "else", "long", "switch", "case", 
		"enum", "register", "typedef", "char", "extern", "return", "union", "const", 
		"float", "short", "unsigned", "continue", "for", "signed", "void", "default", 
		"goto", "sizeof", "volatile", "do", "if", "static", "while"};

struct tnode {
	char *word;
	int count;		
	struct tnode *left;	
	struct tnode *right;
};

int getword(char *, int);
struct tnode *addtree(struct tnode *p, char *w);
void treeprint(struct tnode *, struct tnode *, int);
struct tnode *talloc(void);
char *strdup(char *s);

int main(int argc, char **argv)
{
	unsigned int n = 6; //number of chars to group variables names by, default 6.
	
	if(argc > 1){
		for( ; argc > 1 ; --argc)
			n = (unsigned int) atoi(argv[argc-1]);
			
	}
	struct tnode *root;
	char word[MAXWORD];
	
	root = NULL;
	while (getword(word, MAXWORD) != EOF)
		if (isalpha(word[0]) || word[0] == '_')
			root = addtree(root, word);
	treeprint(NULL, root, n);
	return 0;
}

//addtree: add a note with w, at or below p
struct tnode *addtree(struct tnode *p, char *w)
{
	int cond;
	
	if(p == NULL) {
		p = talloc();
		p->word = strdup(w);
		p->left = p->right = NULL;
		p-> count = 1;
	}
	else if ((cond=strcmp(w, p->word)) == 0)
		p-> count++;
	else if (cond < 0)
		p-> left = addtree(p->left, w);
	else	
		p->right = addtree(p->right, w);
	return p;
}

//print items of the tree in alphabetical order
void treeprint(struct tnode *c, struct tnode *p, int n)
{
	static struct tnode *l = NULL; // Save the last printed struct for comparison.
	
	if (p!= NULL) {
	
		treeprint(p, p->left, n);
				
		if (l != NULL && strncmp(l->word, p->word, n))
			printf("\n");
		printf("%s\n", p->word);
		l = p;	// Once the struct is printed save pointer for next comparison.
				
		treeprint(p, p->right, n);
	}
}

//allocate another tree node
struct tnode *talloc(void)
{
	return (struct tnode *) malloc (sizeof(struct tnode));
}
//make a duplicate of s
char *strdup(char *s)
{
	char *p;
	
	p = (char *) malloc(strlen(s)+1);	//+1 for the terminator
	if (p != NULL)
		strcpy(p, s);
	return p;
}

//getword: get next word or character from input
int getword(char * word, int lim)
{	
	int c, getch(void);
	void ungetch(int);
	char *w = word;
	
	w[0] = '\0';	//clear out word so we don't get repeated words after finding string comment, etc.
	while (isspace(c = getch()))
		;		
	if (c == '/'){
		if ((c = getch()) == '/'){
			while((c = getchar())!='\n')
				;
			return 0;
		}
		else if (c == '*'){
			while ((c = getchar()))
				if (c == '*')
					if ((c = getchar()) == '/')
						return 0;
		}
		else{
			*w++ = '/';
			*w = '\0';
			return '/';
		}
	}	
	else if (c == '\"'){
		while ((c = getchar())){
			if (c == '\\')
				getchar();
			else if (c == '\"')
				return 0;
		}
	}
	else if (c == '\''){
		while ((c = getchar())){
			if (c == '\\')
				getchar();
			else if (c == '\'')
				return 0;
		}
	}
	else if (c == '#'){
		while ((c = getchar()) != '\n')
			;
		return 0;
	}	
	else if (c != EOF)
		*w++ = c;			
	if (!isalpha(c) && c != '_') {	//underscore support
		*w = '\0';
		return c;
	}
	
	for ( ; --lim > 0; w++){
		if (!isalnum(*w = getch()) && *w != '_') {	//underscore support
			ungetch(*w);
			break;
		}
	}
	*w = '\0';
	//added the below loop so that nothing from the list of keywords is returned.
	
	for(int i = (sizeof(keytab)/sizeof keytab[0])-1; i>=0; i--) {
		if (!strcmp(keytab[i], word)){
			word[0] = '\0';
			return 0;
		}
	}	
	
	return word[0];
}
	
int getch(void)
{
	return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c) // push character back to input
{
	if (bufp >= BUFSIZE)
		printf("ungetch: too many characters\n");
	else
		buf[bufp++] = c;
}
