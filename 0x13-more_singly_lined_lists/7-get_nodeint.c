/*  function that returns the nth node of a listint_t linked list. */
#include <stdlib.h>
#include "lists.h"

/**
 * get_node_at_index - 
 * @head: linked list
 * @index: index value
 * 
 * Return: node or null
 */
listint_t *get_nodeint_at_index(listint_t *head, unsigned int index)
{
	listint_t *tmp; // pointer temporal node
	unsigned int i = 0; // counter

	tmp = head; // tmp pointer to head

	while (tmp != NULL) // loop into the list
	{
		if (index == i) // test if counter match with index
		{
			return(tmp); // return  temporal node
		}
		i++, tmp = tmp->next; // plus counter and next node
	}

	return (NULL); // if is no match return null
}