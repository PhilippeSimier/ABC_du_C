/****************************************************
*	  Programme sablier de nombres		    *
*****************************************************/
#include <stdio.h>
#include <stdlib.h>

int main()
{
   int i,j;
   int nbBlanc = 1;
   int val = 1;
   int nb;

   printf("Combien de lignes ? ");
   scanf (" %d",&nb);
   printf("\n");

   for (i=0; i<nb; i++){
        nbBlanc = (nb/2) - abs((nb/2) - i);
        for (j=0; j<nbBlanc; j++) printf("   ");

        for (j=0; j<(nb-2*nbBlanc); j++){
                printf("%02d ",val);
                val++; val %= 100;
        }
        for (j=0; j<nbBlanc; j++) printf("   ");

        printf("\n");
   }
   printf("\n");
   return 0;
}

