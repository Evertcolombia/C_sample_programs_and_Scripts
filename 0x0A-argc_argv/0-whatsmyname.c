/* program that prints its name, followed by a new line.*/

#include <stdio.h>

/**
 * main - print 0 argv
 * @argc: unused
 * @argv: array arguments call function
 * Return: Success 0
 */
int main(int __attribute__((unused)) argc, char *argv[])
{
	printf("%s\n", argv[0]);
	return (0);
}
