#include "holberton.h"

unsigned int _strspn(char *s, char *accept)
{
	unsigned int count = 0, i = 0, b = 0;

	while (s[b] != 32)
	{
		while (accept[i] != '\0')
		{
			if (s[b] == accept[i])
				count ++;
			i++;
		}
		b++;
	}
	return (count);
}
