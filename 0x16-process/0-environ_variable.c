#include <stdlib.h>
#include <stdio.h>

extern char **environ;

int main(int argc, char *argv[])
{
	char **ep;

	(void) argc;
	(void) argv;
	for (ep = environ; *ep != NULL; ep++)
		puts(*ep);
	return (0);
}
