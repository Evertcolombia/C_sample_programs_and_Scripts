#ifndef _HEADER_H
#define _HEADER_H

#include <string.h>
#include <stdio.h>
#include <stdlib.h>

typedef char NAME[100];
typedef char EMAIL[100];
extern int L_size;
extern int goOn;

typedef struct {
	NAME name;
	EMAIL email;
} CONTACT;

CONTACT *createList(char *buffer, CONTACT *list);
#endif
