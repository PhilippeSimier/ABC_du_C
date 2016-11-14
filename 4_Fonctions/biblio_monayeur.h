#ifndef BIBLIOTHEQUE_PERSO_H_INCLUDED
#define BIBLIOTHEQUE_PERSO_H_INCLUDED

int demanderBoisson();
int attendrePiece(int prixBoisson, int pieceUser[]);
int rendrePiece(int rendrePrix, int valPiece[], int nbPiece[], int pieceRendu[]);
void ajouterPiece( int nbPiece[], int pieceUser[]);
void afficherMonnaieRendue(int pieceRendu[], int valPiece[]);
void afficherCaisse( int nbPiece[], int valPiece[]);
#endif // BIBLIOTHEQUE_PERSO_H_INCLUDED
