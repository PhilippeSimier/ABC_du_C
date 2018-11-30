/* 
 * File:   main.c
 * Author: psimier
 *
 * Created on 26 novembre 2018, 11:38
 */

#include <stdio.h>
#include <stdlib.h>
#include "accordeur.h"

int main(int argc, char** argv) {

    char *mots[MAXMOTS];
    char phrase[255];
    int i=0, nb= 0;
    
    saisirPhrase(phrase);
    decouperPhrase(phrase,mots);
    
    // Question 3 & 4
    while (mots[i] != NULL){
        printf(" %s", mots[i]);
        if (! strcmp(mots[i],"les") || ! strcmp(mots[i],"des")){
            i++;
            if (estPluriel(mots[i])){
                printf(VERT);
                printf(" %s", mots[i]);
                printf(RESET);
                
            }
            else{
                printf(ROUGE);
                printf(" %s", mots[i]);
                printf(RESET);
            }
        }
        i++;
    }
    printf("\n");
    
    
    return (EXIT_SUCCESS);
}

