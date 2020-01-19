#ifndef LIST_H
#define LIST_H

#include <stdlib.h>

/********************************************************
 *                                                      *
 *    Define a structure for lined list elements.       *
 *                                                      *   
 * ******************************************************/

typedef struct listElmt_ {
	void *data;
	struct listElmt_ *next;
} listElm;


/********************************************************
 *                                                      *
 *    Define a structure for linked list.               *
 *                                                      *
 * ******************************************************/

typedef struct list_  {
	int size;
	int (*match)(const void *key1, const void key2);
	void (*destroy)(void *data);
	listElm *head;
	listElm *tail;
} list;

/********************************************************
 *                                                      *
 * ----------------- Public interface. -----------------*
 *                                                      *
 * ******************************************************/

void list_init(list *list, void (*destroy) (void *data));
void list_destroy(list *list);
int list_ins_next(list *list, listElm *element, const void *data);
int list_rem_next(list *list, listElm *element, void **data);

#define list_size(list) ((list)->size)
#define list_head(list) ((list)->head)
#define list_tail(list) ((list)->tail)
#define list_is_head(list, element) ((element) == (list)->head ? 1 : 0)
#define list_is_tail(element) ((element)->next == NULL ? 1 : 0)
#define list_data(element) ((element)->data)
#define list_next (element) ((element)->next)

#endif
