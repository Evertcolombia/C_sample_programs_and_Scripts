sigset_t blockSet, prevMask;

/* Initialize a signal set to contain SIGINT */
sigemptyset(&blockSet);
sigaddset(&blockSet, SIGINT);

/* Block SIGINT, save previous signal mask */
if (sigprocmask(SIG_BLOCK, &blockSet, &prevMask) == -1)
	printf("sigprocmask1");

/* ... Code that should not be interrupted by SIGINT ... */
printf("Here we are\n");

/* Restore previous signal mask, unblocking SIGINT */
if (sigprocmask(SIG_SETMASK, &prevMask, NULL) == -1)
	printf("sigprocmask2");

/* if we unblock a pending signal, it is delivered to the process immediately.
 * Attempts to block SIGKILL and SIGSTOP are silently ignored. If we attempt
   to block these signals, sigprocmask() neither honors the request nor
   generates an error
 */
sigfillset(&blockSet);
if (sigprocmask(SIG_BLOCK, &blockset, NULL) == -1)
	printf("sigprocmask2");

