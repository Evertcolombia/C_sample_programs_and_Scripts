//Esta es una tienda que vende productos en la terminal

/** 1-
 * Es buena practica iniciar con tu lgica haciendo los condicionales que necesitas
 * aun si no pones su contenido es bueno tener esto ya claro
 */

#include <stdio.h>
#include <string.h>

char option[8];
int caps, term, tshirt, cup; 
int total_cap = 0, total_term = 0, total_tshirt = 0, total_cup = 0;
int buying = 1;
void main ()
{
    while (buying == 1)
    {
        printf("Choose the product that you're finding\n");
        printf("Firt option is a cap, ingress cap to choose one\n");
        printf("\nPut term to boy one\n");
        printf("\nput t-shirt to buy one\n");
        printf("\nput cup  to buy one\n");

        scanf("%s", option);

        if (strcmp(option, "cap") == 0)
        {
            printf ("\nTerm's price $10, how many do u want\n");
            scanf("%d", &term);
            total_term = total_term + (total_term * 10);
            printf("\nTotal value for Term's is: %d \n", total_term);
        }
        else if (strcmp(option, "term") == 0)
        {
            printf ("\ncap's price $5, how many do u want\n");
            scanf("%d", &caps);
            total_cap = total_cap  + (caps  * 5);
            printf("\nTotal value for caps is: %d \n", total_cap);
        }
        else if (strcmp(option, "tshirt") == 0)
        {
            printf ("\nT-shirt's price $25, how many do u want\n");
            scanf("%d", &tshirt);
            total_tshirt = total_tshirt + (tshirt * 25);
            printf("\nTotal value for T-shirt-s is: %d \n", total_tshirt);
        }
        else if (strcmp(option, "cup") == 0)
        {
            printf ("\ncup's price $2, how many do u want\n");
            scanf("%d", &cup);
            total_cup = total_cup  + (cup  * 2);
            printf("\nTotal value for cups is: %d \n", total_cap);
        }
        else
        {
            printf("\nyour choose isnt in our inventary\n");
            printf("\ntry other option\n");
            printf("\nDo you want another product, put 1, for get out put other number \n");
            scanf("%d", &buying);
        }
    }    

}