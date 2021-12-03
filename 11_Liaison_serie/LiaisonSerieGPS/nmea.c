#include "nmea.h"

int decouper(char trame[], char *champ[], int size) {

    char *ptr = trame;
    char fin = 0;
    int i = 0;

    do {

        while (*ptr && isspace(*ptr)) { //On saute les caractères qui ne sont pas des lettres
            ptr++;
        }
        // si fin de trame on quitte la boucle
        if (*ptr == '\0')
            fin = 1;
        else { // sinon on mémorise le début du champ

            champ[i] = ptr;
            // puis recherche de la fin du champ (une virgule)
            while (*ptr && *ptr != ',') {
                ptr++;
            }
            // Ajout d'une fin de chaine et passage au champ suivant
            if (*ptr != '\0') {
                *ptr = '\0';
                ptr++;
            }
            i++;
        }

    } while (i < size - 1 && !fin);

    champ[i] = NULL;
    return i;
}

// Cette fonction retourne un segment de chaine entre l'indice debut et fin.

char *substr(const char *s, unsigned int debut, unsigned int fin) {
    char *retour = NULL;

    if (s != NULL && debut < fin) {
        retour = calloc(sizeof (char) * (fin - debut + 2), sizeof (char));
        if (retour != NULL) {
            int i;
            for (i = debut; i <= fin; i++) {
                retour[i - debut] = s[i];
            }
            retour[i - debut] = '\0';
        } else {
            printf("Memoire insuffisante\n");
            exit(-1);
        }
    }
    return retour;
}

/**
char *substr(char *src,int pos,int len) { 
  char *dest=NULL;                        
  if (len>0) {                  
    // allocation et mise à zéro          
    dest = calloc(len+1, 1);      
    // vérification de la réussite de l'allocation 
    if(NULL != dest) {
        strncat(dest,src+pos,len);            
    }
  }                                       
  return dest;  
**/

float convertirDegreDeci(char *champ, char *indicateur) {

    float retour = 0.0;
    char *degre = NULL;
    char *minute = NULL;

    if (strlen(champ) == 8) {
        degre = substr(champ, 0, 1);
        minute = substr(champ, 2, 7);
    }
    if (strlen(champ) == 9) {
        degre = substr(champ, 0, 2);
        minute = substr(champ, 3, 9);
    }
    retour = atof(degre) + atof(minute) / 60;
    if (!strcmp(indicateur, "S") || !strcmp(indicateur, "W")) {
        retour *= -1;
    }
    free(degre);
    free(minute);

    return retour;
}

/**
 * @brief Fonction pour calculer le CRC d'une trame
 * @param trame
 * @return le CRC
 */
void calculerCRC(char trame[], char retour[]) {

    char *s; // pointeur pour parcourir la trame
    // Calcul le CRC entre $ et *
    char crc = 0;
    for (s = trame; *s && *s != '*'; s++) {
        if (*s != '$')
            crc = crc ^ *s;
    }
    sprintf(retour,"*%02X", crc );
}


