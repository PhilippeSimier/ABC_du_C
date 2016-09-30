/********************************************************************
*	  Programme sablier de nombres		    		    *
*  Nous pouvons représenter un sablier comme ci-dessous avec une    *
*  suite de nombres dont le plus grand sur la première ligne doit   *
*  être impair. Par exemple, ici Nbligne  vaut 7.		    *
*
*   
*********************************************************************/
#include <stdio.h>
#include <stdlib.h>

int main()
{
   int i,j;
   int nbBlanc;
   int val = 1;
   int nbLigne;

   printf("Combien de lignes ? ");
   scanf (" %d",&nbLigne);
   printf("\n");

   for (i=0; i<nbLigne; i++)
   {
        nbBlanc = (nbLigne / 2) - abs((nbLigne / 2) - i);
        for (j=0; j<nbBlanc; j++)
	    printf("   ");

        for (j=0; j < (nbLigne - 2 * nbBlanc); j++)
	{
                printf("%02d ",val++);
	        val %= 100;
        }
        printf("\n");
   }
   printf("\n");
   return 0;
}

