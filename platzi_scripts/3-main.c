#include "3-calc.h"
#include <stdlib.h>
#include <stdio.h>

int main (int argc, char *argv[])
{
    /*Declare a function pointer*/
    int (*point)(int, int);
    int res, c, d;

    /*if (argc != 4)
        return (98);*/

    /*if (atoi(argv[3]))
    {
        if (*argv[2] == '%' || *argv[2] == '/')
            return (100);
    }*/

    /* Pointe  is pointing to the funcion get_op... passing the argument
    argv[2] as parameter, this is the operatps passed fot the user 
    it will returns  the correct operation for the user*/
    point = get_op_func(argv[2]);

    if (point == NULL)
        return(99);

    /* convert each number from char to int with atoy */
    c = atoi(argv[1]), d = atoi(argv[3]);

    /* Pass to the res a call to the function pointer that bring back 
    an operation and storages it n resutl*/
    res  = point(c, d);
    printf("%d\n", res);

    return 0;
}