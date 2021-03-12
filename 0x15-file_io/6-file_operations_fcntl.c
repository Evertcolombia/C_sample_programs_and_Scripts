#include <fcntl.h>

/* One use of fcntl() is to retrieve or modify the access mode and open file status flags
 of an open file. (These are the values set by the flags argument specified in the call
 to open().) To retrieve these settings, we specify cmd as F_GETFL:*/

int flags, accessMode;

flags = fcntl(fd, F_GETFL);
if (flags == -1)
	errExit("fcntl");

/* Test the flags in the file */
if (flags &  O_SYNC)
	printf("writes are synchronized\n");

/* Check access mode of the file */
accessMode = flags & O_ACCMODE;
if (accessMode == O_WRONLY || accessMode == O_RDWR)
	printf("file is writable\n");

/* We can use the fcntl() F_SETFL command to modify some of the open file status flags.
 The flags that can be modified are O_APPEND, O_NONBLOCK, O_NOATIME, O_ASYNC, and
 O_DIRECT. Attempts to modify other flags are ignored*/

/* modify the bits we wish to change, in this case, enable O_APPEND flag */
flags = |= O_APPEND;
/* to update the flags */
if (fcntl(fd, F_SETFL, flags) == -1)
	errExit("fcntl");

/* A further interface that provides some extra flexibility for duplicating file
   descriptors is the fcntl() F_DUPFD operation:

   This call makes a duplicate of oldfd by using the lowest unused file descriptor
   greater than or equal to startfd. This is useful if we want a guarantee that the new
   descriptor (newfd) falls in a certain range of values */

newfd = fcntl(oldfd, F_DUPFD, startfd);
