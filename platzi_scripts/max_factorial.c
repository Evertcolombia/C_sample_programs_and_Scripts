#include <stdio.h>
#include <math.h>

/**
 * maxPrimeFactor - find the max prime factor of a number
 * @n: value
 * 
 * Return: value
 */

int maxPrimeFactor(int num)
{
    int i, max = -1;

    while (num % 2 == 0)
        num = num / 2, max = 2;

    for (i = 3; i <= sqrt(num); i += 2)
    {
        while (num % i == 0)
            num = num / i, max = i;
    }

    if (num > 2)
        max = num;
    return (max);
 
}

void main ()
{
    int n;
    
    n = 612852475143;
    printf("Max prime factor: %d", maxPrimeFactor(n));
    putchar(10);
}