#define _BSD_SOURCE
#include <signal.h>

extern const char *const sys_siglist[];


#define _GNU_SOURCE
#include <string.h>

char *strsignal(int sig); /* Returns pointer to signal description string */

void psignal(int sig, const char *msg); /* print the sigtnal descriptor */
