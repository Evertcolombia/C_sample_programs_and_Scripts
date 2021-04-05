#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
	char *buffer, *token, *tokens[32];
	size_t bufsize = 32;
	size_t characters;
	int i = 0;

	buffer = (char *) malloc(bufsize * sizeof(char));
	if (buffer == NULL)
	{
		perror("Unable to allocate buffer");
		exit(1);
	}

	printf("$ ");
	characters = getline(&buffer, &bufsize, stdin);
	printf("%zu characters were read.\n", characters);
	token = strtok(buffer, " ");
	while (token != NULL) {
		tokens[i++] = token;
		token = strtok(NULL, " ");
	}
	i = 0;
	while (tokens[i])
	{
		printf("%s\n", tokens[i++]);
	}
	/*printf("%s\n",buffer);*/
	return (0);
}
