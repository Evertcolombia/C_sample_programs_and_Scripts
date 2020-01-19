#include "hash_tables.h"

/**
 * main - check the code for Holberton School students.
 *
 * Return: Always EXIT_SUCCESS.
 */
int main(void)
{
	hash_table_t *ht = NULL;

	/*Creat a table passing a size*/
	ht = hash_table_create(1024);
	/*See table address*/
	printf("%p\n", (void *)ht);
	return (EXIT_SUCCESS);
}
