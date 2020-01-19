#include "hash_tables.h"
void hash_table_delete(hash_table_t *ht)
{
	unsigned int i = 0;
	hash_node_t *tmp = NULL, *tmp_del;

	if (ht == NULL)
		return;

	for (; i < ht->size; i++)
	{
		if (ht->array[i] != NULL)
		{
			tmp = ht->array[i];
			while (tmp != NULL)
			{
				tmp_del = tmp;
				tmp = tmp->next;
				free(tmp_del->key);
				free(tmp_del->value);
				free(tmp_del);
			}
		}
		continue;
	}
	free(ht->array);
	free(ht);
}
