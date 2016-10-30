/******************************************************************************
*  gcc liste.c -o liste -Wall
******************************************************************************/
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

int main()
{
    float valeur;
    Cellule *liste = NULL; //initialisation d'une liste vide
    int i, erreur;
    float tableau[4] = { 6.5, 4.23, 2.1, 4.5 };
    char choix;

    for (i=0 ; i<4 ; i++){
    	push( &liste, tableau[i]);
    }

    afficher(liste);
    printf ("taille de la liste : %d\n\n", len(liste));

    printf(" d pour détruire la liste\n");
    printf(" a pour ajouter un élément\n");
    printf(" r pour retirer un élément\n");
    printf(" s pour afficher le contenu\n");
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
	    printf("Valeur à ajouter :");
 	    scanf("%f",&valeur);
	    push( &liste, valeur);
	    break;

	case 's':
	    afficher(liste);
        }
    }
    while(choix != 'q');
    return 0;
}
