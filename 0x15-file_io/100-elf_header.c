#include <sys/stat.h>
#include <fcntl.h>
#include <sys/types.h>
#include <elf.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>


void is_ELF64(unsigned char *e_ident);

int main(int argc, char *argv[])
{
	int fd, numRead;
	Elf64_Ehdr *efl_h;

	if (argc != 2)
	{
		dprintf(STDERR_FILENO, "Usage: elf-header <ELF-file>\n");
		exit(97);
	}

	fd = open(argv[1], O_RDONLY | O_SYNC);
	if (fd == -1)
	{
		dprintf(STDERR_FILENO, "Cant Open File %s\n", argv[1]);
		exit(98);
	}

	efl_h = malloc(sizeof(Elf64_Ehdr));
	if (efl_h == NULL)
	{
		dprintf(STDERR_FILENO, "Cant use malloc\n");
		exit(100);
	}

	numRead = read(fd, efl_h, sizeof(efl_h));
	if (numRead == -1)
	{
		free(efl_h);
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", argv[1]);
		exit(99);
	}

	is_ELF64(efl_h->e_ident);


	return 0;
}

void is_ELF64(unsigned char *e_ident)
{
	/*printf("%s", (char *) e_ident);*/

	if (!strncmp((char *) e_ident, "\177ELF", 4))
		printf("ELF Header:\n");
	else
	{
		dprintf(STDERR_FILENO, "Error: ELF mismatch \n");
		exit(98);
	}
}
