#include <stdio.h>
#include <stdlib.h>
#include "biblio_personne.h"

// Fonction pour vider le buffer d'entrée
// lit le buffer d'entrée jusqu'au  retour charriot ou fin de fichier
void vide(void){
    int c;
    do {
        c = getchar();
    } while (c != '\n'  && c != EOF);
}


// retourne un pointeur sur une personne
typePersonne *creePersonnePtr(){

    typePersonne *personne;

    // allocation de mémoire pour une structure personne
    personne = (typePersonne*) malloc(sizeof(typePersonne));

    printf("Quel est votre prenom ? ");
    scanf("%12s", personne->prenom);  // lecture de  12 caractères
    vide(); //vide le buffer d'entrée des caractères entrée au delà des 12 lus par scanf
    printf("Quel est votre nom ? ");
    scanf("%12s", personne->nom); // lecture de 12 caractères
    vide();  //vide le buffer d'entrée
    printf("Quel est votre année de naissance ? ");
    scanf("%u", &personne->annee);
    printf("Quel est votre taille en cm? ");
    scanf("%f", &personne->taille);
    printf("Quel est votre poids en Kg? ");
    scanf("%f", &personne->poids);

    return personne;
}


void affichePersonnePtr(typePersonne *personne){
    printf("\n\n Fiche récapitulative \n\n");
    printf("Votre nom est %s %s\n", personne->nom, personne->prenom);
    printf("Votre année de naissance est %u\n", personne->annee);
    printf("Votre taille est de %.2f cm;\n", personne->taille);
    printf("Votre poids est de %.2f Kg\n\n", personne->poids);
}

