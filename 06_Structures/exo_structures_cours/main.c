/*
 * File:   main.c
 * Author: psimier
 *
 * Created on 28 novembre 2018, 10:58
 * compilation : gcc main.c
 * execution   : valgrind --leak-check=full ./a.out
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 255

typedef struct {
    char nom[MAX];
    char prenom[MAX];
    unsigned int annee;
    float taille;
    float poids;
}typePersonne;

void afficherPersonne(typePersonne toto){
    printf("nom    : %s\n", toto.nom);
    printf("année  : %d\n", toto.annee);
}

void afficherPersonnePtr(typePersonne *toto){
    printf("nom    : %s\n", toto->nom);
    printf("année  : %d\n", toto->annee);
}

typePersonne creerPersonne(){

    typePersonne toto;
    printf("Donnez le nom : \n");
    scanf("%s", toto.nom );
    printf("Donnez l'année de naissance : \n");
    scanf("%d", &toto.annee );

    return toto;
}

typePersonne *creerPersonnePtr(){

    typePersonne *personne;
    personne = (typePersonne *)malloc(sizeof(typePersonne));
    printf("Donnez le nom : \n");
    scanf("%s", personne->nom );
    printf("Donnez l'année de naissance : \n");
    scanf("%d", &personne->annee );

    return personne;
}



/*
 *
 */
int main(int argc, char** argv) {

    typePersonne robert, jumeau;
    typePersonne *raymonde;

    robert = creerPersonne();
    raymonde = creerPersonnePtr();
    afficherPersonne(robert);

    afficherPersonnePtr(raymonde);
    // Très important libération de la mémoire
    // réservé lors de l'éxécution creerPersonnePtr()
    free(raymonde);

    return (EXIT_SUCCESS);
}

