#include <stdio.h>
#include "lists.h"

size_t print_listint(const listint_t *h)
{
    float tmp;

    while (h != NULL)
    {
        printf("%d\n", h->n);
        tmp++, h = h->next;
    } return (tmp);
}