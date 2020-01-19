#include "hash_tables.h"

unsigned long int key_index(const unsigned char *key, unsigned long int size)
{
	/**
	 * With tis operation we will be a do an operation
	 * called hashing the key
	 * With this the return is the index that the
	 * hashng operation bring to us
	 **/
	return (hash_djb2(key) % size);
}
