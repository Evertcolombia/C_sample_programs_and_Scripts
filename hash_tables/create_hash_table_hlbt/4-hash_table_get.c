#include "hash_tables.h"

char *hash_table_get(const hash_table_t *ht, const char *key)
{
	/*function that retrieves a value associated with a key.*/
	unsigned long int index;

	/*test if ht is empty*/
	if (ht == NULL)
		return (NULL);

	/*hash th key and get an index*/
	index = key_index((unsigned char *) key, ht->size);

	/*if there are a node in this index
	 * return the value that is in ths key*/
	while(ht->array[index])
	{
		if (strcmp(key, ht->array[index]->key) == 0)
			return (ht->array[index]->value);
		ht->array[index] = ht->array[index]->next;
	}
	return (NULL);
}
