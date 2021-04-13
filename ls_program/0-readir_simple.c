#include <dirent.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>

static void listFiles(const char *dirpath)
{
	DIR *dirp;
	struct dirent *dp;
	/*bool isCurrent;*/	/* True if 'dirpath' is "." */

	/*isCurrent = strcmp(dirpath, ".") == 0;*/
	dirp = opendir(dirpath);
	if (dirp == NULL) {
		printf("error reading directory\n");
		return;
	}

	/* For each entry in this directory, print directory + filename */
	for (;;) {
		dp = readdir(dirp);
		if (dp == NULL)
			break;

		/*if (strcmp(dp->d_name, ".") == 0 || strcmp(dp->d_name, "..") == 0)
			continue;		*//* Skip . and .. */
	
		/*if (!isCurrent)
			printf("%s/", dirpath);*/
		printf("%s\n", dp->d_name);
	}

	if (closedir(dirp) == -1)
		return;
}

int main(int argc, char *argv[])
{
	if (argc > 1 && strcmp(argv[1], "--help") == 0)
		return (-1);

	if (argc == 1)
		listFiles(*argv);

	else
		for (argv++; *argv; argv++)
			listFiles(*argv);

	return(0);
}
