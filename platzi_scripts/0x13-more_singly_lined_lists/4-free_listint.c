/* function that frees a listint_t list. */
#include <stdlib.h>
#include "lists.h"

/**
 * free_listint - free a lined list
 * head: head of list
 * 
 * Return: none
 */
void free_listint(listint_t *head)
{
    listint_t *tmp; /* init a temporal node */

    /* while the list not end */
    while(head)
    {
        tmp = head; /* temporal node = head node */
        head = head->next; /* head node pass to pointer the next */
        free(tmp->n); /* free the values o the tmp node */
        free(tmp); /* free space for tmp node */
    }
    /* finally frees the head */
    free(head);
}