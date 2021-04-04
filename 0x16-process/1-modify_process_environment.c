#define _GNU_SOURCE
#include <stdlib.h>
#include <stdio.h>

extern char **environ;

int main(int argc, char *argv[])
{
	int j;
	char **ep;

	clearenv(); /* Erase entire environment */

	for (j = 1; j < argc; j++) {
		if (putenv(argv[j]) != 0) {
			printf("putenv: %s", argv[j]);
			return (-1);
		}
	}

	if (setenv("GREET", "hello world", 0) == -1) {
		printf("setenv");
		return (-1);
	}

	unsetenv("BYE");

	for (ep = environ; *ep != NULL; ep++)
		puts(*ep);

	return (0);
}
