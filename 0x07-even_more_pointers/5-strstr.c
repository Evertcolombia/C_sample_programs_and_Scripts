#include "holberton.h"

/**
 * _strstr - search for a substring in a string
 * @haystack: pointer to char
 * @needle: pointer to char substring
 *
 * Return: pointet to substring or none
 */
char *_strstr(char *haystack, char *needle)
{
	char *head = needle, *mov, *end, *init;
	int nlen = 0;

	mov = end = head;
	while (*haystack && *needle)
	{
		if (*(needle + 1) == '\0')
		{
			if (*needle == *haystack)
				end = needle;
			if (mov != head && end != head)
			{
				nlen =  end - head;
				if (*(head + (nlen - 1)) == *mov && *(mov + 1 - nlen) == *head)
					return (init);
			}
				haystack++, needle = head;
				continue;
		}
		if (*needle == *haystack)
		{
			if (needle == head)
				init = haystack;
			mov = needle, haystack++;
		}
		needle++;
	}
	return (0);
}
