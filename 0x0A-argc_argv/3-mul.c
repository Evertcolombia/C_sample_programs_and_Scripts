/* program that multiplies two numbers. */
#include <stdio.h>
#include <stdlib.h>

/**
 * main - multipli two arguments
 * @argc: arguments number
 * @argv: array call arg
 * Return: Success 0
 */
int main(int argc, char  *argv[])
{
	if (argc != 3)
		printf("Error\n");
	else
		printf("%ld\n", strtol(argv[1], NULL, 10) * strtol(argv[2], NULL, 10));
	return (0);
}
