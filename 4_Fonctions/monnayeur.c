/***********************************************************************
    TP3 Distributeur de boissons
    Compilation : gcc monnayeur.c biblio_monnayeur.c -o monnayeur -Wall
************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include "biblio_monnayeur.h"

int main()
{   /* la valeur des pièces en centimes d'euros */
    int valPiece[NB] = {200, 100, 50, 20, 10, 5};
    int prixBoisson;
    int valeurARendre;
    int nbPiece[NB]    = {1, 1, 0, 0, 2, 5};
    int pieceUser[NB]  = {0, 0, 0, 0, 0, 0};
    int pieceRendu[NB] = {0, 0, 0, 0, 0, 0};
    char choix;
    int possible;


    do{
        system("clear");
	printf(" Système Distributeur Bonjour.\n\n");
        printf(" Que voulez-vous faire ?\n\n");
        printf("  1 -> Commander une boisson ou snack\n");
        printf("  2 -> Afficher le contenu de la caisse\n");
        printf("  3 -> Quitter\n\n");
        printf(" Votre choix : ");
        scanf(" %c", &choix);

        switch (choix){

        case '1':
            prixBoisson = demanderBoisson();
            valeurARendre = attendrePiece(prixBoisson, pieceUser);
            printf("Somme à rendre : %.1f €\n", ((float)(valeurARendre)/100.0));

           possible = rendrePiece(valeurARendre, valPiece, nbPiece, pieceRendu);
	   if (possible) {
                // afficher la monnaie à rendre
		if (valeurARendre == 0)
		    printf("Merci d'avoir fait l'appoint !\n\n");
                else
		    afficherMonnaieRendue(pieceRendu, valPiece);
            	// ajouter les pièces du client dans la caisse
            	ajouterPiece(nbPiece, pieceUser);
		}
	    else
		printf("Désolé je n'ai pas assez de monnaie en caisse\n");
                continuer();
            break;

        case '2':
	    afficherCaisse( nbPiece, valPiece);
            break;
        case '3':
            printf(" Au revoir\n");
            break;
        default:
            break;
        }

    }while(choix != '3');


    return 0;
}

