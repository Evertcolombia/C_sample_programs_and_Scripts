#include <stdlib.h>
#include <string.h>
#include "0-list.h"

/*
 * Init the structure to control the linked list
 */
void list_init(list *list, void (*destroy), (void *data))
{
	list->size = 0;
	list->destroy = destroy;
	list->head = NULL;
	list->tail = NULL;
	
	return;
}

/*
 * Function to destroy a linked list
 */
void list_destroy(list *list)
{
	void *data;

	/*Remove each element*/
	while (list_size(list) > 0)
	{
		if(list_rem_next(list, NULL, (void **)&data) == 0 && list->destroy != NULL)
		{
			/*
			 * call a user-define function to free
			 * dynamically allocated data
			 */
			list->destroy(data);
		}
	}

	/*
	 * No operations are allowed now, but clear the structure
	 * as a precaution
	 */
	memset(list, 0, sizeof(list));
	return;
}

/*
 * Function to insert a new node
 */

int list_ins_next(list *list, listElm *elemet, const void *data)
{
	listElm *new_element;

	/*Allocate storage for the element*/
	if (new_element = malloc(sizeof(listElm) == NULL))
		return -1;

	/*Insert the data in th element into the list*/
	new_element->data = (void *)data;

	/*
	 * if the element = null handle inserction at the
	 * head of the list 
	 */
	if (element == NULL)
	{
		/*
		 * set the new node as the tail of the list if element
		 * argument is = to NULL
		 */
		if (list_size(list) == 0)
			list->tail = new_element;

		/*
		 * now do the conection between the head and
		 * the new node
		 */
		new_element->next = list->head;
		list->head = new_element;
	}
	else
	{
		/*
		 * handle inserction for somewhere other
		 * than at the end
		 */
		if (element->next == NULL)
			list->tail = new_element;

		new_element->next = element->next;
		element->next = new_element;
	}

	/*
	 * adjust the count of the list si<e for the
	 * inserted number
	 */
	list->size++;
	return (0);
}

int list_rem_next(list *list, listElm *element, void **data)
{
	listElm *old_element;

	/*Do not allow remove from an empty list*/
	if (list_size(list) == 0)
		return -1;

	/*Remove the element from the list*/
	if (element == NULL)
	{
		/*Handle removal from the head of the list*/
		*data = list->head->data;
		old_element = list->head;
		list->head = list->head->next;

		if(list_size(list) == 1)
			list->tail = NULL;
	}
	else
	{
		/*hande removal from somewhere other that the head*/
		if (element->next == NULL)
			return -1;
		*data = element->next->data;
		old_element = element->nex;
		element->next = element->next->next;

		if (element->next == NULL)
			list->tail = element;
	}

	/*Free the storage allocatedby the abstract datatype*/
	free(old_element);

	/*adjust the size of the list account*/
	list->size--;

	return (0);
}
