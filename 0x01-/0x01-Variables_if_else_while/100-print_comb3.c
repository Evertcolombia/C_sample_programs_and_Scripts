#include <stdio.h>

int main(void)
{
    int num1, num2 = 49, num3;

    for (num1 = 48; num1 < 57; num1++)
    {
        /*num3 pasa a tener el valor de num2 cada vez que itera este ciclo*/
        num3 = num2;

        for (; num2  <= 57; num2++)
        {
            /*imprime ambos numeros en su indice*/
            putchar(num1);
            putchar(num2);
            
            /*Si el numero es iguala 89 que salte la linea*/
            if (num1 == 56 && num2 == 57)
                putchar(10);
            /*Si no que le agregue ',' y  ' ' a la impresion*/     
            else
            {
                putchar(44);
                putchar(32);
            }
        }
        /*num2 pasa a tener el valor de num3, es el valor que tenia antes de iniciar este ciclo*/
        num2 = num3;
        /*num2 aumenta en un cada vez que termna este ciclo asi comienza un indice arriba cada vez*/
        num2++;
    }
    return (0);
}