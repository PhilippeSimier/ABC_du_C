#include <stdio.h>
#include <math.h>


void calculPrix(double taxe1, double taxe2, double *prix)
{
    *prix = (*prix / (1 + taxe1 / 100)) * ( 1 + taxe2 / 100);
    *prix = round( *prix * 100) / 100;
}

int main(){

    double tarif=24.9;
    calculPrix(5.5, 19.6, &tarif);
    printf("%lf\n",tarif);

    return 0;
}
