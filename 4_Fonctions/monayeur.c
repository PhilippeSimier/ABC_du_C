/***********************************************************************
    TP3 Distributeur de boissons
    Compilation : gcc monayeur.c biblio_monayeur.c -o monayeur -Wall
************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include "biblio_monayeur.h"

int main()
{   /* la valeur des pièces en centimes d'euros */
    int valPiece[5] = {200, 100, 50, 20, 10};
    int prixBoisson;
    int valeurARendre;
    int nbPiece[5]    = {5, 5, 8, 9, 12};
    int pieceUser[5]  = {0, 0, 0, 0, 0};
    int pieceRendu[5] = {0, 0, 0, 0, 0};
    int choix;
    int boucle;

    printf("Système monayeur Bonjour.\n");

    do{
        printf("Que voulez-vous faire ?\n");
        printf("1 -> Commander une boisson\n");
        printf("2 -> Quitter\n");
        printf("Votre choix : ");
        scanf("%d", &choix);

        switch (choix){
        case 1:
            prixBoisson = demanderBoisson();
            valeurARendre = attendrePiece(prixBoisson, pieceUser);
            printf("Somme à rendre : %.1f\n", ((float)(valeurARendre)/100.0));
            // ajouter les pieces de l'usager dans le monnayeur
            ajouterPiece(nbPiece, pieceUser);
            rendrePiece(valeurARendre, valPiece, nbPiece, pieceRendu);

            printf("Pieces rendues :\n");
            for(boucle = 0; boucle < 5; boucle++){
		if (pieceRendu[boucle] != 0)
             		printf("%d piece de %.1f€\n", pieceRendu[boucle], ((float)(valPiece[boucle])/100.0));
            }
            break;
        case 2:
            printf("Au revoir\n");
            break;
        default:
            printf("Saisie incorrecte\n");
            break;
        }

    }while(choix != 2);


    return 0;
}

