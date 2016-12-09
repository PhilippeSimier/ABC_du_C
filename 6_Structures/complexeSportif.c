/****************************************************************************
*  Complexe Sportif
*
*  Compilation :
*  gcc -Wall complexeSportif.c biblio_complexeSportif.c -o complexeSportif
*****************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include "biblio_complexeSportif.h"
#define NBADHERENT 5000

int main()
{
    typeAdherent *tabAdherent[NBADHERENT];
    int compteurAdherent = 0;
    int numeroCarte;
    char choix;
    printf("Base de Donnée Complexe Sportif\n\n");


    do{
	effacerEcran();
        afficherMenu(compteurAdherent);
        scanf(" %c", &choix);
        switch (choix){
        case 'a':
            compteurAdherent = ajouterUnAdherent(tabAdherent, compteurAdherent);
	    continuer();
            break;
        case 's':
            printf("Numéro de carte de l'adhérent à supprimer : ");
            scanf("%d", &numeroCarte);
            compteurAdherent = supprimerUnAdherent(tabAdherent, numeroCarte, compteurAdherent);
            break;
        case 'm':
            printf("Numéro de carte de l'adhérent : ");
            scanf("%d", &numeroCarte);
            modifierFiche(tabAdherent, numeroCarte, compteurAdherent);
            continuer();
            break;
        case 'v':
            printf("Numéro de carte de l'adhérent : ");
            scanf("%d", &numeroCarte);
            afficherUnAdherent(tabAdherent, numeroCarte, compteurAdherent);
	    continuer();
            break;
        case 'l':
            afficherAdherents(tabAdherent, compteurAdherent);
	    continuer();
            break;
        case 'e':
            compteurAdherent = supprimerAdherents(tabAdherent, compteurAdherent);
            continuer();
            break;
        case 'x':
            sauvegardeAdherents(tabAdherent, compteurAdherent);
	    continuer();
            break;
        case 'c':
            compteurAdherent = chargerAdherents(tabAdherent, compteurAdherent);
	    continuer();
            break;
        case 'q':
            break;
        default:
            printf("Saisie incorrecte.");
            break;
        }
    }while(choix != 'q');
    return 0;
}
