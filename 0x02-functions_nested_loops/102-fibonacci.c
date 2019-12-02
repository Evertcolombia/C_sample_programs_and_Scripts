#include <stdio.h>

/**
 * this function will prints all the fibonacci numbers till 50
 */

int main (void)
{
	unsigned long fi_1 = 0, fi_2 = 1, sum = 0;
	int count;

	for (count = 0; count < 50; count++)
	{
		sum = fi_1 + fi_2;
		fi_1 = fi_2;
		fi_2 = sum;

		printf("%lu", sum);
		
		if (count != 49)
			putchar(44), putchar(32);
	}
	putchar(10);
	return (0);
}
