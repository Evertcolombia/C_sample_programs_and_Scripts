#include "hash_tables.h"

/**
 * This function will insert a new node o replace
 * a value if it's the case
 **/

int hash_table_set(hash_table_t *ht, const char *key, const char *value){
	unsigned long  int index;
	hash_node_t *new_node = NULL;

	if (ht == NULL || !key)
		return (0);

	printf("getting an index\n");
	index = key_index((unsigned char *) key, ht->size);
	printf("This is the index: %lu\n", index);

	if (ht->array[index] != NULL)
	{
		printf("the index is not empty\n\n");

		if (strcmp(key, ht->array[index]->key) == 0)
		{
			printf("there are a key with the same content\n");
			free(ht->array[index]->value);
			ht->array[index]->value = strdup(value);
			printf("free and set value\n\n");
			return (1);
		}
	}
	printf("are not a node in this index, or not is the same key\n");
	new_node = malloc(sizeof(hash_node_t));
	if (new_node == NULL)
		return (0);
	printf("create a node and set values\n");
	new_node->key = strdup(key);
	new_node->value = strdup(value);
	printf("node conection between index and node\n\n");
	new_node->next = ht->array[index];
	ht->array[index] = new_node;
	return (1);
}
