#include "shell.h"

char *read_line(char *buffer)
{
	size_t size = 0;
	int i = 0;

	fflush(stdin);
	i = getline(&buffer, &size, stdin);
	if (i == EOF) {
		free(buffer);
		exit(0);
	}
	if ((int) i < 0)
	{
		free(buffer);
		exit(1);
	}

	buffer[i - 1] = '\0';
	return(buffer);
}
