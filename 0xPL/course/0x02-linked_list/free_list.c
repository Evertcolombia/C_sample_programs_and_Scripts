#include "linked_list.h"
int freeList(NODE *current)
{
	NODE *next;
        while (current)
        {
		next = current->next;
		free(current);
		current = current->next;
        } return (0);
}
