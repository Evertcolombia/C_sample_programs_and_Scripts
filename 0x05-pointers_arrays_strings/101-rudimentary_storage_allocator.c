#define ALLOCSIZE 10000 /* size of available space */
#include <stdio.h>

static char allocbuf[ALLOCSIZE];	/* storage for alloc */
static char *allocp = allocbuf;		/* next free position */

char *alloc(int n)	/*Return pointer to n characters */
{
	if (allocbuf + ALLOCSIZE - allocp >= n) {	/* if fits */
		allocp += n;
		printf("here\n");
		return (allocp - n);	/* old p */
	}
	else	/* not enough room */
		return(0);
}

void afree(char *p)	/* free storage pointed to by p */
{
	if (p >= allocbuf && p < allocbuf + ALLOCSIZE)
		allocp = p;
}

int main(void)
{
	char *res;

	res = alloc(100);
	printf("%d\n", *res);
	return(1);
}
