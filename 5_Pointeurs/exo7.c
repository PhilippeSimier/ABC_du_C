/******************************************************************
    Correction question 7 TP pointeur

    compilation : gcc exo7.c biblio_pointeur.c -o exo7 -Wall

******************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "biblio_pointeur.h"


int  main(){

    char *nom;
    nom = saisirChaine("Comment vous appelez-vous ? ");
    printf("Vous vous appelez %s.\n", nom);


    return 0;
}

