#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define TAILLEMAX 50

/* 5. Codez une fonction moisNom qui retourne un pointeur sur
    une chaîne de caractères allouée dynamiquement et qui contient
    le nom du mois dont le numéro est passé en paramètre.
*/

char* moisNom(int idMois){
    char *arrayMois[12] = {"Janvier", "Fevrier", "Mars",
		      "Avril", "Mai", "Juin", "Juillet",
		      "Aout", "Septembre", "Octobre",
		      "Novembre", "Decembre"};
    char *mois;

    idMois--;
    // allocation de mémoire  Attention au +1
    mois  = (char*)malloc( (strlen(arrayMois[idMois]) + 1) * sizeof(char));
    strcpy( mois, arrayMois[idMois] );

    return mois;
}
