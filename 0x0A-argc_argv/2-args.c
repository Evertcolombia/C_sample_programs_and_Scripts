/*Write a program that prints all arguments it receives.

All arguments should be printed, including the first one
Only print one argument per line, ending with a new line*/

#include <stdio.h>

/**
 * main - print all arg
 * @argc: count
 * @argv: array
 * Return: Success 0
 */
int main(int argc, char **argv)
{
	while (argc--)
		printf("%s\n", *argv++);
	return (0);
}