/* function that returns the sum of all the data (n) of a listint_t linked list. */

#include <stdlib.h>
#include "lists.h"

/**
 * sum_listint - sum elements of a list
 * @head: linked list
 * 
 * Return: sum or null
 */
int sum_listint(listint_t *head)
{
	int sum = 0; // init int to store sum
	
	if (head == NULL) // test if head is empty
		return (0);

	while (head != NULL) //loop trougth the list
	{
		sum  = sum + head->n; //sum  n from each node
		head = head->next; // head pointer next node
	}
	return (sum); //total sum
}