#include <stdio.h>

int main(void)
{
    char str[] = "Holberton";
    int  i = 0;
    while (str[i] != '\0')
    {
        putchar(str[i]);
        i++;
    }
    putchar(10);
    return (0);
}