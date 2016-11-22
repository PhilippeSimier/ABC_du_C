#include <stdio.h>
#include <stdlib.h>
#include "biblio_personne.h"

// retourne un pointeur sur une personne
typePersonne *creePersonnePtr(){

    typePersonne *personne;

    // allocation de mémoire pour une structure personne
    personne = (typePersonne*) malloc(sizeof(typePersonne));

    printf("Quel est votre prenom ? ");
    scanf("%25s", personne->prenom);
    printf("Quel est votre nom ? ");
    scanf("%25s", personne->nom);
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

