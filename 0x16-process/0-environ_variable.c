#include <stdlib.h>
#include <stdio.h>

extern char **environ;

int main(int argc, char **av, char **env)
{
	char **ep;

	(void) argc;
	(void) av;
	for (ep = environ; *ep != NULL; ep++)
		puts(*ep);

	printf("environ adresss: %p\n", (void *) &environ);
	printf("env adresss: %p\n", (void *) &env);

	return (0);
}


