#include "holberton.h"
/**
 * _strspn - return total prefix of substring in string
 * @s: principal string
 * @accept: substring
 *
 * Return: count total
 */
unsigned int _strspn(char *s, char *accept)
{
	int count = 0;
	char *head = accept;

	while (*accept && *s && *s != 32)
	{
		if (*(accept + 1) == '\0')
		{
			if (*s == *accept)
				count++;
			accept = head, *s++;
			continue;
		}
		if (*s == *accept)
			count++;
		accept++;
	}
	return (count);
}
