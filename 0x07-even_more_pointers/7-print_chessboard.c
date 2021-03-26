#include "holberton.h"
#include <stdio.h>

/**
 * print_chessboard - print some like his name
 * @a: pointer to array of pointers
 *
 * Return: None
 */
void print_chessboard(char (*a)[8])
{
	int n = 0, i = 0;

	while (n < 8 && i < 8)
	{
		_putchar(a[i][n]);

		if (n == 7)
		{
			_putchar('\n'), n = 0, i++;
			continue;
		}
		n++;
	}
}
