/******************************************************************
    Correction question 6 TP pointeur

    compilation : gcc exo6.c biblio_pointeur.c -o exo6 -Wall

******************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "biblio_pointeur.h"



int  main(){

    char buffer[50];
    char *pt_sansE;

    printf("donnez un phrase : ");
    fgets(buffer, sizeof(buffer), stdin);
    pt_sansE = supprimerE(buffer);
    printf("%s\n", pt_sansE);

    return 0;
}

