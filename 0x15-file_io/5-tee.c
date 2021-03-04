#include <sys/stat.h>
#include <fcntl.h>
#include <ctype.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*
 * The tee command reads its standard input until end-of-file, writing a copy of
   the input to standard output and to the file named in its command-line argument.
 
 * Implement tee using I/O system calls. By default, tee overwrites any existing
   file with the given name. Implement the –a command-line option (tee –a file),
   which causes te to append text to the end of a file if it already exists.
   (Refer to Appendix B for a description of the getopt() function,
   which can be used to parse command-line options.)
 *
 */

int main (int argc, char *argv[])
{
	off_t offset;
	int fd, fn;
	char buff[1024];
	ssize_t numRead;

	if (argc < 3 || strcmp(argv[1], "--help") == 0)
	{
		dprintf(STDERR_FILENO, "%s file_from file_to| -a <append>\n", argv[0]);
		exit(97);
	}

	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	{
		dprintf(STDERR_FILENO, "Cant Open File %s\n", argv[1]);
		exit(98);
	}
	
	if (argv[2] == "-a")
	{
		printf("hereee1");
		fn = open(argv[3], O_RDWR, O_TRUNC, O_APPEND);
		if (fn == -1)
		{
			printf("hereee");
			dprintf(STDERR_FILENO, "Cant Open File %s\n", argv[3]);
			exit(98);
		}
		
		if (lseek(fn, 0, SEEK_END) == -1)
			dprintf(STDERR_FILENO, "error using lseek"), exit(100);

		while((numRead = read(fd, buff, 1024)) > 0)
		{
			write(STDOUT_FILENO, buff, numRead);
			if (write(fn, buff, 1024) < 0)
			{
				dprintf(STDERR_FILENO, "Error: Can't write to %s\n", argv[3]);
				exit(99);
			}
		}
	}
	else
	{
		fn = open(argv[2], O_RDWR, O_TRUNC, O_APPEND);
		if (fn == -1)
		{
			dprintf(STDERR_FILENO, "Cant Open File %s\n", argv[2]);
			exit(98);
		
		}
		lseek(fn, 0, SEEK_SET);

		while((numRead = read(fd, buff, 1024)) > 0)
		{
			write(STDOUT_FILENO, buff, numRead);
			if (write(fn, buff, numRead) < 0)
			{
				dprintf(STDERR_FILENO, "Error: Can't write to %s\n", argv[2]);
				exit(99);
			}
		}
	}

	if (numRead == -1)
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", argv[1]), exit(98);
	if (close(fd) == -1)
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fd), exit(100);
	if (close(fn) == -1)
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fn), exit(100);

	return (1);
}
/*
int write_file(int fd, int fn)
{
	char buff[1024];
	ssize_t numRead;

	while ((numRead = read(fd, buff, 1024)) > 0)
	{
		write(STDOUT_FILENO, buff, numRead);
		if (write(fn, buff, numRead) < 0)
		{
			dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", from);
			exit(98);
		}
	}

	return numRead;
}*/
