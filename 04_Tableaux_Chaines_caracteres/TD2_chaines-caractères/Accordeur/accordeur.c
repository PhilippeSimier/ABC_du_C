#include "accordeur.h"

void viderBuffer(){
    while (getchar() != '\n')   // vidage du buffer d'entrée
        continue; 
}

void saisirPhrase(char phrase[]){
    printf("Entrez une phrase : \n");  
    fgets(phrase, LONG, stdin );
    
}
/* La fonction decouperPhrase découpe la phrase en tableau de mots
 * Lors du parcours de phrase, la fonction transforme 
 * les espaces blancs en fin de mots en caractère fin de chaîne
 * (caractère \0) et fait pointer tableau à l'intérieur de phrase. 
 * L'avantage de cette méthode est qu'il n'est pas nécessaire 
 * d'allouer de la mémoire supplémentaire pour stocker 
 * les mots isolés de la phrase. 
 */
int decouperPhrase(char phrase[], char *tableau[]){
    char *debut = phrase;
    int i;
    
    for (i=0; i < MAXMOTS-1; i++){
        //On saute les caractères qui ne sont pas des lettres
        while (*debut && isspace(*debut)){
            debut ++;
        }
        // si fin de phrase on quitte la boucle
        if (!*debut) break;
        // sinon on mémorise le début du mots
        tableau[i] = debut;
        // puis recherche de la fin du mots
        while (*debut && ! isspace(*debut)){
            debut ++;
        }    
        // Ajout d'une fin de chaine et passage au mot suivant 
        if (*debut){
           *debut = '\0';
           debut++;
        }    
    }
    tableau[i] = NULL;
    return i;
}

logique estPluriel(char *mot){
    logique retour = NON;
    if (mot[strlen(mot) - 1] == 's'){
        retour = OUI;
    }
    return retour;
}

