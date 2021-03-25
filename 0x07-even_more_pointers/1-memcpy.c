#include "holberton.h"

/**
 * _memcpy - copy memory from src to dest
 * @dest: pointer to char
 * @src: pointer to char
 * @n: size
 *
 * Return: pointer to char
 */
char *_memcpy(char *dest, char *src, unsigned int n)
{
	while (n--)
		*dest++ = *src++;
	return (dest);
}
