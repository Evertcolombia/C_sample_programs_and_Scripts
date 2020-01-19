#include "hash_tables.h"
/**
 * This function is an specific good algorithm to create has using the key that will be  in the node_table 
 * always return a hash number
 **/
unsigned long int hash_djb2(const unsigned char *str)
{
	unsigned long int hash;
	int c;

	hash = 5381;

	while ((c = *str++))
	{
		hash = ((hash << 5) + hash) + c; /* hash + 33 + c*/
	}
	return (hash);
}
