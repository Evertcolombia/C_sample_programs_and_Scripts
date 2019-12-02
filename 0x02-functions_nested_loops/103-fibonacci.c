#include <stdio.h>

/**
 * main - Entry point
 *
 * return: 0 (on sucess)
 */
int main (void)
{
	unsigned long num_1 = 0, num_2 = 1, sum = 0, total = 0;
	int count;

	while (sum < 4000000)
	{
		sum = num_1 + num_2;
		num_1 = num_2;
		num_2 = sum;

		if (sum % 2 == 0)
			total += sum;
	}
	printf("%lu", total);
	putchar(10);
	return (0);
}
