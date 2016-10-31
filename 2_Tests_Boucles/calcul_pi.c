/****************************************************************
*    Calcul d'une valeur approchée de pi			*
*    En mathématique, nous avons appris que la somme :		*
*    1 – 1/3 + 1/5 – 1/7 + 1/9 – 1/11 + 1/13 ... tend vers pi/4 *
*    4 - 4/3 + 4/5 - 4/7 + 4/9 - 4/11 + 4/13 ... Tend vers pi   *
*								*
*    Compilation : gcc calcul_pi.c -o calcul_pi -Wall		*
*    Exécution   : time ./calcul_pi				*
*								*
*    Pi = 3.14159266 à +-0.00000001				*
*								*
*    real    0m10.730s						*
*    user    0m10.720s						*
*    sys     0m0.000s						*
*								*
*****************************************************************/

#include <stdio.h>
#include <stdlib.h>
#define EPSILON 0.00000001

int main()
{
    double pi = 4.0;
    double signe = +1;
    double denominateur = 1.0;
    double fraction;

    do {
        signe *= -1;
        denominateur +=  2.0;
	fraction = 4.0/denominateur;
        pi +=  (fraction *  signe);
    }
    while (fraction > EPSILON);

    printf("Pi = %.8f à +-%.8f\n", pi, fraction);
    return 0;
}
