/*	6-3: Write a corss-referenced that prints a list of all words in a document, and, for each 
	word, a list of the line numbers on which it occurs. Remove noise words like "the", and 
	"and" and so on.
	
	This program is similar to the last program except that ewe need to keep track of the 
	current line number and when a word is found add its line number to a list that is kept
	in each word node.
	
*/

#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <strings.h>
#include <stdlib.h>

#define MAXWORD 100
#define BUFSIZE  1000

char buf[BUFSIZE];	//buffer for ungetch
int bufp = 0;		//next free position in buf

char *keytab[] = {"the", "and", "if", "a"};

struct lnode {
	int line;
	struct lnode *left;
	struct lnode *right;
};

struct tnode {
	char *word;
	int count;		
	struct tnode *left;	
	struct tnode *right;
	struct lnode *root;
};

int getword(char *, int);
struct tnode *addtree(struct tnode *p, char *w, int);
struct lnode *laddtree(struct lnode *p, int);
void treeprint(struct tnode *);
void ltreeprint(struct lnode *, int);
struct tnode *talloc(void);
struct lnode *lalloc(void);
char *strdup(char *s);

int main(int argc, char **argv)
{
	struct tnode *root;
	char word[MAXWORD], c;
	int linenumber = 1;
	
	root = NULL;
	while ((c = getword(word, MAXWORD)) != EOF){
		if (c == '\n')
			linenumber++;
		else if (isalpha(word[0]))
			root = addtree(root, word, linenumber);
	}
	treeprint(root);
	putchar('\n');
	return 0;
}

//addtree: add a note with w, at or below p

struct tnode *addtree(struct tnode *p, char *w, int linenumber)
{
	int cond;
	
	if(p == NULL) {
		p = talloc();
		p->word = strdup(w);
		p->left = p->right = NULL;
		p->root = NULL;
		p->root = laddtree(p->root, linenumber);
	}
	else if ((cond=strcasecmp(w, p->word)) == 0)
		p->root = laddtree(p->root, linenumber);
	else if (cond < 0)
		p->left = addtree(p->left, w, linenumber);
	else	
		p->right = addtree(p->right, w, linenumber);
	return p;
}

struct lnode *laddtree(struct lnode *p, int n)
{
	if(p == NULL) {
		p = lalloc();
		p->line = n;
		p->left = p->right = NULL;
	}
	else if (n == p->line)
		; // do nothing if it's on the same line.
	else if (n < p->line){
		p->left = laddtree(p->left, n);
	}
	else	{
		p->right = laddtree(p->right, n);
	}
	return p;
}


//print items of the tree in alphabetical order
void treeprint(struct tnode *p)
{
	
	if (p!= NULL) {	
		treeprint(p->left);
		printf("\n%s ", p->word);
		ltreeprint(p->root, 1);
		treeprint(p->right);
	}
}

void ltreeprint(struct lnode *p, int first)
{	
	if (p!= NULL) {	
		ltreeprint(p->left, 0);
		if (first)
			printf(" %d", p->line);
		else 
			printf(", %d", p->line);
		ltreeprint(p->right, 0);
	}
}

//allocate another tree node
struct tnode *talloc(void)
{
	return (struct tnode *) malloc (sizeof(struct tnode));
}

//allocate a pagenumber
struct lnode *lalloc(void)
{
	return (struct lnode *) malloc (sizeof(struct lnode));
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
	while (isspace(c = getch())){
		if (c == '\n')
			return '\n';
	}		
	if (c != EOF)
		*w++ = c;			
	if (!isalpha(c)) {
		*w = '\0';
		return c;
	}
	
	for ( ; --lim > 0; w++){
		if (!isalnum(*w = getch())) {	//underscore support
			ungetch(*w);
			break;
		}
	}
	*w = '\0';
	
	//added the below loop so that nothing from the list of garbage words is returned
	
	for(int i = (sizeof(keytab)/sizeof keytab[0])-1; i>=0; i--) {
		if (!strcmp(keytab[i], word)){
			word[0] = '\0';
			return 0;
		}
	}	
		if (strlen(word)< 3){
			word[0] = 0;
			return 0;
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
