/**
 * Write a function that prints the n times table, starting with 0.
 * Prototype: void print_times_table(int n)
 * If n is greater than 15 or less than 0 the function should not print anything
 */

#include "holberton.h"

/**
 * times_table - prints tables 9 times
 *
 * return: none
 */

void print_times_table(int n)
{
    int mul, count, res;
    if (n <= 15 && n >= 0)
    {
        for (mul = 0; mul <= n; mul++)
        {
            for (count = 0; count <= n; count++)
            {
                res = mul * count;
                if (res > 9)
                {
                    if (res > 99)
                    {
                        _putchar(32), _putchar((res / 10) / 10 + '0');
                        _putchar((res % 100) / 10 + '0'), _putchar(res % 10 + '0'); 
                    }
                    else
                    {
                        _putchar(32), _putchar(32);
                        _putchar(res / 10 + '0'), _putchar(res % 10 + '0');
                    }
                }
                else
                {
                    if (count != 0)
                    {
                        _putchar(32), _putchar(32), _putchar(32);
                    }    
                    _putchar(res + '0');
                }

                if (count != n)
                    _putchar(44);
            }
            _putchar(10);
        }
    }
}