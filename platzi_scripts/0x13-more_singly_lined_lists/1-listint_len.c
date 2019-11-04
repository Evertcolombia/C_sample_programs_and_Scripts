/* function that returns the number of elements in a linked listint_t list. */
#include <stdio.h>
#include "lists.h"

/**
* alistint_len - counts the length of list
 * head: double pointer
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
