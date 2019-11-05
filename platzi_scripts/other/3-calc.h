#ifndef _HOLBERTON_H_
#define _HOLBERTON_H_

/**
 * struct op - Struct op
 *
 * @op: The operator
 * @f: The function associated
 */

/* define a structure op that contains two atrributes
a char that is a pointer '*op' and a function pointer that recives 
tow integers as parameters */
typedef struct op
{
    char *op;
    int (*f)(int a, int b);
} op_t;

/* Prototpyes */
int op_add(int a, int b);
int op_sub(int a, int b);
int op_mul(int a, int b);
int op_div(int a, int b);
int op_mod(int a, int b);
int (*get_op_func(char *))(int, int);

#endif /* _HOLBERTON_H */
 