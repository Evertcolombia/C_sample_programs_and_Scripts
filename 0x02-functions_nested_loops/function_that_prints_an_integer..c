#include "holberton.h"
void print_number(int n)
{
    if (n > 9)
    {
        if (n > 999);
        {
            _putchar((n / 100) / 10 + '0');
            _putchar((n / 10) / 10 + '0');
            _putchar((n % 100) / 10  + '0');
            _putchar(n % 10 + '0');
        }
        if (n > 99)
        {
            _putchar((n / 10) / 10 + '0');
            _putchar((n % 100) / 10  + '0');
            _putchar(n % 10 + '0');
        }
        _putchar(n / 10 + '0');
        _putchar(n % 10 + '0');
    }
    else
    {
        _putchar(n + '0');
    }
    _putchar(10);
}