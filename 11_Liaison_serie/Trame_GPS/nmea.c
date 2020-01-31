#include "nmea.h"

int decouper(char trame[], char *tableau[]){
    char *debut = trame;
    int i;

    for (i=0; i < MAX-1; i++){
        //On saute les caractères qui ne sont pas des lettres
        while (*debut && isspace(*debut)){
            debut ++;
        }
        // si fin de phrase on quitte la boucle
        if (!*debut) break;
        // sinon on mémorise le début du champ
        tableau[i] = debut;
        // puis recherche de la fin du champ
        while (*debut && *debut != ','){
            debut ++;
        }
        // Ajout d'une fin de chaine et passage au champ suivant
        if (*debut){
           *debut = '\0';
           debut++;
        }
    }
    tableau[i] = NULL;
    return i;
}
