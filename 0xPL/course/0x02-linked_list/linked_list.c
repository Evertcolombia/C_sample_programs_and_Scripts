#include <stdio.h>
#include <stdlib.h>

/*Structure for lined list*/
typedef struct Node {
	int number;
	struct Node * next;
} NODE;

/*Function that create a node*/
NODE *createNode(int number)
{
	/*NewNode type  NODE*/
	NODE *newNode;

	newNode = malloc(sizeof(NODE));
	if (newNode == NULL)
		return (NULL);
	/*
	 * new node will points to null and
	 * assign the number in the correct attribute 
	 */
	newNode->next = NULL;
	newNode->number = number;

	/*Return a pointer to the new node*/
	return (newNode);
}

/*
 * function to construct a linked list
 * with the user input
 */
int main(int argc, const char *arg[])
{
	/*
	 * pointer for the new node for the correct
	 * linked
	 */
	NODE *start = NULL, *current;
	char goOn;
	int listSize = 0, number;

	/*
	 * construc list with nodes while the user
	 * dont type 0
	 */
	do {
		printf("La lista contiene %d nodos. (Ingrese el siguiente numero 0 para finalizar)\n", listSize);
		/*get the user input*/
		scanf("%d", &number);

		/*if the user import is not 0 */
		if (number)
		{
			/*If start = NULL or start is not true*/
			if (!start)
			{
				/*
				 * Start create a new node that is signed to 
				 * the start of list
				 */
				start = createNode(number);

				/*plus in one the listSize*/
				listSize++;

			}
			else /*If the list yet have nodes*/
			{
				/*keep a pointer to the start of the list*/
				current = start;

				/*traverse the list while is possible*/
				while(current->next)
					current = current->next;
				/*
				 * Now that are in the last node
				 * create a new node in the current->next
				 * position
				 */
				current->next = createNode(number);
				/*plus listSize in one*/
				listSize++;
			}
			/*keeps cycle and program running*/
			goOn = 1;
		}
		else
		{
			/*if the number is 0 ends the cycle*/
			goOn = 0;
		}
	} while (goOn);

	/*bring back to the start of the list*/
	current = start;
	printf("La lista contiene los numeros: \n" );
	/*Traverse the list print the n in each node
	 * with, and space till the end*/
	while (current)
	{
		printf("%d", current->number);
		printf(current->next ? ", " : "\n");
		current = current->next;
	}

	return (0);
}
