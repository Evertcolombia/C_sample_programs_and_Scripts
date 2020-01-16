#ifndef CHTBL_H
#define CHTBL_H

#include <stdlib.h>
#include <stdio.h>

#include "lists.h"

/**
 * Define a structure for chained hash tables
 **/

typedef struct CHTBL_ {
	int buckets; /*Number of buckets allocatedin the table*/

	/**
	 * Function pointer  h specifies a hash
	 * function for hashing keys
	 **/
	int (*h)(const void *key);

	/**
         * Function pointer match  specifies a defined
         * function to determine wheter two keys match
	 * it should return 1 in match and 0 on not match
         **/
	int (*match)(const void *key1, const void *key2);

	/**
         * Function pointer destroy (argument)
         * function to free dynamically memory
         **/
	void (*destroy)(void *data);

	int size;
	List *table;
} CHTbl;


/**********************
* Public interface    *
***********************/

int chtbl_init(CHTbl *hbtl, int buckets, int(*h)(const void *key), int (*match)(const void *key1, const void *key2), void(*destroy)(void *data));

void chbtl_destroy(CHTbl *hbtl);

int chbtl_insert(CHTbl *hbtl, const void *data);

int chbtl_remove(CHTbl *hbtl, void **data);

int chbtl_lookup(const CHTbl *hbtl, void **data);

#define chbtl_size(hbtl) (hbtl->size)

#endif
