/* function that adds a new node at the end of a listint_t list. */

#include <stdio.h>
#include <stdlib.h>
#include "lists.h"

/**
 * add_nodeint_end - add nodes at the end of the liist
 * head: double pointer to the head list
 * n: value
 * 
 * Return: last node of the list
 */
listint_t *add_nodeint_end(listint_t **head, const int n)
{
    /* init two new nodes one temp and otrhe for the last node
    of the list */
    /* the temporal node will point to the head, it mans also
        point the firs node of the list */
    /* the last node will be the last node of the list */
    listint_t *last_node;
    listint_t *tmp_node = *head;

    if (head == NULL)
        return (NULL);

    /* Create memory location for the last node */
    last_node = malloc(sizeof(listint_t));
    if (last_node == NULL)
        return (NULL);
    /* Set data for the last node, it means last
        will have NULL on the next property */
    last_node->n = n, last_node->next = NULL;

    /* If the list is empty, head will point to last node
        and return that last node, now our list will have
        one node */
    if (*head == NULL)
    {
        *head = last_node;
        return (last_node);
    }

    /* while our temp node that points at head 
        if it have a node
        do if have a node,  uptade that node to have
        an next property and not null */
    while (tmp_node->next != NULL)
        tmp_node = tmp_node->next; 

    /* Now that this node have next property, set up it
        pointer to our last_node*/
    tmp_node->next = last_node;
    
    return (last_node);
}