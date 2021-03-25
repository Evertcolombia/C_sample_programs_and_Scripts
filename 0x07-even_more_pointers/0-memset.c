#include "holberton.h"

/**
 * _memset - fill memory to a char pointer
 * @s: pointer to fill
 * @b: selected char
 * @n: size
 *
 * Return: char pointer
 */

char *_memset(char *s, char b, unsigned int n)
{
	while (n--)
		*s++ = b;
	return (s);
}
