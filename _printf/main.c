/* include header */
#include <stdarg.h>
#include <stdio.h>
#include "holerton.h"

int (*get_ops_function(char s))(va_list ap)
{
    int i = 0;

    d_dt data_types[] = {
        {"c", print_char},
       /* {"s", print_string},*/
        {NULL, NULL}
    };

    while (i < 3)
    {
        if (s == *data_types[i].type)
           return (data_types[i].f);
       i++;
    }
}

int print_char(va_list ap)
{
	printf("hola");
    return(1);
}

int main ()
{
    _printf("%c");
    return(0);
}