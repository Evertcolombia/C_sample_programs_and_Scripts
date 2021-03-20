#include "holberton.h"
/**
 * _puts - write the conten of a string to stdout
 * @str: pointer to string
 *
 * Return: none
 */
void _puts(char *str)
{
	while (*str)
		_putchar(*str++);
	_putchar(10);
}
