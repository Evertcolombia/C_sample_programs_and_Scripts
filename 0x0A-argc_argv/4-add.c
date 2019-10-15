/* Write a program that adds positive numbers.

 * Print the result, followed by a new line
 * If no number is passed to the program, print 0, followed by a new line
 * If one of the number contains symbols that are not digits, print Error, followed by a new line, and return 1
 * You can assume that numbers and the addition of all the numbers can be stored in an int
 */

#include <string.h>
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
	char s[100];
	int sum = 0;
	char *c;

	argv++;
	while (--argc)
	{
		sprintf(s, "%d", atoi(*argv));
		c = s;
		if (strcmp(*argv, c))
		{
			printf("Error\n");
			return (1);
		}
		else
		{
			sum = sum + strtol(*argv, NULL, 10);
		}
		argv++;
	}
	printf("%d\n", sum);
	return (0);
}