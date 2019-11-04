/* program that prints all arguments it receives. */
#include <stdio.h>

/**
 * main - print  arguments
 * @argc: arguments number
 * @argv: array call arg
 * Return: Success 0
 */
int main(int argc, char  *argv[])
{
    int i = 0;
    
    for(;i < argc; i++)
        printf("%s\n", argv[i]);
    return(0);
}