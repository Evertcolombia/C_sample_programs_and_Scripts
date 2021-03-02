#include <sys/stat.h>
#include <fcntl.h>
#include <ctype.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/**
 * The  first  command-line  argument  to  this  program is the name of a file to beopened.
 * The remaining arguments specify I/O operations to be performed on thefile. 
 * Each  of  these  operations  consists  of  a  letter  followed  by  an  associated  value(with no separating space):
 * soffset: Seek to byte offset from the start of the file.
 * rlength:  Read  length  bytes  from  the  file,  starting  at  the  current  file  offset,  anddisplay them in text form.
 * Rlength:  Read  length  bytes  from  the  file,  starting  at  the  current  file  offset,  anddisplay them in hexadecimal.
 * wstr: Write the string of characters specified in str at the current file offset.
 */

int main (int argc, char *argv[])
{
	size_t len;
	off_t offset;
	mode_t filePerms;
	int fd, ap, j, openFlags;
	char *buf;
	ssize_t numRead, numWritten;

	if (argc < 3 || strcmp(argv[1], "--help") == 0)
	{
		dprintf(STDERR_FILENO, "%s file r<length>|R<length>|w<string>|s<offset>}\n", argv[0]);
		exit(97);
	}

	openFlags = O_RDWR | O_CREAT;
	filePerms = S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP |
		S_IROTH | S_IWOTH;

	fd = open(argv[1], openFlags, filePerms);
	if (fd == -1)
	{
		dprintf(STDERR_FILENO, "Cant Open File %s\n", argv[1]);
		exit(98);
	}

	for (ap = 2; ap < argc; ap++)
	{
		switch (argv[ap][0])
		{
			case 'r': /* Display bytes at current offset, as text */
			case 'R': /* Display bytes at current offset, in hex */
				len = getLong(&argv[ap][1], GN_ANY_BASE, argv[ap]);
				buf = malloc(len);
				if (buf == NULL)
					exit(98);
				numRead = read(fd, buf, len);
				if (numRead == -1)
					exit(98);
				
				if (numRead == 0)
				{
					printf("%s: end-of-file\n", argv[ap]);
				}
				else {
					printf("%s", argv[ap]);
					for (j = 0; j < numRead; j++)
					{
						if (argv[ap][0] == 'r')
							printf("%c", isprint((unsined char) buf[j]) ? buf[j] : '?');
						else
							printf("%02x ", (unsigned int) buf[j]);
					}
					printf("\n");
				}

				free(buf);
				break;
			case 'w': /* Write string at current offset */
				numWritten = write(fd, &argv[ap][1], strlen(argv[ap][1]));
				if (numWritten == -1)
				{
					dprintf(STDERR_FILENO, "Cant write to the file");
					exit(99);
				}
				printf("%s wrote %ld bytes \n", argv[ap], (long) numWritten);

				break;
			case 's': /* Change file offset */
				offset = getLong(&argv[ap][1], GN_ANY_BASE, argv[ap]);
				if (lseek(fd, offset, SEEK_SET) == -1)
				{
					dprintf(STDERR_FILENO, "error using lseek");
					exit(100);
				}
				printf("%s: seek succeeded\n", argv[ap]);
				break;
			default:
				dprintf(STDIN_FILENO, "Argument must start with [rRws]: %s\n", argv[ap]);
		}
	}
	
	exit(EXIT_SUCCESS);
}
