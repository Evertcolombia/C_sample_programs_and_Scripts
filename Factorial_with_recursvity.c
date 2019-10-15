#include <stdio.h>

long result;
int n;

/*Usamos una variable de tipo long para recbir cualquier numero*/
long factorial(int n)
{
    /*si es igual a 0 devuelva el resultado*/
    if (n == 0)
        return (1);
    else
        /*Hace la recursvidad llamando a la funcion para hacer su calculo*/
        return (n * factorial(n - 1));
}

/*Drver de nuestro programa*/
int main(int argc, char const *argv[])
{
    printf("Ingrese el numero a calcular\n");
    scanf("%d", &n);
    
    if (n < 0)
        printf("EL numero debe ser postivo\n");
    else
    {
        result = factorial(n);
        printf("%d! = %ld\n", n, result);
    }
    return 0;
}