/*
 *
 The mkstemp() function generates a unique filename based on a template
 supplied by the caller and opens the file, returning a file descriptor that
 can be used with I/O system calls

 The mkstemp() function creates the file with read and write permissions for the
 file owner (and no permissions for other users), and opens it with the O_EXCL flag,
 guaranteeing that the caller has exclusive access to the file.
 */
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>

int main(int argc, char *argv[])
{

	int fd;
	char template[] = "/tmp/somestringXXX";


	fd = mkstemp(template);
	if (fd == -1)
		return (-1);

	printf("Generated filename was: %s\n", template);
	unlink(temlate);			/* Name disappears immediately, but the file
					    is removed only after close() */

	/* Use fi9le I/O system calls - read(), write(), and so on */
	if (close(fd) == -1)
		errExit("Close");
}
