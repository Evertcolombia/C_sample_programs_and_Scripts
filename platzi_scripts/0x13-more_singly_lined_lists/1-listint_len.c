#include <stdio.h>
#include "lists.h"

size_t listint_len(const listint_t *h)
{
	float tmp;

	while (h != NULL)
		tmp++, h = h->next;
	return (tmp);
}
