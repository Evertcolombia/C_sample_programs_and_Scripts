/* Write a program that multiplies two numbers.
 *
 * Your program should print the result of the multiplication, followed by a new line
 * You can assume that the two numbers and result of the multiplication can be stored in an integer
 * If the program does not receive two arguments, your program should print Error, followed by a new line, and return 1
 */

#include <stdlib.h>
#include <stdio.h>
/**
 * main - mult two numbers
 * @argc: count arg
 * @argv: array arg
 * Return: Success 0, Error 1
 */
int main(int argc, char *argv[])
{
	int opr1, opr2;

	if (argc != 3)
	{
		printf("Error\n");
		return (1);
	}
	opr1 = strtol(argv[1], NULL, 10);
	opr2 = strtol(argv[2], NULL, 10);
	printf("%d\n", opr1 * opr2);
	return (0);
}