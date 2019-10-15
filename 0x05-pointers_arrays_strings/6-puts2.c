/*Write a function that prints every other character of a string, starting with the first character, followed by a new line.*/

#include "holberton.h"
/**
 * puts2 - puts
 * @str: string
 * Return: none
 */
void puts2(char *str)
{
    int i = 0, c;

    while (str[i])
        i++;
    for (c = 0; c <= i - 1; c++)
    {
        if (c % 2 == 0)
            _putchar(str[c]);
    }
    _putchar(10);
    
}