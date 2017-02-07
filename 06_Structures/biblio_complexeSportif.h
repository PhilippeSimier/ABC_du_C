#ifndef BIBLIO_H_INCLUDED
#define BIBLIO_H_INCLUDED

#define NBSPORT 5
#define TAILLEMAX 50

#define VERT   "\033[1;32m"
#define RESET  "\033[1;0m"

#define NOIR 0
#define ROUGE 1
//#define VERT 2
#define JAUNE 3
#define BLEU 4
#define MAGENTA 5
#define CYAN 6
#define BLANC 7
#define ESC x1B

typedef enum{
    NATATION = 1,
    BASKETBALL,
    HANDBALL,
    SQUASH,
    TENNIS
}sport;

typedef struct{
    int jour;
    int mois;
    int annee;
}date;

typedef struct{
    char nom[TAILLEMAX];
    char prenom[TAILLEMAX];
    date dateDeNaissance;
    int nbActivite;
    sport activite[NBSPORT];
    int numCarte;
}typeAdherent;

void afficher_couleur(int, int, char *chaine);

void effacerEcran();

void continuer();

void afficherMenu(int);

void afficherDate(date);

void afficherActivite(sport);

typeAdherent *creerUnAdherent();

void afficherUnAdherent(typeAdherent *adherent[], int, int);

void afficherAdherents(typeAdherent *tad[], int);

int ajouterUnAdherent(typeAdherent *tab[], int);

int supprimerUnAdherent(typeAdherent *tab[], int, int);

int supprimerAdherents(typeAdherent *tab[], int);

void modifierFiche(typeAdherent *tab[], int, int);

int chargerAdherents(typeAdherent *ad[], int);

void sauvegardeAdherents(typeAdherent *ad[], int);

#endif // BIBLIO_H_INCLUDED
