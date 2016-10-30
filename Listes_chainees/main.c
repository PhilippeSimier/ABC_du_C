/******************************************************************************
*  gcc main.c liste.c -o main -Wall
******************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include "liste.h"

int main()
{
    float valeur;
    Cellule *liste; 
    int i, erreur;
    float tableau[4] = { 6.5, 4.23, 2.1, 4.5 };
    char choix;

    init(&liste);  // initialisation d'une liste vide;
    // remplissage avec les éléments d'un tableau
    for (i=0 ; i<4 ; i++){
    	push( &liste, tableau[i]);
    }

    afficher(liste);
    printf ("taille de la liste : %d\n\n", len(liste));

    printf(" d pour détruire la liste\n");
    printf(" a pour ajouter un élément\n");
    printf(" r pour retirer un élément\n");
    printf(" s pour afficher le contenu\n");
    printf(" t pour ajouter un élément à la fin\n");
    printf(" S pour afficher la somme des éléments\n");
    printf(" q pour quitter\n");

    do{
    	printf("Votre choix ? :");
    	scanf(" %c", &choix);

    	switch(choix){
    	case 'd':
            detruire(&liste);
            break;

        case 'r':
            erreur = pull( &liste, &valeur);
            if(erreur == 0)
            	printf("Valeur retirée %.2f\n", valeur);
            else
            	printf("Erreur liste vide\n");
            afficher(liste);
            printf ("taille de la liste : %d\n", len(liste));
            break;

	case 'a':
	    printf("Valeur à ajouter à la tête : ");
 	    scanf("%f",&valeur);
	    push( &liste, valeur);
	    break;

        case 't':
            printf("Valeur à ajouter à la queue : ");
            scanf("%f",&valeur);
            tail( &liste, valeur);
            break;


	case 's':
	    afficher(liste);
            break;

	case 'S':
            valeur = somme(liste);
	    printf("La somme des éléments est :%.2f\n", valeur);
	    break;

	}
    }
    while(choix != 'q');
    return 0;
}
