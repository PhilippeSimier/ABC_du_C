/****************************************************************
*    Calcul d'une valeur approchée de PI			*
*    En mathématique, nous avons appris que la somme :		*
*    1 – 1/3 + 1/5 – 1/7 + 1/9 – 1/11 + 1/13 … tend vers pi/4,	*
*	Compilation : gcc calcul_pi.c -o calcul_pi -Wall	*
*****************************************************************/

#include <stdio.h>
#include <stdlib.h>
#define EPSILON 0.000001

int main()
{
    double piSurQuatre = 1.0;
    double signe = -1;
    double denominateur = 3.0;
    double fraction;

    piSurQuatre = 1.0;

    do {
            fraction = 1.0/denominateur;
            piSurQuatre +=  (fraction *  signe);
            signe *= -1;
            denominateur +=  2.0;
    }
    while (fraction*4 > EPSILON);

    printf("Pi = %f\n", piSurQuatre*4);
    return 0;
}
