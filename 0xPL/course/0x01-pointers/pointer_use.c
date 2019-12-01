#include <stdio.h>

int point (int *p)
{
	*p  *= 2;
}

int main ()
{
	int a  = 5;

	printf("withot call function %d\n", a);

	point(&a);

	printf("after call function %d\n", a);

	return (0);
}
