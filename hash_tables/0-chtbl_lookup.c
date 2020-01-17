#include "header.h"
#include "lists.h"

int chbtl_lookup(const CHTbl *hbtl, void **data)
{
	ListElmt *element;
	int bucket = 0;

	/**
	 * hash the key
	 **/
	bucket = hbtl->h(*data) % hbtl->buckets;

	
	/**
	 * Search for the data in the bucket
	 **/
	for (element = list_head(&hbtl->table[bucket]); element != NULL; element = list_next(element))
	{
		if (hbtl->match(*data, list_data(element)))
		{
			/**
			 * Pass back the data from the table
			 **/
			*data = list_data(element);
			return (0);
		}
	}

	/**
	 * return that the data was not found
	 **/
	return (-1);
}
	
