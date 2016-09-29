/***************************************************************************
*    Calcul de pi
*    En mathématique, nous avons appris que la somme :
*    1 – 1/3 + 1/5 – 1/7 + 1/9 – 1/11 + 1/13 … tend vers pi/4,
*	Compilation : gcc calcul_pi.c -o calcul_pi
****************************************************************************/

#include <stdio.h>
#include <stdlib.h>

int main()
{
    double piSurQuatre = 1.0;
    double epsilon = 0.000001;
    double signe = -1;
    double denominateur = 3.0;
    double fraction;


   piSurQuatre = 1.0;

    do {
            fraction = 1.0/denominateur;
            piSurQuatre = piSurQuatre + (fraction *  signe);
            signe = signe * -1;
            denominateur = denominateur + 2.0;

    }
    while (fraction*4 > epsilon);

    printf("%f\n", piSurQuatre*4);
    return 0;
}
