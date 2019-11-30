#include "3-calc.h"
#include <stdlib.h>
#include <stdio.h>

/* Function pointer that recives a pointer to a char and 
 returns a function from our structure  with two integers as arguments */
int (*get_op_func(char *s))(int, int)
{
	/* structure, that containt two properties for each one of his index
	operator 'op', and function 'f' */
    op_t ops[] = {
		{"+", op_add},
		{"-", op_sub},
		{"*", op_mul},
		{"/", op_div},
		{"%", op_mod},
		{NULL, NULL}
	};
    int i;
    
	i = 0;
	while (i < 5)
	{
		/* if the ops instance  in the index i  into that index in the op
		property  is equal to the *s from the  argument pass for the function */
		if (*ops[i].op == *s)
		{
			/* if that *s argument plus 1  is the same that null
			Returns that ops instance in index i into the function property*/
			if (*s + 1 == '\0')
				return (ops[i].f)
		}
	}
}