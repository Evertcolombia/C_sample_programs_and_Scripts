#include <stdio.h>

void main()
{
    int lower, q = 113, e = 101;

    for (lower = 97; lower <= 122; lower++)
    {
        if (lower != q && lower != e)
            putchar(lower);
    }        
    putchar(10);
}