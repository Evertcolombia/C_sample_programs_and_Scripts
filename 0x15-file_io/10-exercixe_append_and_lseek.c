#include <sys/stat.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <stdio.h>
#include <string.h>

int write_file(int fd, int fc);

int main(int argc, char *argv[])
{
	int fd, fc;
	/*off_t offset;*/

	if (argc != 3 || strcmp(argv[2], "--help") == 0)
		dprintf(STDERR_FILENO, "%s file\n", argv[0]), exit(98);

	
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	{
		dprintf(STDERR_FILENO, "Cant Open File %s\n", argv[1]);
		return (98);
	}

	fc = open(argv[2], O_RDWR | O_APPEND);
	if (fc == -1)
	{
		dprintf(STDERR_FILENO, "Cant Open File %s\n", argv[2]);
		return (98);
	}

	/*if ((offset = lseek(fc, 0, SEEK_SET)) == -1)
	{
		dprintf(STDERR_FILENO, "error using lseek\n");
		exit(100);
	}

	printf("%s: seek succeeded\n", argv[2]);*/
	write_file(fd, fc);
	return(0);	
}

int write_file(int fd, int fc)
{
	char buff[1024];
	ssize_t numRead;


	while ((numRead = read(fd, buff, 1024)) > 0);
	{
		printf("Sissaaaa");
		write(STDOUT_FILENO, buff, numRead);
		if (write(fc, buff, numRead) < 0)
		{
			 dprintf(STDERR_FILENO, "Error: Can't write to file\n");
			 exit(99);
		}
	}

	if (numRead == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't write to\n");
		exit(99);
	}

	if (close(fd) == -1 || close(fc) == -1)
		dprintf(STDERR_FILENO, "Error: Can't close fd");

	
	return (numRead);
}
