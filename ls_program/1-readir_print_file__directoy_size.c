#include <dirent.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>

static void displayStatinfo(const char *pathname);

static void listFiles(const char *dirpath)
{
	DIR *dirp;
	struct dirent *dp;
	char *buffer;

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
		/*printf("%s\n", dp->d_name);*/
		if (strcmp(dp->d_name, "..") == 0) {
			buffer = (char *) malloc(strlen(dp->d_name) * sizeof(char));
			if (!buffer)
				return;
			buffer = strcpy(buffer, dp->d_name);
		}
		printf("%s ", dp->d_name);
		displayStatinfo(buffer);
	}

	if (closedir(dirp) == -1)
		return;
}

static void displayStatinfo(const char *pathname)
{
	struct stat sb;

	if (lstat(pathname, &sb) == -1) {
		printf("error on lstat()\n");
		return;
	}
	printf("%lld bytes\n", (long long) sb.st_size);
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
