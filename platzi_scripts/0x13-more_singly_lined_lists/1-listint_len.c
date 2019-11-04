/* function that returns the number of elements in a linked listint_t list. */
#include <stdio.h>
#include "lists.h"

/**
* add_nodeint - counts the number of nodes
 * head: double pointer
 * n: value
 * 
 * Return: node counter
 */
size_t listint_len(const listint_t *h)
{
	float tmp;

	while (h != NULL)
		tmp++, h = h->next;
	return (tmp);
}
