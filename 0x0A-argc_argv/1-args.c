/*Write a program that prints the number of arguments passed into it.

Your program should print a number, followed by a new line*/

#include <stdio.h>

/**
 * main - print n arg
 * @argc: arguments number
 * @argv: array call arg
 * Return: Success 0
 */
int main(int argc, char __attribute__((unused)) *argv[])
{
	printf("%d\n", --argc);
	return (0);
}