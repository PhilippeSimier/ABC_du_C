#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define EPSILON 0.00001


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

    int i;
    char *sensE;
    char *s;

    // Boucle pour compter le nb de caractères différent de e dans la chaine
    for(s=chaine, i=0 ; *s; s++){
        if( *s != 'e')
            i++;
    }

    // Allocation de mémoire pour la nouvelle chaine (Attention i+1)
    sensE = (char*)malloc( (i+1) * sizeof(char));

    for( s=chaine, i=0; *s; s++){  // Attention deux initialisations s et i sont initialisés
        if(*s != 'e'){
            sensE[i] = *s;
            i++;
        }
    }
    // retourne la nouvelle chaine
    return sensE;
}

/* 7. Codez une fonction saisirChaine qui demande à l'utilisateur de saisir
une chaine de caractères et retourne un pointeur vers une zone mémoire
allouée dynamiquement et contenant la chaîne saisie.
La fonction saisirChaine prendra en paramètres une chaine de caractères
correspondant au message à afficher pour demander à l'utilisateur de saisir
une chaine.  */

char* saisirChaine(char *message){
    char *nom;
    char buffer[255];

    printf("%s", message);
    scanf("%s", buffer);

    nom = (char*) malloc((strlen(buffer)+1)*sizeof(char));
    strcpy(nom, buffer);

    return nom;
}

/* 8. Codez une fonction swapFloat qui intervertit les valeurs de deux
      variables de type float.  */

void swapFloat(float *ptr1, float *ptr2){
    float tmp;

    tmp = *ptr1;
    *ptr1 = *ptr2;
    *ptr2 = tmp;
}

/* 9 résolution de l'équation du second degré
	retourne le nb de racines dans R (0, 1 ou 2)
*/
int resoSecondDegre(float a, float b, float c, float *racine1, float *racine2){
    float delta, rdelta;

    delta = b*b - 4*a*c;

    if(delta >= EPSILON){
	 rdelta = sqrt(delta);
         *racine1 = ((-b - rdelta) / (2*a));
         *racine2 = ((-b + rdelta) / (2*a));
	 return 2;
    }
    else{
	if(delta >= -EPSILON){
	    *racine1 = (-b / (2*a));
            *racine2 = *racine1;
	    return 1;
	}
        else
	    //pas de racine dans R
	    return 0;

    }
}
