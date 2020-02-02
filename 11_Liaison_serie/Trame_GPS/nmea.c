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


// Cette fonction retourne un segment de chaine entre l'indice debut et fin.
char *substr(const char *s, unsigned int debut, unsigned int fin){
   char *retour = NULL;

   if (s != NULL && debut < fin){
      retour = malloc (sizeof (char) * (fin - debut + 2));
      if (retour != NULL){
         int i;
         for (i = debut; i <= fin; i++){
            retour[i-debut] = s[i];
         }
         retour[i-debut] = '\0';
      }
      else{
         fprintf (stderr, "Memoire insuffisante\n");
         exit (EXIT_FAILURE);
      }
   }
   return retour;
}

float convertirDegreDeci(char *champ, char *indicateur){

    float retour = 0.0;
    char *degre;
    char *minute;

    if (strlen(champ)==9){
	degre = substr(champ, 0, 1);
	minute = substr(champ, 2, 9);
    }
    if (strlen(champ)==10){
        degre = substr(champ, 0, 2);
        minute = substr(champ, 3, 10);
    }
    retour = atof(degre) + atof(minute)/60;
    if (!strcmp(indicateur,"S") || !strcmp(indicateur,"W")){
	retour *= -1;
    }
    free(degre);
    free(minute);
    return retour;
}
