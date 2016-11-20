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

/* 6. Codez une fonction supprimerE qui prend en paramètre une
      chaîne de caractères et retourne  un pointeur sur une chaîne
      de caractères allouée dynamiquement et qui contient la chaîne
      de caractères initiale sans les caractères 'e'.
*/

char* supprimerE(char chaine[]){

    int i,j;
    int nb = 0;
    char *sensE;
    char *s;

    // Boucle pour compter le nb de caractères différent de e dans la chaine
    for(s=chaine ; *s; s++){
        if( *s != 'e')
            nb++;
    }

    // Allocation de mémoire pour la nouvelle chaine
    sensE = (char*)malloc( (nb+1) * sizeof(char));

    for( i=0, j=0; i < strlen(chaine); i++){  // Attention deux indexs i et j sont initialisés
        if(chaine[i] != 'e'){
            sensE[j] = chaine[i];
            j++;
        }
    }
    // retourne la nouvelle chaine
    return sensE;
}
