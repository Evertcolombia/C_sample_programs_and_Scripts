#include "holberton.h"

char *_strpbrk(char *s, char *accept)
{
	char *head = accept;;
	
	while (*accept && *s)
	{
		if (*(accept + 1) == '\0')
		{
			if (*s == *accept)
				return (s);
			s++, accept = head; 
			continue;
		}
		else if (*s == *accept)
			return (s);
		accept++;
	}
	return (0);
}
