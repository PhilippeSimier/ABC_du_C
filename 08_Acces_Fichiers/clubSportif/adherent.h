#ifndef ADHERENT_H
#define ADHERENT_H

#include <stdio.h>
#include <stdlib.h>
#define MAX 25

typedef enum{NATATION, BASKETBALL, AVIRON, ATHLETISME, TENNIS}
activite;

typedef struct{
    int jour;
    int mois;
    int annee;
}typeDate;

typedef struct{
   char nom[MAX];
   char prenom[MAX];
   typeDate naissance;
   int nbDiscipline;
   activite discipline[5];
   int noLicence;
}typeAdherent;

// Fonction pour afficher le menu
void          afficheMenu(int nbAdherent);
void          continuer();
void          afficherDate(typeDate uneDate);
void          afficherActivite(activite uneActivite);
typeAdherent *creerUnAdherent();
void          afficherAdherent(typeAdherent *unAdherent);
void          afficherAdherents(typeAdherent *tab[],int nb);
int           supprimerUnAdherent(typeAdherent *tab[], int nro, int nb);
// Suite du TP
int           sauvegarderAdherents(typeAdherent *tab[], int nb);
int           chargerAdherents(typeAdherent *tab[ ]);


#endif /* ADHERENT_H */

