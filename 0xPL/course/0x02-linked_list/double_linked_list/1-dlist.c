#include "dlist.h"

void dlist_init(list *list, void (*destroy)(void *data))
{
	/*Inicialite the list*/
	list->size = 0;
	list->destroy = destroy;
	list->head = NULL;
	list->prev = NULL;
	
	return;
}

/*Function to deestroy a double list*/
void dlist_destroy(list *list)
{
	void *data;

	/*Remove each element*/
	while (dlist_size(list) > 0)
	{
		if(dlist_remove(list, dlist_tail(list), (void **)&data) == 0 && list->destroy != NULL)
		{
			/*
		 	* calle a user defined function to fee 
			* dinamycally allocated data
		 	*/
			list->destroy(data);
		}	
	}

	/*clear the structure for precausion*/
	memset(list, 0, sizeof(list));

	return (0);

}

/*function to insert an element in a double lined list*/
int dlist_ins_next(list *list, dlist *element, const void *data)
{
	dlist *new_element;

	/*do not allow a NULL element unless the list is empty*/
	if (element == NULL && dlist_size(list) != 0)
		return (-1);
	
	/*allocate storage for the element*/
	if ((new_element = malloc(sizeof(element))) == NULL)
		return -1;
	
	/*Insert the new element into the list*/
	new_element->data =  (void *)data;

	
	if(dlist_size(list) == 0)
	{
		/*handle nserction when the list is empty*/
		list->head = new_element;
		list->head->prev = NULL;
		list->head->next = NULL;
		list->tail = new_element;
	}
	else
	{
		/*handle inserction when the list isnt empty*/
		new_element->next = element->next;
		new_element->prev = element;

		if (element->next == NULL)
			list-tail = new_element;
		else
			element->next->prev = new_element;
		element->next = new_element;
	}

	/*adust the list count for the inserted node*/
	list->size++;

	return (0);
}

/*function to insert an element in a prev position*/
int dlist_ins_prev(list *list, dlist *element, const void *data)
{
	dlist *new_element;

	/*Do not a null element unless the list is empty*/
	if (element == NULL) && dlist_size(list) != 0
		return (-1);

	/*allocate memory for new element*/
	if (new_element = malloc(sizeof(element)) == NULL)
		return (-1);

	/*insert the new element into the list*/
	new_element->data = (void *)data;

	if (dlist_size(list) == 0)
	{
		/*handle inserction when the lst is empty*/
		list->head = new_element;
		list->head->prev = NULL;
		list->head->next = NULL;
		list->tail = new_element;
	}
	else
	{
		/*handle inserction when the list isnt empty*/
		new_element->next = element;
		new_element->prev = element->prev;
		
		if (element->prev == NULL
			list->head = new_element;
		else
			element->prev->next = new_element;
		element->prev = new_element;)
	}

	/*adjust the size of the list count*/
	list->size++;

	return (0);
}

/*function to  remove and element*/
int dlist_remove(list *list, dlist *element, void **data)
{
	/*
	 * Do not a null element or removal from
	 * and empty list
	 */
	if (element == NULL && dlist_size(list) == 0)
		return (-1);

	/*Remove the element from the list*/
	*data = element->data;

	if (element == list->head)
	{
		/*handle removal from the head of the list*/
		list->head = element->next;

		if (list->head == NULL)
			list->tail = NULL;
		else
			element->next->prev = element->prev;
	}
	else
	{
		/*handle removal from other than head of the list*/
		element->prev->next = element->next;

		if (element->next == NULL)
			list->tail = element->prev;
		else
			element->next->prev = element->prev;
	}

	/*free the storage allocate by the abstract datatype*/
	free(elment);

	/*adust the size of the list counter*/
	list->size--;

	return (0);
}
