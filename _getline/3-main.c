#include <stdio.h>
#include <stdlib.h>
#include "sort.h"
/**
 * main - Entry point
 *
 * Return: Always 0
 */
int main(void)
{
    int array[][2] = {{19, 3}, {48, 1}, {99, 4}, {71, 1}, {13, 4}, {52, 5}, {96, 7}, {73, 9}, {86, 2}, {7, 4}};
    size_t n = sizeof(array) / sizeof(array[0]);

    print_array(array, n);
    printf("\n");
    quick_sort(array, n);
    printf("\n");
    print_array(array, n);
    return (0);
}
