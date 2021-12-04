#include "nmea.h"

/**
 * @brief Scinde une chaîne de caractères en segments
 * @param trame une chaine de caractères à découper
 * @param champ un tableau de chaine (char *)
 * @param size la taille maxi du tableau à ne pas dépasser
 * @return le nombre de champs trouvés
 */
int decouper(char trame[], char *champ[],const int size) {

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

/**
 * @brief Retourne un segment de chaîne
 * @param src     un pointeur sur la chaine source
 * @param offset  la chaîne retournée commencera au caractère numéro offset
 * @param len     la chaîne retournée contiendra length caractères
 * @return la fonction renvoie un pointeur sur la chaîne résultat dest.  
 */
char *substr(char *src, const int offset, const int length) {
    char *dest = NULL;
    if (length > 0) {
        // allocation de mémoire avec mise à zéro          
        dest = calloc(length + 1, sizeof (char));
        // vérification de la réussite de l'allocation 
        if (NULL != dest) {
            strncat(dest, src + offset, length);
        }
    }
    return dest;
}

/**
 * @brief fonction pour convertir valeur en degrés, sous forme décimale.
 * @param champ de la latitude ou longitude
 * @param indicateur 
 * @return 
 */

double convertirDegreDeci(char *champ, char *indicateur) {

    double retour = 0.0;
    char *degre = NULL;
    char *minute = NULL;

    if (strlen(champ) == 8) {
        degre = substr(champ, 0, 2);
        minute = substr(champ, 2, 6);
    }
    if (strlen(champ) == 9) {
        degre = substr(champ, 0, 3);
        minute = substr(champ, 3, 6);
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
void calculerCRC(const char trame[], char retour[]) {

    char *s; // pointeur pour parcourir la trame
    // Calcul le CRC entre $ et *
    char crc = 0;
    for (s = trame; *s && *s != '*'; s++) {
        if (*s != '$')
            crc = crc ^ *s;
    }
    snprintf(retour, 4, "*%02X", crc);
}


