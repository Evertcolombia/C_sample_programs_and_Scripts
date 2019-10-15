/**
 * Write a function that prints the last digit of a number.
 * Prototype: int print_last_digit(int);
 * Returns the value of the last digit
 */

#include "holberton.h"
/**
 * print_last_digit - print last digit of a number
 * @n: value
 *
 * Return: on (success) 1
 */
int print_last_digit(int n)
{
    int res;

    res = n % 10;
    if (res < 0)
        res = res * -1;
    _putchar(res + '0');
    return (res);
}