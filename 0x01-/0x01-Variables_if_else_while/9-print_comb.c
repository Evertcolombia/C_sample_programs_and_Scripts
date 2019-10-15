#include <stdio.h>

void main()
{
    int num;

    for (num = 48; num <= 57; num++)
    {
        putchar(num);
        if (num != 57)
        {
            putchar(44);
            putchar(32);
        }
    }
    putchar(10);
}