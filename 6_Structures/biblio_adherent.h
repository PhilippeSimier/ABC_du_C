#ifndef BIBLIO_H_INCLUDED
#define BIBLIO_H_INCLUDED
#define TAILLEMAX 50

typedef struct{
    char nom[TAILLEMAX];
    char prenom[TAILLEMAX];
    char numCarte[TAILLEMAX];
    unsigned int numActivite;
}typeAdherent;

void continuer();

typeAdherent *nouvelAdherent();

void afficherUnAdherent(typeAdherent *adherent[], char numCarteAdherent[], int indiceAdherent);

#endif // BIBLIO_H_INCLUDED
