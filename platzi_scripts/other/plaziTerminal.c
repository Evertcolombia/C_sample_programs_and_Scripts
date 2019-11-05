#include <stdio.h>
#include <string.h>

/**
 * main - Platzi terminal lets an user init 'session' and chooose some op    tions in a program'
 *
 * Return - none
 */
void main()
{
	char userName[25];
	int decision;
	int count =  1;
	int estudiando = 1;

	while (count == 1)
	{
		printf("Bienvenidos a Platzi Terminal\n");
		printf("Ingresa tu nombre de usuario:\n");
		scanf("%s", userName);
		printf("Bienvenido %s, vamos a acceder a tu seccion\n", userName);

		if (strcmp(userName, "luxy") == 0)
		{
			while (estudiando == 1)
			{
				printf("Esto es platzi terminal free edition, que deseas hacer?\n");
				printf("Ingrese 1 para estudiar,\n 2 Para leer el blog\n Ingrese cualquier otro valor para salir");
				scanf("%d", &decision);

				if (decision == 1)
					printf("Estas en la seccion de estudio, saca el maximo provecho\n");
				else if (decision == 2)
					printf("Estas en el blog, disfruta\n");
				else
				{
					printf("Goodbye");
					estudiando = 2;
				}
			}
		}

		else if (strcmp(userName == "camila") == 0)
		{
			printf("Esto es platziterminal Standar edition, que deseas hacer ?\n");
			printf("Ingrese 1 para estudiar\n 2 para leer el blog\n 3 mentoria\n Ingrese cualquer otro valor para salr");
			scanf("%d", &decision);

			if (decision == 1)
				printf("Estas en la seccion de estudio, saca e    l maximo provecho\n");
 			else if (decision == 2)
 31				printf("Estas en el blog, disfruta\n");
			else if (decision == 3)
					printf("Estas en la seccion de solicitud de mentorias\n");
			else
					printf("Goodbye");

		}

		else
		{
			printf("No eres un usuario registrado, o escribiste mal tu nombre\n");
			printf("Prueba de nuevo por favor");
		}
}
