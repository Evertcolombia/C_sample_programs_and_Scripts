#include "linked_list.h"

int main(int argc, const char *arg[])
{
	NODE *start = NULL, *current, *next;
	char goOn;
	int listSize = 0, number;

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
			goOn = 0;
	} while (goOn);

	current = start;
        printf("La lista contiene los Numeros: \n");
	NodeContentPrint(current);

        current = start;
        freeList(current);

        return (0);
}
