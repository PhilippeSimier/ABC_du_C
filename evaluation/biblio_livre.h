#ifndef BIBLIO_H_INCLUDED
#define BIBLIO_H_INCLUDED

#define NBCARMAX 100
#define NBISBN 13

typedef enum
{
  Roman,Policier,BD,Jeunesse,Loisirs,Sciences
}GENRE;

typedef struct {
  char titre[NBCARMAX+1];
  char auteurs[NBCARMAX+1];
  int annee;
  GENRE type;
  double prix;
  char identifiant[NBISBN+1];
  int quantite;

}LIVRE;

char  cleISBN(char *codeISBN);
int   verificationISBN(char *codeISBN);
void  afficherGenre(GENRE typ);
void  continuer();
void  afficherUnLivre(LIVRE *liv);
LIVRE *creerUnLivre();
int   ajouterUnLivre(LIVRE *tab[], int nb);
void  afficherLivres(LIVRE *liv[], int nb);
int   supprimerUnLivre(LIVRE *tab[], int indice, int nb);
int   supprimerToutLesLivres(LIVRE *tab[], int nb);
int   quelLivre(LIVRE *tab[], int nb);
void  modifieUnLivre(LIVRE *tab[], int nb);
double prixDuStock(LIVRE *tab[], int nb);
void  calculPrix(double taxe1, double taxe2, double *prix);
void  actualiserLivre(LIVRE *tab[], int nb);
void  afficheMenu(LIVRE *tab[], int compteurLivre);
void  enregistrerBase(LIVRE *tab[], int nb);
int   ouvrirBase(LIVRE *tab[], int nb);

#endif // BIBLIO_H_INCLUDED

