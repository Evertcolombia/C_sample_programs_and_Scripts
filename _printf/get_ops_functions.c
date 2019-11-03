/* include header */
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include "holberton.h"

int (*get_ops_function(char s))(va_list ap)
{
    int i = 0;

    d_dt data_types[] = {
        {"c", print_char},
       /* {"s", print_string},*/
    };

    while (i < 1)
    {
        if (s == *data_types[i].type)
           return (data_types[i].f);
        
       i++;
    }
    exit(-1);
}
