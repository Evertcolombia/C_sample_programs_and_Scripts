#include "header.h"
#include <stdio.h>

int main (int argc, char *argv[])
{
	int arc = argc;

	if (argc ==  1)
	{
		printf("ingrese cadenas de texto a ser comaparadas\n");
		return (1);
	}
	
	printLargestString(argc, argv);
	return (0);
}
