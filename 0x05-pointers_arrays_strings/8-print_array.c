#include <stdio.h>
/**
 * print_array - print n element of array
 * @a: int pointer to an array
 * @n: number o elements to print
 */
void print_array(int *a, int n)
{
	int i;

	for (i = 1; i < n && *a != '\0'; i++)
		printf("%i, ", *a++);
	printf("%i\n", *a);
}
