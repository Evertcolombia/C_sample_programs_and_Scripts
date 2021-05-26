#include <stdlib.h>
#include <stdio.h>
#include <string.h>

char *_getenv(const char *name);
int _strcmp(char *s1, char *s2);
int _strlen(char *s);

extern char **environ;

int main(int argc, char **av, char **env)
{
	char *token = NULL;
	if (argc < 2)
	{
		printf("bad usage\n");
		return(1);
	}

	token = _getenv(av[1]);
	printf("%s\n", token);

	return (0);
}


char *_getenv(const char *name)
{
	char **ep;


	if (name != NULL)
	{
		ep = environ;
		for (ep = environ; *ep != NULL; ep++) {
			if (_strcmp(*ep, (char *)name) == 0) {
				return (*ep);
			}
		}
	}
	return (NULL);
}

int _strcmp(char *s1, char *s2)
{
	for (; *s1 == *s2; s1++, s2++) {
		if (*(s1 + 1) == 61)
		{
			return (0);
		}
	}
	return (*s1 - *s2);
}

