#include <stdlib.h>
#include <string.h>

#include "sort.h"
/**
 * insertion_sort - insert a node in a ordered list
 */

int insertion_sort(void *data, int size, int esize, int (*compare) (const void *key1, const void *key2))
{
	char *a = data;
	int i, j;
	void *key;

	/**
	 * allocate storage for the key element
	 */

	if ((key = malloc(esize)) == NULL)
		return (-1);

	/**
	 * repeteadly insert akey element among the sorted element
	 */
	for (j = 1; j < size; j++)
	{
		memcpy(key, &a[j * esize], esize);
		i = j - 1;
	
		/**
		 * determine the position a wicht to insert
		 * key element
		 */
		while (i >= 0 && compare(&a[i *  esize], key) > 0)
		{
			memcpy(&a[(i + 1) * esize], &a[i * esize], esize);
			i--;
		}
		memcpy(&a[(i + 1) * esize], key, esize)
	}

	/**
	 * free the storrage allocated for sortinng
	 */
	free(key);
	return (0);

