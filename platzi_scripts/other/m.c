#include "3-calc.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * main - calculator main
 * @argc: number arguments
 * @argv: array arguments
 * Return: success (integer)
 */
int main(int argc, char *argv[])
{
	int result;
	int (*ptr)(int, int);

	if (argc != 4)
		return (__RETURN__(98));

	if (atoi(argv[3]) == 0 && (*argv[2] == '%' || *argv[2] == '/'))
		return (__RETURN__(100));

	ptr = get_op_func(argv[2]);

	if (ptr == NULL)
		return (__RETURN__(99));

	result = ptr(atoi(argv[1]), atoi(argv[3]));
	printf("%d\n", result);
	return (0);
}