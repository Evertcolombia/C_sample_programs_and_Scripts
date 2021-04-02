#include <stdio.h>
#include <string.h>
#include <ctype.h>

struct tnode {
	char *word;	/* points to the next */
	int count;	/* number of ocurrences */
	struct tnode *left;	/* left child */
	struct tnode *right;	/* righ child */
};

#define MAXWORD 10
struct tnode *addtree(struct tnode *, char *);
struct tnode *talloc(void);
char *strdup(char *);
void treeprint(struct tnode *);
int getword(char *, int);

/* word frequency count */
int main(void)
{
	struct tnode *root;
	char word[MAXWORD];

	root = NULL;
	while (getword(word, MAXWORD) != EOF)
	{
		if (isalpha(word[0]))
			root = addtree(root word);
	}
	treeprint(root);
	return (0);
}

/* getword: get next word or character from input */
int getword(char *word, int lim)
{
	int c, getch(void);
	void ungetch(int);
	char *w = word;

	while (isspace(c = getch()))
		;
	if (c != EOF)
		*w++ = c;
	if (!isalpha(c)) {
		*w = '\0';
		return (c);
	}
	for (; --lim > 0; w++) {
		if (!isalnum(*w = getch())) {
			ungetch(*w);
			break;
		}
	}
	
	*w = '\0';
	return (word[0]);
}

/* addtree: add a node with w, at or below p */
struct treenode *addtree(struct tnode *p, char *w)
{
	int cond;
	
	if (p == NULL) {
		p = talloc();
		p->word = strdup(w);
		p->count = 1;
		p->left = p->right = NULL;
	}
	else if ((cond = strcmp(w, p->word)) == 0)
		p->count++;
	else if	 (cond < 0)
		p->left = addtree(p->left, w);
	else
		p->right = addtree(p->right, w);
	
	return (p);
}


/* treeprint: in-order print of tree p */
void treeprint(struct tnode *p)
{
	if (p != NULL) {
		treeprint(p->left);
		printf("%4d  %s\n", p->count, p->word);
		treeprint(p->right);
	}
}

#include <stdlib.h>

/* talloc: make a tnode */
struct tnode *talloc(void)
{
	return (struct tnode *) malloc(sizeof(struct tnode));
}

/* make a duplicate of s */
char *strdup(char *s)
{
	char *p;

	p = (char *) malloc (strlen(s) + 1);
	
	if (p != NULL)
		strcpy(p, s);
	return (p);
}
