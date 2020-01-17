#include "header.h"
#include "lists.h"

int chtbl_insert(CHTbl *htbl, const void *data)
{
	void *tmp;
	int bucket = 0, retval = 0;

	/**
	 * Hash the key
	 **/
	bucket = htbl->h(data) % htbl->buckets;

	/**
	 * Insert the data into the bucket
	 **/
	retval = list_ins_next(&htbl->table[bucket], NULL, data);
	if (retval == 0)
		htbl->size++;

	return (retval);
}
