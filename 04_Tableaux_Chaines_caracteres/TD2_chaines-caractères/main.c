/*
 * application permettant de donner la conjugaison 
 * des verbes du premier groupe au présent.
 */

/* 
 * File:   main.c
 * Author: psimier
 *
 * Created on 12 novembre 2018, 13:31
 */

#include <stdio.h>
#include <stdlib.h>
#include "conjugueur.h"
#define LONG 255

/*
 * 
 */


int main(int argc, char** argv) {

    char verbe[LONG];
    printf("Verbe à conjuger  ?\n");
    scanf("%s",verbe);
    if (isPremierGroupe(verbe)){
        printf("%s au présent de l'indicatif :\n\n", verbe);        
        conjuguerPresent(verbe);
    }
    return (EXIT_SUCCESS);
}

