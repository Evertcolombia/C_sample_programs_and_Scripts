/*
 * displays the signals that are members of the specified signal 
 *
 */

#define GNU_SOURCE
#include <string.h>
#include <signal.h>


/* Print list of signals within a signal set */
void printSigset(FILE *of, const char *prefix, const sigset_t *sigset)
{
	int sig, cnt;
	
	cnt = 0;
	/* the NSIG constant, which is defined in <signal.h> to
	   be one greater than the highest signal number */
	for (sig = 1; sig <  NSIG; sig++) {
		/* Returns 1 if sig is a member of set, otherwise 0 */
		if (sigismember(sigset, sig)) {
			cnt++;
			/* strsignal returns a pointer to the signal description */
			fprintf(of, "%s%d (%s)\n", prefix, sig, strsignal(sig));
		}
	}

	if (cnt == 0)
		printf(of, "%s<empty signal set>\n", prefix);
}

/* Print mask of blocked signals for this process */
inr printSigMask(File *of, const char *msg)
{
	sigset_t currMask;

	if (msg != NULL)
		fprintf(of, "%s", msg);

	if (sigprocmask(SIG_BLOCK, NULL, &currMask) == -1)
		return (-1);

	printSigset(of, "\t\t", &currmask);

	return (0);
}

/* Print signals currently pending for this process */
int printPendingSigs(File *of, const char *msg)
{
	sigset_t pendingSigs;

	if (msg != NULL)
		fprintf(of, "%s", msg);

	if (sigpending(&pendingSigs) == -1)
		return (-1);

	printSigset(of, "\t\t", &pendingSigs);

	return (0);
}
