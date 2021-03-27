/* program that prints all arguments it receives. */
#include <stdio.h>

/**
 * main - print  arguments
 * @argc: arguments number
 * @argv: array call arg
 * Return: Success 0
 */
int main(int argc, char  *argv[])
{
	while (argc-- > 0)
		printf("%s\n", *argv++);
}
