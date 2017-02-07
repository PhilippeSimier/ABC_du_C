/**********************************************************************
*  Un adhérent à un complexe sportif est caractérisé par:
	son nom.
	son prénom.
	son numéro de badge composé d'un ensemble
		10 chiffres et/ou lettres.
	son numéro d'activité
  Compilation : gcc -Wall adherent.c biblio_adherent.c -o adherent
***********************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "biblio_adherent.h"
#define NBINSCRITMAX 5000
#define TAILLEMAX 50

int main()
{
    int choix;
    int boucle;
    char numCarteAdherent[TAILLEMAX];
    int indiceAdherent=0;

    typeAdherent *adherent[NBINSCRITMAX];

    system("clear");
    printf("Bienvenue au club.\n\n");

    do{
        printf("Que voulez-vous faire ?\n");
        printf("  1 -> S'inscrire\n");
        printf("  2 -> Afficher un adhérent en particulier\n");
        printf("  3 -> Quitter\n");
        printf("  Votre choix : ");
        scanf("%d", &choix);

        switch (choix){
        case 1:
	    system("clear");
            adherent[indiceAdherent] = nouvelAdherent();
            indiceAdherent++;
	    void continuer();
            break;
        case 2:
            system("clear");
            printf("\nQuel adhérent voulez-vous afficher ?");
            scanf("%s", numCarteAdherent);
            afficherUnAdherent(adherent, numCarteAdherent, indiceAdherent);
	    void continuer();
            break;
        case 3:
            printf("\nAu revoir.\n");
            break;
        default:
            printf("\nChoix incorrecte.\n");
            break;
        }
    }while(choix < 3);

    //liberation de la memoire
    for(boucle = 0; boucle < indiceAdherent; boucle++){
        free(adherent[boucle]);
    }

    return 0;
}
