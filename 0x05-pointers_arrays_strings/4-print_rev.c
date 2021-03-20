/*Write a function that prints a string, followed by a new line, to stdout.*/

#include "holberton.h"
/**
 * print_rev - put a string in reverse
 * @s: pointer to the argument string
 *
 * Return: none
 */
void print_rev(char *s)
{
    /*int c, i;*/
	int len;

	for (len = 1; *s != '\0'; s++)
		len++;

	while (len--)
		_putchar(*s--);
	_putchar(10);
}
