#include "header.h"

CONTACT *createList(char *buffer, CONTACT *list)
{
	char emailBuffer[100];
	int L_size = 0;

	if (strcmp("0", buffer) != 0)
	{
		if(!list)
			list = malloc(sizeof(CONTACT));
		else
			list = realloc(list, L_size + 1  * sizeof(CONTACT));
		strcpy(list[L_size].name, buffer);
		
		printf("Ingrese el email de %s\n", buffer);
		scanf("%99s", emailBuffer);
		strcpy(list[L_size].email, emailBuffer);

		L_size++;
	}
	else
		printf("Campo vacio ilegal\n");
		return(list);
	return (list);
}
