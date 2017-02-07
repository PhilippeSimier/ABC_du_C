/******************************************************************
    Correction question 8 TP pointeur

    compilation : gcc exo8.c biblio_pointeur.c -o exo8 -Wall

******************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "biblio_pointeur.h"


int  main(){

    float val1;
    float val2;

    printf("Saisissez deux réels.\n");
    printf("1: ");
    scanf("%f", &val1);
    printf("2: ");
    scanf("%f", &val2);

    printf("Avant:\n");
    printf("Val1 = %.2f \tVal2 = %.2f\n", val1, val2);
    swapFloat(&val1, &val2);

    printf("Après le swap:\n");
    printf("Val1 = %.2f \tVal2 = %.2f\n", val1, val2);

    return 0;
}

