/*Write a program that prints its name, followed by a new line.

If you rename the program, it will print the new name, without having to compile it again

You should not remove the path before the name of the program*/

#include <stdio.h>
/**
 * main - print 0 argv
 * @argc: unused
 * @argv: array arguments call function
 * Return: Success 0
 */
int main(int __attribute__((__unused__)) argc, char *argv[])
{
	printf("%s\n", argv[0]);
	return (0);
}