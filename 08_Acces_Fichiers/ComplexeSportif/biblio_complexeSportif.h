#include <stdio.h>
#include <stdlib.h>

#ifndef BIBLIO_COMPLEXESPORTIF_H
#define BIBLIO_COMPLEXESPORTIF_H
#define TAILLEMAX 50

typedef enum{
    NATATION = 1,
    BASKETBALL,
    HANDBALL,
    SQUASH,
    TENNIS,      
}sport;

void afficherActivite(sport activite);

typedef struct{
    unsigned char jour;   // de 0 à 255
    unsigned char mois;
    unsigned int annee;       
}date;

void afficherDate(date date);

typedef struct{
    char nom[TAILLEMAX];
    char prenom[TAILLEMAX];
    date dateDeNaissance;
    unsigned int nbActivite;
    sport activite[5];
    unsigned int numCarte; 
}typeAdherent;

void afficherUnAdherent(typeAdherent *ad);
void afficherLesAdherents(typeAdherent *tab[],int nb);
void effacerEcran();
void continuer();

typeAdherent *creerUnAdherent();

void afficherMenu(int nbAdhrent);

int sauvegarderAdherents(typeAdherent *tab[], int nb);
int chargerAdherents(typeAdherent *tab[]);
int supprimerAdherent(typeAdherent *tab[], int nro, int nb);
void modifierAdherent(typeAdherent *tab[], int nro, int nb);
int supprimerTousLesAdherents(typeAdherent *tab[], int nb);
void voirUneFiche(typeAdherent *tab[], int nb);



#endif /* BIBLIO_COMPLEXESPORTIF_H */

