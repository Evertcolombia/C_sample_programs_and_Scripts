/* function that frees a listint_t list. with double pointers */
#include <stdlib.h>
#include "lists.h"

/**
 * free_listint2 - free a linked list
 * head: double pointer
 * 
 * Return: None
 */
void free_listint2(listint_t **head)
{
	listint_t *tmp; // Init a tmp node

	if (head == NULL) //test for head content
		return (NULL);

	while(*head != NULL) //looping into the list
	{
		tmp = *head; // *tmp pointer to *head pointer
 		*head = *head->next; // (*head) // *head pointer the nex node
		free(tmp->n), free(tmp); // free actual tmp node
	}

	*head = NULL; // sets head to null
}
