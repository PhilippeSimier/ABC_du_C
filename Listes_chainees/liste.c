/******************************************************************************
*  biblio liste.c
******************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include "liste.h"

// Créer un liste vide
void init(Cellule **L){
    *L = NULL;
}

// empiler une valeur en tête de liste
void push(Cellule **oldL, float donnee){
    Cellule *newL;

    newL = (Cellule*)malloc(sizeof(Cellule)); // création d'une nouvelle cellule
    newL->donnee = donnee;
    newL->next = *oldL;
    *oldL = newL;
}

// ajoute une valeur en queue de liste
void tail(Cellule **L, float donnee){
    Cellule *newL;
    Cellule *p;

    newL = (Cellule*)malloc(sizeof(Cellule)); // allocation de mémoire pour une nouvelle cellule
    newL->donnee = donnee;  // donnée de la nouvelle cellule
    newL->next = NULL;  // la nouvelle est la dernière
    if (*L == NULL)     // cas particulier si la liste est vide
	*L = newL;
    else {
	for( p = *L; p->next ; p = p->next)
 	    {}
	p->next = newL;
    }
}

// retire une valeur en tête de  pile
// la fonction renvoie 1 en cas d'erreur ou 0 en cas de succès
// la pile est passé par adresse on a doonc un double pointeur
int pull(Cellule **L, float *donnee){

    Cellule *pointeur;
    if (*L == NULL)
	return 1;  // si la pile est vide retourne 1

    *donnee = (*L)->donnee;
    pointeur = (*L)->next;
    free(*L);  //destruction de la cellule retirée
    *L = pointeur;

    return 0;
}

// Affichage du contenu de la liste
void afficher (Cellule *L){
    char premier = 1;

    printf("{");
    for(; L ; L = L->next)
    {
	if (!premier)
		printf(",");   // affiche un séparateur sauf pour le premier
	else
		premier = 0;
	printf(" %.2f", L->donnee);
    }
    printf(" }\n");
}

// Compte le nb d'éléments de la liste
int len(Cellule *L){
    int nb = 0;

    for(; L ; L = L->next)
	nb++;
    return nb;
}

// pour détruire une liste chainée il faut détruire chacune des cellules
void detruire(Cellule **L){
    Cellule *pointeur;

    while( *L != NULL){
	pointeur = *L;   // mémorisation de l'adresse de la cellule
        *L = (*L)->next; // passage a la cellule suivante
        free(pointeur);  // destruction de cellule  mémorisée
    }
    *L = NULL;
}

float somme(Cellule *L){
    float som = 0.0;

    for(; L ; L = L->next){
	som += L->donnee;
    }
    return som;
}

