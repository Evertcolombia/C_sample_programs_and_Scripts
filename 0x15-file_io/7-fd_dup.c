/* The dup() call takes oldfd, an open file descriptor, and returns a new descriptor that
 refers to the same open file description. The new descriptor is guaranteed to be the
 lowest unused file descriptor. */
#include ?
#include <unistd.h>

int newfd;

/* Assuming the normal situation where the shell has opened file descriptors 0, 1, and
2 on the program’s behalf, and no other descriptors are in use, dup() will create the
duplicate of descriptor 1 using file 3. */
newfd = dup(1);

/* If we wanted the duplicate to be descriptor 2, we could use the following
 technique: */
close(2);
newfd = dup(1);

/* This code works only if descriptor 0 was open. To make the above code simpler,
 and to ensure we always get the file descriptor we want, we can use dup2() */

/* The dup2() system call makes a duplicate of the file descriptor given in oldfd using
 the descriptor number supplied in newfd. If the file descriptor specified in newfd is
 already open, dup2() closes it first. (Any error that occurs during this close is
 silently ignored; safer programming practice is to explicitly close() newfd if it is open
 before the call to dup2().)

 We could simplify the preceding calls to close() and dup() to the following:*/
dup2(1, 2);

/*  duplicate file descriptors share the same file
 offset value and status flags in their shared open file description. However, the new
 file descriptor has its own set of file descriptor flags, and its close-on-exec flag
 (FD_CLOEXEC) is always turned off. The interfaces that we describe next allow explicit
 control of the new file descriptor’s close-on-exec flag.
 The dup3() system call performs the same task as dup2(), but adds an additional
 argument, flags, that is a bit mask that modifies the behavior of the system call. */
dup3(2, 4, O_CLOEXEC);
