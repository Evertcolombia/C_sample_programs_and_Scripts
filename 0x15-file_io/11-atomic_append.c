#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

/*
 * This exercise is designed to demonstrate why the atomicity guaranteed by opening
   a file with the O_APPEND flag is necessary. Write a program that takes up to three
   command-line arguments:
 	$ atomic_append filename num-bytes [x]
 */ 
int main(int argc, char *argv[])
{
	int fd, num_bytes, i;
	mode_t filePerms;
	
	if (argc < 3 || atoi(argv[2]) == 0)
		dprintf(STDERR_FILENO, "Usage: %s num_bytes\n", argv[0]), exit(99);

	num_bytes = atoi(argv[2]);
	filePerms =  S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH | S_IWOTH;

	if (argc == 3)
	{
		fd = open(argv[1], O_CREAT | O_WRONLY | O_APPEND, filePerms);
		if (fd == -1)
		{
			dprintf(STDERR_FILENO, "Cant Open File %s\n", argv[1]);
			exit(97);
		}

		for (i = 0; i < num_bytes; i++)
		{
			if (write(fd, 0, 1) < 1)
			{
				dprintf(STDERR_FILENO, "Error: Can't write to file\n");
				exit(98);
			}
		}

	}
	else if (argc == 4 && strcmp(argv[3], "x") == 0)
	{
		fd = open(argv[1], O_CREAT | O_RDWR, filePerms);
		if (fd == -1)
		{
			dprintf(STDERR_FILENO, "Cant Open File %s\n", argv[1]);
			exit(97);
		}
		for (i = 0; i < num_bytes; i++)
		{
			if (lseek(fd, 0, SEEK_END) == -1)
			{
				dprintf(STDERR_FILENO, "error using lseek\n");
				exit(100);
			}
			if (write(fd, 0, 1) < 1)
			{
				dprintf(STDERR_FILENO, "Error: Can't write to file\n");
				exit(98);
			}
		}
	}
}
