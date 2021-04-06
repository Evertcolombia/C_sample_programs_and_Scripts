#include "shell.h"

int main()
{
	pid_t child_pid;
	size_t bufsize = 32;
	char *buffer, *tokens[10];
	size_t characters;
	int status, i;
	bool state = true;
	while (state)
	{
		/*signal(SIGINT, handleCtrlc);*/
		if (isatty(STDIN_FILENO))
			write(STDIN_FILENO, "#cisfun$ ", 9);
		
		buffer = line_buffer(buffer);

		characters = getline(&buffer, &bufsize, stdin);
		if ((int) characters < 0)
		{
			free(buffer);
			exit(1);
		}

		else if ((int) characters == 1 && *buffer == 10) {
			free(buffer);
			continue;
		}
		if (buffer == NULL) {
			if (isatty(STDIN_FILENO))
				write(STDOUT_FILENO, "\n", 1);
			continue;
		}
		buffer[characters - 1] = '\0';

		i = 0;
		tokens[i] = strtok(buffer, " ");
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
				perror("./shell");
		}
		wait(&status);
		free(buffer);
	}
	return (0);
}
