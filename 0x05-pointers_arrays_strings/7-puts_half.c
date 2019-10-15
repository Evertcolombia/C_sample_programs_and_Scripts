#include "holberton.h"

/**
 * puts_half - puts half string
 * @str: string
 * Return: none
 */
void puts_half(char *str)
{
    int i = 0, l, c;

    while (str[i])
        i++;
    l = i - 1;
    for (c = 0; c <= l; c++)
    {
        if (c > (l / 2))
            _putchar(str[c]);
    }
    _putchar(10);
}