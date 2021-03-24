#include <stdio.h>
#include <string.h>

#define MAXLINES 5 /* max #lines to be sorted */

char *lineptr[MAXLINES]; /* pointers to text lines */

int readLines(char *lineptr[], int maxlines);
void writeLines(char *lineptr[], int nlines);
int _getline(char *s, int n);
char *alloc(int);
void qsort(char *lineptr[], int left, int right);

/* Sort input lines */
int  main(void)
{
	int nlines;

	if ((nlines = readLines(lineptr, MAXLINES)) >= 0) {
		qsort(lineptr, 0, nlines-1);
		writeLines(lineptr, nlines);
		return (0);
	}
	else {
		printf("Error: Input to big to sort\n");
		return (1);
	}
}

#define MAXLEN 1000 /* max lenght of any input line */

/* readLines: read input lines */
int readLines(char *lineptr[], int maxlines)
{
	int len, nlines;
	char *p, line[MAXLEN];

	nlines = 0;
	while ((len = _getline(line, MAXLEN)) > 0) {
		p = alloc(len);
		if (p == NULL)
			return (-1);
		if (nlines >= maxlines)
			return (nlines);
		else {
			if (nlines <= MAXLINES)
			{
				line[len-1] = '\0'; /* delete new line */
				strcpy(p, line);
				lineptr[nlines++] = p;
			}
			else
				break;
		}
	}
	printf("%d", nlines);
	return (nlines);
}

/* write output lines */
void writeLines(char *lineptr[], int nlines)
{
	while (nlines-- > 0)
		printf("%s\n", *lineptr++);
}

/* getline: Read a line  into s, return length*/
int _getline(char *s, int lim)
{
	int i, c;

	for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; i++)
	{
		s[i] = c;
	}
	if (c == '\n')
		s[i++] = c;
	s[i] = '\0';

	return (i);
}

static char allocbuf[MAXLEN];
static char *allocp = allocbuf;

/* alloc: return pointers to n characters*/
char *alloc(int n)
{
	if (allocbuf + MAXLEN - allocp >= 0) {
		allocp += n;
		return (allocp - n);
	}
	else
		return (0);
}

/* qsort: sort v[left] ...v[right] into increasing order */
void qsort(char *lineptr[], int left, int right)
{
	int i, last;
	void swap(char *lineptr[], int i, int j);

	if (left >= right) /* do nothing if array conains */
		return; /* fewer than two elements*/

	swap(lineptr, left, (left + right) / 2);
	last = left;

	for (i = left + 1; i <= right; i++)
	{
		if (strcmp(lineptr[i], lineptr[left]) < 0)
			swap(lineptr, ++last, i);
		swap(lineptr, left, last);
		swap(lineptr, last + 1, right);
	}
}

/* swap: intercgange v[i] and v[j] */
void swap(char *v[], int i, int j)
{
	char *temp;

	temp = v[i];
	v[i] = v[j];
	v[j] = temp;
}
