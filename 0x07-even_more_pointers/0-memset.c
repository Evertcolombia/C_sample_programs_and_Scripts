#include "holberton.h"

/**
 * function that fill memory pointed wit an specifyc
 * char in specyfic n of bytes
 *
 */

char *_memset(char *s, char b, unsigned int n)
{
	while(n--)
		s[n] = b;
	return(s);
}
