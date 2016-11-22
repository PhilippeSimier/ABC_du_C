#ifndef BIBLIO_H_INCLUDED
#define BIBLIO_H_INCLUDED
#define TAILLEMAX 13

typedef struct{
    char nom[TAILLEMAX];
    char prenom[TAILLEMAX];
    unsigned int annee;
    float taille;
    float poids;
}typePersonne;

// 3 -  la fonction creePersonnePtr  retourne un pointeur sur une personne
typePersonne *creePersonnePtr();

// 4 - Affiche la fiche d'un personne passée par pointeur
void affichePersonnePtr(typePersonne *personne);

#endif // BIBLIO_H_INCLUDED
