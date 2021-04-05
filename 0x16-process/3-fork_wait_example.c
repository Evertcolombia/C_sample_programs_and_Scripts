#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(void)
{
	pid_t child_pid, wait_result;
	int status, i = 0;
	char *argv[] = {"/bin/ls", "-l", "/usr/", NULL};

	while (i < 5)
	{
		child_pid = fork();
			if (child_pid == -1)
		{
			perror("Error: ");
			return (1);
		}
		if (child_pid == 0)
		{
			sleep(2);
			printf();
			if (execve(argv[0], argv, NULL) == -1)
				perror("Error executing  program\n");
		}
		else 
		{
			wait_result = wait(&status);
			if (wait_result != -1)
				 printf("Process %lu returned result: %d\n", (long unsigned) wait_result, status);
			printf("Oh it's all better now \n");
		}
		
	}
	return (0);
}
