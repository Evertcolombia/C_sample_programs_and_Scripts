/**
 * La funcion malloc asigna bytes de tamano y devuelve un puntero
 * a la memoria a signada
 * 
 * #include <stdilib.h>
 * void *malloc(size_t size);
 */

#include <stdio.h>
#include <stdlib.h>

int main (void)
{
    int n;
    char *ar;

    n = 5;
    ar = malloc(n * sizeof(char));
    ar [0] = 'C';
    ar [1] = 'o';
    ar [2] = 'o';
    ar [3] = 'l';
    ar [4] = '\n';
    printf ("%s\n", ar);
    return(0);
}