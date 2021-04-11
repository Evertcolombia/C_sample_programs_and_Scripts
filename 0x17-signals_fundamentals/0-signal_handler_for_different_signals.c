#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

/* When the kernel invokes a signal handler, it passes the number of the
   signal that caused the invocation as an integer argument to the handler.
   (This is the sig argument)

 * We can, establish the same handler to catch different types of signals
   and use this argument to determine which signal caused the handler to
   be invoked.
 */
static void sigHandler(int sig)
{
	static int count = 0;

	/* UNSAFE: This handler uses non-async-signal-safe functions 
	   (printf(), exit()); */
	
	if (sig == SIGINT) {
		count++;
		printf("Caught SIGINT (%d)\n", count);
		return;		/* Resume execution at point of interruption */
	}

	/* Must be SIGQUIT - print a message and terminate the process */
	printf("Caught SIGTSTP - that's all folks!\n");
	exit(EXIT_SUCCESS);
}

int main(int argc, char *argv[])
{
	(void) argc;
	(void) argv;

	/* Establish same handler for SIGINT and SIGQUIT */
	if (signal(SIGINT, sigHandler) == SIG_ERR) {
		printf("error in signal SIGINT\n");
		exit(0);
	}

	if (signal(SIGTSTP, sigHandler) == SIG_ERR) {
		printf("error in signal SIGQUIT\n");
		exit(0);
	}

	for (;;)		/* Loop forever, waiting for signals */
		pause();	/* Block until a signal is caught */
}
