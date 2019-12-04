#include "holberton.h"

char *_memcpy(char *dest, char *src, unsigned int n)
{
	unsigned int i = 0;

	/*if (src == NULL)
		return (NULL);*/
	while(i < n)
	{
		dest[i] = src[i];
		++i;
	}
	return(dest);
}
