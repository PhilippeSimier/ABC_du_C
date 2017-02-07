#include <stdio.h>
#include "biblio_q9.h"

int main(){

    FILE * fp;
    typePersonne *liste[1000];
    int nb = 0;

    fp = fopen("fichierNom","r");
    testErreur();

    // lecture du fichier texte
    while(!feof(fp)){
	liste[nb]=lirePersonne(fp);
        nb++;
    }
    for (int i=0; i < nb; i++){
        if (liste[i] != NULL){
		afficherPersonne(liste[i]);
                printf("\n");
        }
    }
    return 0;
}
