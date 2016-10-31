/*****************************************************
*                                                    *
*    Nombre de grains sur un échiquier               *
*    Valeur exacte 2^64 -1                           *
*                                                    *
*     18446744073709551615    20 chiffres en décimal *
*     gcc grains.c -o grain -Wall		     * 
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
      nb *=  2;
      total += nb;
    printf("%2d %20llu %20llu\n",i+1 , nb, total);
    }
    return 0;
}
