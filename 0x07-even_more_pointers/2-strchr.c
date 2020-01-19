#include "holberton.h"

int _strlen(char *s);

/**
 * this function looks for and specific char in a string
 *
 */
char *_strchr(char *s, char c)
{
	int len = _strlen(s);
	int i = 0;
	char *ch = '\0';

	while (i < len)
	{
		if (s[i] == c)
		{
			ch = &s[i];
			break;
		}
		i++;
	}
	return (ch);
}

/**
 * _strlen - show the lenght of a string
 * @s: pointe to  pass the array
 *
 * Return: none
 */

int _strlen(char *s)
{
        int a = 0;

        while (s[a])
                ++a;
        return (a);
}
