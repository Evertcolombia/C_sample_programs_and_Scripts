#include "hash_tables.h"

hash_table_t *hash_table_create(unsigned long int size)
{
	hash_table_t *table = NULL;

	if (size < 1)
		return (NULL);

	/*
	 * Store memory ofr the array structure, a malloc can be
	 * expande after it was created
	 **/
	table = malloc(sizeof(hash_table_t));
	if (table == NULL)
		return (NULL);

	/**
	 * expand the array with the size as it's own size
	 * using the arry property n the new table
	 **/
	table->array = malloc(size * sizeof(hash_node_t *));
	if (table->array == NULL)
		return (NULL);
	/*memset will set the memory ofr each index of array i n 0
	 * 1-argument = the memory you want to set
	 * 2-argument = what yo want will fill the space
	 * 3-argument = size of the memory yo want store*/
	memset(table->array, 0, size * sizeof(hash_node_t *));

	table->size = size;

	return (table);
}
