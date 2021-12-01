#include "nmea.h"


int decouper(char trame[], char *tableau[], int size) {

    char *ptr = trame;
    char fin = 0;

    int i = 0;
    do {

        while (*ptr && isspace(*ptr)) { //On saute les caractères qui ne sont pas des lettres
            ptr++;
        }
        // si fin de trame on quitte la boucle
        if (!*ptr) 
            fin = 1;
        else {   // sinon on mémorise le début du champ
            
            tableau[i] = ptr;
            // puis recherche de la fin du champ (une virgule)
            while (*ptr && *ptr != ',') {
                ptr++;
            }
            // Ajout d'une fin de chaine et passage au champ suivant
            if (*ptr) {
                *ptr = '\0';
                ptr++;
            }
        }
        i++;
    } while (i < size - 1 && !fin);

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
         printf ("Memoire insuffisante\n");
         exit (-1);
      }
   }
   return retour;
}

float convertirDegreDeci(char *champ, char *indicateur){

    float retour = 0.0;
    char *degre = NULL;
    char *minute = NULL;

    if (strlen(champ)==8){
	degre = substr(champ, 0, 1);
	minute = substr(champ, 2, 7);
    }
    if (strlen(champ)==9){
        degre = substr(champ, 0, 2);
        minute = substr(champ, 3, 9);
    }
    retour = atof(degre) + atof(minute)/60;
    if (!strcmp(indicateur,"S") || !strcmp(indicateur,"W")){
	retour *= -1;
    }
    if (degre != NULL) free(degre);
    if (minute != NULL) free(minute);
    return retour;
}

