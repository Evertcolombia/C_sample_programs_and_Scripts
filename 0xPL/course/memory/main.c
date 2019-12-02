#include "header.h"

int main ()
{
	CONTACT *list = NULL;
	char buffer[100], *bufferp;
	int i, goOn = 0;

	do
	{
		printf("Ingrese el nombre del nuevo contacto (0 para terminar)\n");
                scanf("%99s", buffer);
		bufferp = buffer;
		list = createList(bufferp, list);
		goOn++;

	} while (goOn < 1 );

	printf("\n Esta es tu lista de contactos:\n");
        printf("Nombre\t\tEmail\n");
	printf("%s\t\t%s\n", list[goOn].name, list[goOn].email);


        /*for (i = 0; i < L_size; i++)
	{
                printf("%s\t\t%s\n", list[i].name, list[i].email);
	}*/
        return (0);
}
