#include "header.h"
#include "lists.h"


int chtbl_init(CHTbl *htbl, int buckets, int (*h)(const void *key), int (*match)(const void *key1, const void *key2), void (*destroy)(void *data))
{
	int  i = 0;

	/**
	 * Allocate space for the hash table
	 **/

	htbl->table = (List *)malloc(buckets * sizeof(List));
	if (htbl->table == NULL)
		return (-1);

	/**
	 * Inizialite the buckets
	 **/
	htbl->buckets = buckets;

	for (; i < htbl->buckets; i++)
		list_init(&htbl->table[i], destroy);

	/**
	 * Encapsulate the functions
	 **/
	htbl->h = h;
	htbl->match = match;
	htbl->destroy = destroy;

	/**
	 * Inizialite the number of elements in the table
	 **/
	htbl->size = 0;

	return(0);
}
