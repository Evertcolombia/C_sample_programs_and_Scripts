#include <dirent.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>

static void displayStatinfo(const char *pathname, bool isFree);

static void listFiles(const char *dirpath)
{
	DIR *dirp;
	struct dirent *dp;
	char *buffer;
	int len = 0;

	/*bool isCurrent;*/	/* True if 'dirpath' is "." */

	/*isCurrent = strcmp(dirpath, ".") == 0;*/
	printf("%s\n", dirpath);
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
		
		if (strcmp(dirpath, ".") == 0) {
			printf("%s ", dp->d_name);
			displayStatinfo(dp->d_name, false);
		}
		else {
			len = 1 + strlen(dirpath) + strlen(dp->d_name);
			buffer = (char *) malloc(len * sizeof(char));
			if (!buffer)
				return;

			buffer = strcpy(buffer, dirpath);
			buffer = strcat(buffer, dp->d_name);
			printf("%s ", dp->d_name);
			displayStatinfo(buffer, true);
		}
	}

	if (closedir(dirp) == -1)
		return;
}

static void displayStatinfo(const char *pathname, bool isFree)
{
	struct stat sb;

	if (lstat(pathname, &sb) == -1) {
		printf("error on lstat()\n");
		return;
	}
	printf("%lld\n", (long long) sb.st_size);
	if (isFree)
		free((char *)pathname);
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
