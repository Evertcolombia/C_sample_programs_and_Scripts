#include "linked_list.h"

int free_node(NODE *current, int number)
{
        NODE *next, *tmp;

        while(current)
        {
                tmp = current;

                if (current->number == number)
                {
                        next = current->next;
                        free(current);
                        current = current->next;
                }
                else if (current->number == number)
                {
                        next = current->next;
                        tmp->next = tmp->next->next;
                        free(current);
                        current = current->next;
                }
                else
                        current = current->next;
        }
        return (0);
}
