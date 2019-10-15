/*Write a function that prints a string, followed by a new line, to stdout.*/

#include "holberton.h"
/**
 * print_rev - put a string in reverse
 * @s: pointer to the argument string
 *
 * Return: none
 */
void print_rev(char *s)
{
    int c, i;

    while (s[i])
        ++i;

    for (c = i; c >= 0; c--)
        _putchar(s[c]);
    _putchar(10);
}
