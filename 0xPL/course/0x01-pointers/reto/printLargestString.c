#include "header.h"

void printLargestString(int arc, char *arv[])
{
	int i= 1, temp = 0, total = 0;
	char largest[50];
	
	for (; i < arc; i++)
	{
		temp = strlen(arv[i]);
		if(temp > total)
		{
			total = temp;
			strcpy(largest, arv[i]);
		}
	}

	printf("largest: %s\n", largest);
}
