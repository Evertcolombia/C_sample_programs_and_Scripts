#ifndef HASH_TABLE
#define HASH_TABLE

/*sys call libraries*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>


/*hash node structure for each node in the buckets*/
typedef struct hash_node_s
{
	char *key;
	char *value;
	struct hash_node_s *next;
} hash_node_t;

/*hash_table array asociative*/
typedef struct hash_table_s
{
	unsigned long int size;
	hash_node_t **array;
} hash_table_t;

/*Prototypes*/
hash_table_t *hash_table_create(unsigned long int size);
unsigned long int hash_djb2(const unsigned char *str);
unsigned long int key_index(const unsigned char *key, unsigned long int size);

#endif /*HASH__TABLE*/
