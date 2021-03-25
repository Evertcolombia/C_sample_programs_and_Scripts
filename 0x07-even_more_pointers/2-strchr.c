#include "holberton.h"

/**
 * _strchr - Returns the first ocurrence of char or null
 * @s: pointer to char
 * @c: char to compare
 *
 * Return: pointer to char or null
 */
char *_strchr(char *s, char c)
{
	while (*s++)
	{
		if (*s == c)
			return (s);
	}
	return ('\0');
}
