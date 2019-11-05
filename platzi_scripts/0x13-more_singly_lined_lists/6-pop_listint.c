/* function that deletes the head node of a listint_t linked list, and returns the head node’s data (n). */

#include <stdlib.h>
#include <lists.h>

/**
 * pop_listint
 * head - duble pointer to list
 * 
 * Return: data int;
 */
int pop_listint(listint_t **head)
{
	listint_t *tmp; // temporal node
	int data; //int to store data 

	//tmp = *head // tmp ponter to head pointer
	//if head == null return (0)

	if (*head != NULL)
	{
		tmp = *head; //tmp pointer to head pointer
		*head = *head->next; // *head pointer next node
		data = tmp->n; // data store  ddata from tmp node
		free(tmp->n), free(tmp); // free tmp node
		return (data); // return data
	}
	return(0);
}
