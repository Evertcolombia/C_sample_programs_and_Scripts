#ifndef DLIST_H
#define DLIST_H

#include <stdlib.h>

/********************************************************
 *                                                      *
 *  Define a structure for double linked list elements. *
 *                                                      *
 * ******************************************************/

typdef struct DlistElm {
	void *data;
	struct Dlist *prev;
	struct Dlist *next;

} dlist;

/********************************************************
 *                                                      *
 *    Define a structure for double linked list.        *
 *                                                      *
 * ******************************************************/

typedef struct list {
	int size;
	int (*match)(const void *key1, const void *key2);
	void (*destroy) (void *data);
	dlist *head;
	dlist *tail;
} list;

/********************************************************
 *                                                      *
 * ----------------- Public interface. -----------------*
 *                                                      *
 * ******************************************************/

void dlist_init(list *list, void (*destroy) (void*data));
void dlist_destroy(list *list);
int dlist_ins_next(list *list, dlist *element, const void *data);
int dlist_ins_prev(list *list, dlist *element, const void *data);
int dlist_remove(list *list,dlist *element, void **data);

#define dlist_size(list) ((list)->size)
#define dlist_head(list) ((list)->head)
#define dlist_tail(list) ((list)->tail)
#define dlist_is_head(element) (element->prev == NULL ? 1 : 0)
#define dlist_is_tail(element) (element->next == NULL ? 1 : 0)
#define dlist_data(element) ((element)->data)
#define dlist_next(element) ((element)->next)
#define dlist_prev(element) ((element)->prev)

#endif
