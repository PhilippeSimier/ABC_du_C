
#include <stdio.h>
#include <stdlib.h>
#include "adherent.h"
#define MAXELEM 5000

int main(int argc, char** argv) {
    typeAdherent* tableau[MAXELEM];  // Q9
    int compteurAdherent = 0;   // Q10
    char choix;
    int i=0;
    int nb;
    
    compteurAdherent = chargerAdherents(tableau);
    do{
        system("clear");  // efface l'écran
        afficheMenu(compteurAdherent);
        scanf(" %c", &choix);
        switch(choix){
            case 'A':
              tableau[compteurAdherent] = creerUnAdherent();
              compteurAdherent++;  
              break;
              
            case 'V':
              printf("Numéro de licence de l'adhérent : ");
              scanf("%d", &i);  
              afficherAdherent(tableau[i]);
              continuer();
              break;
              
            case 'L':
               
              afficherAdherents(tableau, compteurAdherent);
              continuer();
              break;
            
            case 'S':
              printf("Numéro de licence de l'adhérent : ");
              scanf("%d", &i);  
              compteurAdherent = supprimerUnAdherent(tableau, i, compteurAdherent);
              continuer();
              break;
              
            case 'W':
              nb = sauvegarderAdherents(tableau, compteurAdherent);
              if (nb != compteurAdherent){
                printf("Erreur sauvegarde\n");  
              }
              break;
               
              
        }
        
    }
    while(choix != 'Q');

    return (EXIT_SUCCESS);
}

