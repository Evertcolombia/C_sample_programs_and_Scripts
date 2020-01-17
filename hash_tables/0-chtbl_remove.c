#include "header.h"
#include "lists.h"

int chtbl_remove(CHTbl *hbtl, void **data)
{
	ListElmt *element, *prev;
	int bucket = 0;

	/**
	 * Hash the key
	 **/
	bucket = hbtl->h(*data) % hbtl->buckets;

	
	/**
	 * Search for the data in the bucket
	 **/
	prev = NULL;
	
	for (element = list_head(&htbl->table[bucket]); element != NULL; element = list_next(element))
	{
		if (hbtl->match(*data, list_data(element)))
		{
			/**
			 * Remove the data from the bucket
			 **/
			if (list_rem_next(&htbl->table[bucket], prev, data) == 0)
			{
				htbl->size--;
				return (0);
			}
			else
				return (-1);
		}
	}
	prev = element;

	/**
	 * Return tha the data was not found
	 **/
	return (-1);
}
