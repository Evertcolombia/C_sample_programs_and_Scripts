#include <stdio.h>
#include <signal.h>

int main(int argc, char *argv[])
{
	int numSigs, sig, j;
	pid_t pid;

	if (argc < 4 || strcmp(argv[1], "--help") == 0) {
		printf("%s pid num-sigs sig-num [sig-num-2]\n", argv[0]);
		return (-1);	 
	}

	pid = getLong(argv[1], 0, "PID");
	numSigs = getInt(argv[2], GN_GT_0, "num-sigs");

	/* Send signals to receiver */
	printf("%s: sending signal %d to process %ld %d times\n",
			argv[0], sig, (long) pid, numSigs);

	for (j = 0;  j < numSigs; j++) {
		if (kill(pid, sig) == -1) {
			printf("error kill");
			return (-1);
		}
	}

	/* If a fourth command-line argument was specified, send that signal */
	if (argc > 4) {
		if (kill(pid, getInt(argv[4], 0, "sig-num-2")) == -1) {
			printf("erro KIll");
			return (-1);
		}
	}
}
