/************************************************************************
*	    SABLIER de NOMBRES			    		    	*
*  Nous pouvons représenter un sablier comme ci-dessous avec une    	*
*  suite de nombres dont le plus grand sur la première ligne doit   	*
*  être impair. Par exemple, ici Nbligne  vaut 9.		    	*
*									*
*   01 02 03 04 05 06 07 08 09						*
*      10 11 12 13 14 15 16						*
*         17 18 19 20 21						*
*            22 23 24							*
*               25							*
*            26 27 28							*
*         29 30 31 32 33						*
*      34 35 36 37 38 39 40						*
*   41 42 43 44 45 46 47 48 49						*
*									*
*   									*
*************************************************************************/
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

