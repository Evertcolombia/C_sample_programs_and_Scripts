/**
 * Write a function that prints all natural numbers from n to 98, followed by a new line.Prototype: void print_to_98(int n);
 * Numbers must be separated by a comma, followed by a space
 * Numbers should be printed in order
 * The first printed number should be the number passed to your function
 * The last printed number should be 98
 * You are allowed to use the standard library
 */

#include <stdio.h>
#include <stdlib.h>
/**
 * print_to_98 - absoluted value
 * @n: value
 *
 * Return: absoluted.
 */
void print_to_98(int n)
{
    int num;

    if (n == 98)
        printf("%d", n);
    if (n < 98)
    {
        for (num = n; num <= 98; num++)
        {
            printf("%d", num);
            if (num != 98)
                putchar(44),putchar(32);   
        }
    }
    if (n > 98)
    {
        for (num = n; num >= 98; num--)
        {
            printf("%d", num);
            if (num != 98)
                putchar(44),putchar(32);
        }
    }
    putchar(10);
}