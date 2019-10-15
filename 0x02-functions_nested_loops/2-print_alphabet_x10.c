#include <stdio.h>

void main(void)
{
    for (int i = 0; i < 10; i++)
    {
        for (int alpha = 97; alpha <= 122; alpha++)
            putchar(alpha);
        putchar(10);
    }        
}