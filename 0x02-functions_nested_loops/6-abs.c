/**
 * Write a function that computes the absolute value of an integer.
 * Prototype: int _abs(int);
 */


int _abs(int n)
{
    /*Si n es menor a cero es negativo so n *  - 1 devuelve
      el mismo numero en positivo porque multiplca los signos tambien*/
    if (n < 0)
        n = n * -1;
    return (n);
}