#include "linked_list.h"

int main(int argc, const char *arg[])
{
	NODE *start = NULL, *current, *next;
	char goOn;
	int listSize = 0, number, deleteNumber;

	do {
		printf("La lista contiene %d nodos. (Ingrese el siguiente numero 0 para finalizar)\n", listSize);
		scanf("%d", &number);

		if (number)
		{
			if (!start)
			{
				start = createNode(number);
				listSize++;
			}
			else
			{
				current = start;
				while(current->next)
					current = current->next;
				current->next = createNode(number);
				listSize++;
			}
			goOn = 1;
		}
		else
		{
			scanf("insert the number in the node that wants to delete: %d. (press 0 to out of the program))\n", &deleteNumber);
			if (deleteNumber)
			{
				free_node(current,  deleteNumber);
                                printf("the node with the %d number was deleted\n", deleteNumber);
                                continue;
			}
			else
			{
				goOn = 0;
			}
		}

	} while (goOn);

	current = start;
        printf("La lista contiene los Numeros: \n");
	NodeContentPrint(current);

        current = start;
        freeList(current);

        return (0);
}
