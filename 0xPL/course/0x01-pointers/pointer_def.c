#include <stdio.h>

int main ()
{
        int number = 5;
        int *point;

        /*pointer to variable*/
        point = &number;

        /*get address of a variable*/
        printf("%p\n", &number);


        /*print the adress and value that is in a pointer*/
        printf("%p, %d\n", point, *point);

        return (0);
}
