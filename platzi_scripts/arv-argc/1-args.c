/* program that prints the number of arguments passed into it. */
#include <stdio.h>

/**
 * main - print n arg
 * @argc: arguments number
 * @argv: array call arg
 * Return: Success 0
 */
int main(int argc, char __attribute__((unused)) *argv[])
{
    int i = 0;
    
    while(i < argc - 1)
        i++;
    printf("%d\n", i);
}