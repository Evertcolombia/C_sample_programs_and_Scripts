/* program that prints its name, followed by a new line.*/

#include <stdio.h>

/**
 * main - print 0 argv
 * @argc: unused
 * @argv: array arguments call function 
 * Return: Success 0
 */
int main (int argc, char *argv[])
{
    int i =0;
    
    for (;i < argc; i++)
        printf("%s\n", argv[i]);
    return(0);
}