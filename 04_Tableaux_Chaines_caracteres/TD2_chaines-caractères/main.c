/* 
 * File:   main.c
 * Author: psimier
 *
 * Created on 26 novembre 2018, 08:17
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "conjugueur.h"


int main(int argc, char** argv) {
    char verbe[255];
    
    printf("Donner un verbe\n");
    scanf("%s", verbe);
    if (isPremierGroupe(verbe)){
        printf("Le verbe %s est du premier groupe\n", verbe);
        conjuguerAuPresent(verbe);
    }
    else{
        printf("Le verbe saisi n' est pas du premier groupe\n");
    }
    
    return (EXIT_SUCCESS);
}

