#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "biblio_complexeSportif.h"

int main(int argc, char** argv) {

    typeAdherent * tableau[5000];
    int nb = 0;
    char choix;
    int numero;

    nb = chargerAdherents(tableau);
    do {
        effacerEcran();
        afficherMenu(nb);
        scanf(" %c", &choix);
        switch(choix){
            case 'A':   // Ajouter une fiche adhérent
            case 'a':    
                tableau[nb] = creerUnAdherent();
                nb++;
                break;
            case 'L':  //Voir le contenu de l'ensemble des fiches
            case 'l':
                afficherLesAdherents(tableau, nb);
                continuer();
                break;
            case 'F':  // sauvegarde les fiches
            case 'f':
                sauvegarderAdherents(tableau, nb);
                continuer();
                break;
                
            case 'E':   // supprimer toutes les fiches
            case 'e':
                nb = supprimerTousLesAdherents(tableau, nb);
                if (nb == 0) printf("fiches supprimées\n");
                continuer();
                break;    
                
            case 'V':  // voir une fiche
            case 'v':
                voirUneFiche(tableau,nb);
                continuer();
                break; 
            case 'S':  // supprimer une fiche
            case 's':
                
                printf("Numero de la fiche à supprimer \n");
                scanf("%u", &numero);
                nb = supprimerAdherent(tableau, numero, nb);
                continuer();
                break;    
                
            case 'Q':
            case 'q':
                return (EXIT_SUCCESS);
                break;    
            default :
                printf("Erreur !\n");
                
        }
                
        
        
    } while (choix != 'Q');
   
    return (EXIT_SUCCESS);
}

