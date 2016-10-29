#include <stdio.h>
#include <stdlib.h>

typedef struct Cellule
{
    float donnee;
    struct Cellule *next;  // pointeur sur la valeure suivante
}Cellule;

// empile une valeur en queue de liste
void push(Cellule **oldL, float donnee){
    Cellule *newL;

    newL = (Cellule*)malloc(sizeof(Cellule)); // création d'une nouvelle cellule
    newL->donnee = donnee;
    newL->next = *oldL;
    *oldL = newL;
}

// retire une valeur en queue de  pile
float pull(Cellule **L){
    float donnee;
    Cellule *pointeur;
    if (*L == NULL)
	return 0.0;

    donnee = (*L)->donnee;
    pointeur = (*L)->next;
    free(*L);  //destruction de la cellule retirée
    *L = pointeur;

    return donnee;
}

// Affichage du contenu de la liste
void afficher (Cellule *L){
    printf("( ");
    for(; L ; L = L->next)
	printf(" %.2f", L->donnee);
    printf(" )\n");
}

// Compte le nb d'éléments de la liste
int len(Cellule *L){
    int nb = 0;

    for(; L ; L = L->next)
	nb++;
    return nb;
}

int main()
{
    float valeur;
    Cellule *liste = NULL; //initialisation d'une liste vide
    int i;
    float tableau[4] = { 6.5, 4.23, 2.1, 4.5 };

    for (i=0 ; i<4 ; i++){
    	push( &liste, tableau[i]);
    }

    afficher(liste);
    printf ("taille de la liste : %d\n", len(liste));

    for (i=0 ; i<4 ; i++){
   	valeur = pull( &liste);
   	printf("Valeur retirée %.2f\n", valeur);
   	afficher(liste);
   	printf ("taille de la liste : %d\n", len(liste));
    }
    return 0;
}
