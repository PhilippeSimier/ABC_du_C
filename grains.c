/*****************************************************
*                                                    *
*    Nombre de grains sur un échiquier               *
*    Valeur exacte 2^64 -1                           *
*                                                    *
*     18446744073709551615    20 chiffres en décimal *
******************************************************/


#include <stdio.h>
#include <stdlib.h>

int main()
{
    /* Version avec des entiers sur 64 bits non signé*/
    unsigned long long int total = 1;
    unsigned long long int    nb = 1;
    int i;

    printf("Calcul avec des variables entières sur 64 bits\n\n");

    printf("%2d %20llu %20llu\n",1 , nb, total);
    for(i=1; i<64; i++){
      nb = nb * 2;
      total = total + nb;
    printf("%2d %20llu %20llu\n",i+1 , nb, total);
    }
    return 0;


    /* Version avec des nombres flottants 
    la valeur retournée n'est pas exacte

    double total = 1.0;
    double    nb = 1.0;
    int i;

    for(i=0; i<63; i++){
      nb = nb *2;
      total = total + nb;
    }
    printf("%f\n",total);
    return 0;
    */
}
