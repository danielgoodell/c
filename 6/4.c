/*	6-4: Write a program that prints the distinct words in its input sorted into decreasing 
	order of frequency of ocurrence. Precede each word by its count.
	
	First I'm going to run the program given in the book that counts words and stores them in
	a binary tree. 
	Then the part I'm actually going to write some functions to create a NEW binary tree
	from the first one except now it will be sorted in descending order by count instead of
	alphabetically.
	This will require two recursive functions, one similar to treeprint and one similar to 
	addnode.
	Also added are a couple functions that recursively destroy the binary trees to free their 
	memory after I am done with them.
*/

#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

#define MAXWORD 100
#define BUFSIZE  1000

char buf[BUFSIZE];	//buffer for ungetch
int bufp = 0;		//next free position in buf

char *keytab[] = {"a", "an", "the", "of", "at", "on"}; //words not to include.

struct tnode {
	char *word;
	int count;		
	struct tnode *left;	
	struct tnode *right;
};

int getword(char *, int);
struct tnode *addtree(struct tnode *p, char *w);
void treeprint(struct tnode *);
struct tnode *talloc(void);
char *strdup(char *s);
struct tnode *caddnode(struct tnode *, struct tnode *);
struct tnode *treesort(struct tnode *, struct tnode *);
void destroytree(struct tnode *);

int main(int argc, char **argv)
{
	struct tnode *root, *sorted;

	char word[MAXWORD];
	
	root = NULL;
	//sorted = talloc();
	sorted = NULL;
	while (getword(word, MAXWORD) != EOF)
		if (isalpha(word[0]))
			root = addtree(root, word);

	sorted = treesort(root, sorted);
	
	destroytree(root);

	treeprint(sorted);
	
	destroytree(sorted);
	
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
		p->count++;
	else if (cond < 0)
		p->left = addtree(p->left, w);
	else	
		p->right = addtree(p->right, w);
	return p;
}

//treesort: traverses the binary tree and calls caddnode to add each element to a new binary tree.
struct tnode *treesort(struct tnode *p, struct tnode *c)
{	
	if (p != NULL) {
		c = caddnode(c, p);
		treesort(p->left, c);
		treesort(p->right, c);
	}
	return c;
}

//caddnode: adds each new element into the binary tree in descending order based on count.
struct tnode *caddnode(struct tnode *c, struct tnode *p)
{
	if(c == NULL){
		c = talloc();
		c->word = strdup(p->word);
		c->left = c->right = NULL;
		c->count = p->count;
	}
	else if (p->count >= c->count){
		c->left = caddnode(c->left, p);
	}
	else {	
		c->right = caddnode(c->right, p);
	}

	return c;
}

//delete the entire tree, freeing all the used memory.
void destroytree(struct tnode *p)
{
	if (p != NULL){
		destroytree(p->left);
		destroytree(p->right);
		free(p->word); // free the strdup allocation
		free(p);	//free the talloc allocation
	}
}
		
//print items of the tree in alphabetical order
void treeprint(struct tnode *p)
{
	if (p!= NULL) {
		treeprint(p->left);
		printf("%4d, %s\n", p->count, p->word);
		treeprint(p->right);
	}
}

//allocate another tree node
struct tnode *talloc(void)
{
	return (struct tnode *) malloc (sizeof(struct tnode));
}

//make a duplicate of string s
char *strdup(char *s)
{
	char *p;
	
	p = (char *) malloc(strlen(s)+1);	//+1 for the terminator
	if (p != NULL)
		strcpy(p, s);
	return p;
}

//getword: get next word or character from input. Don't get words less 3 chars in length
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
	if (strlen(word) < 3){ //don't return words less than 3 characeters long.
		word[0] = 0;
		return 0;
	}
	return word[0];
}

//getch: get the next char from the input or last ungetched char from the buffer.	
int getch(void)
{
	return (bufp > 0) ? buf[--bufp] : getchar();
}

//ungetch: push a character back to the input buffer.
void ungetch(int c)
{
	if (bufp >= BUFSIZE)
		printf("ungetch: too many characters\n");
	else
		buf[bufp++] = c;
}
