/* function that prints all the elements of a listint_t list.*/

#include <stdio.h>
#include "lists.h"

/**
* print_listint - prints elements of nodes
 * head: header of the list
 * 
 * Return: node counter
 */
size_t print_listint(const listint_t *h)
{
    float tmp;

    while (h != NULL)
    {
        printf("%d\n", h->n);
        tmp++, h = h->next;
    } return (tmp);
}