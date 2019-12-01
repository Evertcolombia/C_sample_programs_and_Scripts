#include <stdio.h>

int mul (int *p)
{
	*p *= 2;
}
int main ()
{
	int number;
	int *res;

	printf("put a number\n");
	scanf("%d", &number);

	*res = mul(&number);

	printf("did you type the number: %d\n", number);
}
