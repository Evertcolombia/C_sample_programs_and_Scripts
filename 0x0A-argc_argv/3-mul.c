/* program that multiplies two numbers. */
#include <stdio.h>
#include <stdlib.h>

/**
 * main - multipli two arguments
 * @argc: arguments number
 * @argv: array call arg
 * Return: Success 0
 */
int main(int argc, char  *argv[])
{
    int a = 0, b = 0, mul = 0;
    
    if (argc != 3)
    {
        printf("Error\n"); 
        return(0);
    }
    
    a = strtol(argv[1], NULL, 10), b = strtol(argv[2], NULL, 10);
    
    mul = a * b;
    printf("%d\n", mul);
    
    return(0);
}