#include "linked_list.h"

void NodeContentPrint(NODE *current)
{
	int i = 0;
	while (current)
	{
		printf("Node [%d]: [%d]", i, current->number);
		printf(current->next ? ", " : "\n");
		current = current ->next;
	}
}
