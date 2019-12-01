#include <stdio.h>

/**
 * this function sums all the numbers that are multiples of 3 or 5
 *  and prints this sum
 */

int main (void)
{
	int sum = 0, i  = 0;

	for (i = 1; i < 1024; i++)
	{
		if (i % 3 == 0 || i % 5 == 0)
			sum += i;
	}

	printf("%d", sum), putchar(10);
	return (0);
}
