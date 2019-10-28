#include <stdarg.h>
#include <stdio.h>
#include "holerton.h"

int _printf(const char *format, ...)
{
    int i = 0, byte = 0;
    int (*execute)(va_list ap);

    va_list ap;
    va_start(ap, format);

    while (format[i])
    {
        if (!format[i])
            return(-1);

        if (format[i] == '%')
            execute = get_ops_function(format[i + 1]);

        byte = execute(ap);
        i++;
    }
    va_end(ap);
    return(byte);
}