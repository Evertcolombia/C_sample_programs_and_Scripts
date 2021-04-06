#include "shell.h"

char *line_buffer(char *buffer)
{
	size_t bufsize = 32;

	buffer = (char *) malloc(bufsize * sizeof(char));
	if (buffer == NULL) {
		perror("Unable to allocate buffer");
		exit(1);
	}
	return (buffer);
}
