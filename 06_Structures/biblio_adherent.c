#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "biblio_adherent.h"

void continuer(){
    printf(" Pour continuer appuyez sur une touche\n");
    getchar();  // retire le CR
    getchar();  // attend une action sur le clavier
    system("clear");  // efface l'écran
}

typeAdherent *nouvelAdherent(){
    typeAdherent *adherent;

    adherent = (typeAdherent*) malloc(sizeof(typeAdherent));

    printf("Nom: ");
    scanf("%s", adherent->nom);
    printf("Prenom: ");
    scanf("%s", adherent->prenom);
    printf("Numero de badge: ");
    scanf("%s", adherent->numCarte);
    printf("Numero d'activite: ");
    scanf("%u", &adherent->numActivite);

    printf("\nVous êtes incrit.\n\n");

    return adherent;
}

void afficherUnAdherent(typeAdherent *adherent[], char numCarteAdherent[], int nbAdherent){
    int boucle;

    for(boucle = 0; boucle < nbAdherent; boucle++){
        if(strcmp(adherent[boucle]->numCarte, numCarteAdherent) == 0){
            printf(" Nom: ");
            printf(" %s\n", adherent[boucle]->nom);
            printf(" Prenom: ");
            printf(" %s\n", adherent[boucle]->prenom);
            printf(" Numero d'activite: ");
            printf(" %u\n\n", adherent[boucle]->numActivite);

        }
    }
}
