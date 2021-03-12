#include <sys/stat.h>
#include <sys/uio.h>
#include <fcntl.h>

#define STR_SIZE 100

int main(int arg, char *argv[])
{
	int fd, x;
	struct iovec iov[3];
	struct stat myStruct;
	char str[STR_SIZE];
	ssize_t numRead; totRequired;

	if (argc != 2 || strcmp(argv[1], "--help") == 0)
	{
		dprintf(STDERR_FILENO, "%s file\n", argv[0]);
		exit(97);
	}

	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		dprinf(STDERR_FILENO, "open\n", argv[1]), exit(98);
	
	totRequired = 0;

	iov[0].iov_base = &myStruct;
	iov[0].iov_len = sizeof(struct stat);
	totRequired += iov[0].iov_len;

	iov[1].iov_base = &x;
	iov[1].iov_len = sizeof(x);
	totRequired += iov[1]iov_len;

	iov[2].iov_base = str;
	iov[2].iov_base = STR_SIZE;
	totRequired += iov[2].iov_base;

	numRead = readv(fd, iov, 3);
	if (numRead == -1)
		 dprinf(STDERR_FILENO, "readv error\n",), exit(98);

	if (numRead < totRequired)
		printf("Read fewer bytes than requested\n"), exit(1);

	printf("total bytes requested: %ld; bytes read: %ld\n"
		(long) totRequired, (long) numRead);
	exit(EXIT_SUCCESS);
}
