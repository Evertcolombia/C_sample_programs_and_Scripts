#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
	int fd;

	if (argc < 2)
	{
		printf("Not argumnets passed\n");
		return (-1);
	}
	fd = open(argv[1], O_WRONLY | O_CREAT);
	if (fd  == -1)
		return (-1);

	if (dup2(STDOUT_FILENO, fd) == -1)
	{
		perror("dup2");
		return (EXIT_FAILURE);
	}

	printf("aqui estamos\n");
	close(fd);
	return(1);
}
