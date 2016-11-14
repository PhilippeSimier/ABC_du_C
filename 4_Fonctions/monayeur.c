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
    int nbPiece[5]    = {1, 1, 0, 0, 2};
    int pieceUser[5]  = {0, 0, 0, 0, 0};
    int pieceRendu[5] = {0, 0, 0, 0, 0};
    int choix;
    int boucle;
    int possible;

    printf("Système monayeur Bonjour.\n");

    do{
        printf("Que voulez-vous faire ?\n");
        printf("1 -> Commander une boisson\n");
        printf("2 -> Afficher le contenu de la caisse\n");
        printf("3 -> Quitter\n");
        printf("Votre choix : ");
        scanf("%d", &choix);

        switch (choix){
        case 1:
            prixBoisson = demanderBoisson();
            valeurARendre = attendrePiece(prixBoisson, pieceUser);
            printf("Somme à rendre : %.1f\n", ((float)(valeurARendre)/100.0));

           possible = rendrePiece(valeurARendre, valPiece, nbPiece, pieceRendu);
	   if (possible) {

            	printf("Pieces rendues :\n");
            	for(boucle = 0; boucle < 5; boucle++){
			if (pieceRendu[boucle] != 0)
             			printf("%d piece de %.1f€\n", pieceRendu[boucle], ((float)(valPiece[boucle])/100.0));
            	}
            	// ajouter les pièces du client dans la caisse
            	ajouterPiece(nbPiece, pieceUser);
		}
	    else
		printf("Désolé je n'ai pas assez de monnaie en caisse\n");
            break;
        case 2:
		afficherCaisse( nbPiece, valPiece);
                break;
        case 3:
            printf("Au revoir\n");
            break;
        default:
            printf("Saisie incorrecte\n");
            break;
        }

    }while(choix != 3);


    return 0;
}

