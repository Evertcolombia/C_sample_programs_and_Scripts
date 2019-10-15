#include <stdio.h>

void main()
{
    int lower, upper;

    for (lower = 97; lower <= 122; lower++)
        putchar(lower);
    for (upper = 65; upper <= 90; upper++)
        putchar(upper);
    putchar(10);
}