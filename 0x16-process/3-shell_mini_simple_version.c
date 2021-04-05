#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>

int main()
{
	pid_t child_pid;
	size_t bufsize = 32;
	char *buffer, *tokens[10];
	size_t characters;
	int status, i, a = 0;

	while (a  == 0)
	{
		i = 0;
		buffer = (char *) malloc(bufsize * sizeof(char));
		if (buffer == NULL)
		{
			perror("Unable to allocate buffer");
			exit(1);
		}

		printf("#cisfun$ ");
		characters = getline(&buffer, &bufsize, stdin);
		buffer[characters - 1] = '\0';
		tokens[0] = strtok(buffer, " ");
		
		while(tokens[i] != NULL)
			tokens[++i] = strtok(NULL, " ");

		child_pid = fork();
		if (child_pid < 0)
		{
			perror("Error: ");
			exit(0);
		}

		else if(child_pid == 0)
		{
			if (execve(tokens[0], tokens, NULL) == -1)
				perror("Error executing  program");
		}
		wait(&status);
		free(buffer);
	}
	return (0);
}
