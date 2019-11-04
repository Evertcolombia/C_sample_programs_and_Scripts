/* function that adds a new node at the beginning of a listint_t list. */

#include <stdio.h>
#include <stdlib.h>
#include "lists.h"

/**
 * add_nodeint - add a new node at the beggin
 * head: double pointer
 * n: value
 * 
 * Return: new node
 */
listint_t *add_nodeint(listint_t **head, const int n)
{
	/* Intance of pointer to a new node*/
	listint_t *n_node;

	/* Storages memory for the new node */
	n_node = malloc(sizeof(listint_t));
	if (n_node == NULL)
		return (NULL);

	/* Set int value for the property in new node*/
	n_node->n = n;
	/* This node points to head , it means will points to the first
	   node in the list, for that this will be the first in the list*/
	n_node->next = *head;
	/* head is this node so is the first in the list now*/
	*head = n_node;

	return (n_node);
}
