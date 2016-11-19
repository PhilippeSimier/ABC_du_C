/******************************************************************
    Correction question 5 TP pointeur
    5. Codez une fonction moisNom qui retourne un pointeur sur
    une chaîne de caractères allouée dynamiquement et qui contient
    le nom du mois dont le numéro est passé en paramètre.

    compilation : gcc exo5.c biblio_pointeur.c -o exo5

******************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "biblio_pointeur.h"



void main(){
    int Nb;
    char *pt_char;


    do{
	printf("De quel mois voulez-vous le nom ? (Entre 1 et 12)\n");
    	scanf("%d", &Nb);
    }
    while( Nb <1 || Nb >12);
    pt_char = moisNom(Nb);

    printf("%s\n", pt_char);
}

