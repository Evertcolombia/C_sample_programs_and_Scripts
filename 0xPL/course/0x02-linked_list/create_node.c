#include "linked_list.h"

NODE *createNode(int number)
{
	NODE *newNode;

	newNode = malloc(sizeof(NODE));
	if (newNode == NULL)
		return (NULL);

	newNode->next = NULL;
	newNode->number = number;

	return (newNode);
}
