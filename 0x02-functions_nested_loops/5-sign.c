/*
 * Write a function that prints the sign of a number.
 *
 * Prototype: int print_sign(int n);
 * Returns 1 and prints + if n is greater than zero
 * Returns 0 and prints 0 if n is zero
 * Returns -1 and prints - if n is less than zero
 */

#include "holberton.h"

/**
 * print_sign - show a number and state
 * @n : data
 *
 * Return: Always (success)
 */
int print_sign(int n)
{
    int r = 0;

    if (n > 0)
    {
        _putchar(43);
        r = 1;
    }
    else if (n < 0)
    {
        _putchar(45);
        r = -1;
    }
    else
        _putchar(48);
    return(r);
        
}