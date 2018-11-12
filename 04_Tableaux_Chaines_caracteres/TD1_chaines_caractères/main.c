/*
 * demande une phrase quelconque à l'utilisateur 
 * à l'aide de la fonction gets 
 * et affiche cette phrase à l'écran
 */

/* 
 * File:   main.c
 * Author: psimier
 *
 * Created on 12 novembre 2018, 07:56
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "caractere.h"

/* 
 * 
 */
#define LONG 255




int main(int argc, char** argv) {
    char phrase[LONG];
    char phraseInverse[LONG];
    char copie[LONG];
    
    printf("Saisir une phrase \n");
    //gets(phrase);
    //scanf("%[^\n]", phrase);
    fgets(phrase, LONG, stdin );
    strncpy(copie,phrase,LONG);
    printf("La phrase est : \"%s\"\n", copie);
    printf("le longueur est : %d \n", (int)strlen(copie));
    if (strncmp(copie,"essai\n", 5) == 0){
        printf("le début de la phrase entrée est essai \n");
    }
    else{
        printf("le début de la phrase entrée n' est pas essai \n");
    }
    printf ("le nb de voyelles est : %d\n", comptageVoyelle(phrase));
    printf ("le nb de consonnes est : %d\n", comptageConsonne(phrase));
    printf ("le nb de motss est : %d\n", comptageMots(phrase));
    Inverser(phrase, phraseInverse);
    printf("%s",phraseInverse);
    return (EXIT_SUCCESS);
}

