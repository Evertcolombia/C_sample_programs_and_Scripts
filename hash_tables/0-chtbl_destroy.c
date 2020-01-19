#include "header.h"
#include "list.h"

void chtbl_destroy(CHTbl *htbl)
{
	int i = 0;

	/**
	 * Destroy each bucket
	 **/
	for (; i < htbl->buckets; i++)
		list_destroy(&htbl->table[i]);


	/**
	 * Free storage allocate in the hash table
	 **/
	free(htbl->table);

	/**
	 * No operations are allowed now, but clear the
	 * Structure as a precaution
	 **/
	memset(htbl, 0, sizeof(CHTbl));

	return;
}
