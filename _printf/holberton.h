#ifndef _HOLBERTON_H_
#define _HOLBERTON_H_
#include <stdarg.h>

int _putchar(char c);
int _printf(const char *format, ...);
int (*get_ops_function(char s))(va_list ap);
int  print_char(va_list ap);

typedef struct data
{
        char *type;
        int (*f)(va_list ap);
} d_dt;
#endif /* _HOLBERTON_H_ */