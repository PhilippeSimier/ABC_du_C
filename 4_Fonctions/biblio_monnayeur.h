#ifndef BIBLIOTHEQUE_PERSO_H_INCLUDED
#define BIBLIOTHEQUE_PERSO_H_INCLUDED
#define NB 6  // nombre de type de pièces acceptées
#define NBP 11 // nombre de produits que le distributeur peut proposer

void continuer();
float conv(int centime);
int demanderBoisson();
int attendrePiece(int prixBoisson, int pieceUser[]);
int rendrePiece(int rendrePrix, int valPiece[], int nbPiece[], int pieceRendu[]);
void ajouterPiece( int nbPiece[], int pieceUser[]);
void afficherMonnaieRendue(int pieceRendu[], int valPiece[]);
void afficherCaisse( int nbPiece[], int valPiece[]);
#endif // BIBLIOTHEQUE_PERSO_H_INCLUDED
