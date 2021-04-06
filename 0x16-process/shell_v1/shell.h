#ifndef SHELL_H
#define SHELL_H

/*Allowed Libraries*/
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>
#include <stdbool.h>

extern char **environ;

void handleCtrlc(int i);
char *read_line(char *buffer);
char *line_buffer(char *buffer);
#endif /* SHELL_H */
