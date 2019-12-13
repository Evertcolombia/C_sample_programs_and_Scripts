#ifndef _HEADER_
#define _HEADER_

#include <stdlib.h>
#include <stdio.h>

/*Structure for lined list*/
typedef struct Node {
	int number;
	struct Node *next;
} NODE;

/*Protoypes*/
NODE *createNode(int number);
void NodeContentPrint(NODE *current);
int freeList(NODE *current);
#endif
