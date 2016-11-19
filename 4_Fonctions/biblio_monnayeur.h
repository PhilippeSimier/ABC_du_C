#ifndef BIBLIOTHEQUE_PERSO_H_INCLUDED
#define BIBLIOTHEQUE_PERSO_H_INCLUDED

#define NB 7  // nombre de type de pièces acceptées
#define VALPIECE  {1000, 500, 200, 100, 50, 20, 10} // La valeur des pièces ou billets acceptées en centimes
#define FOND_DE_CAISSE {0, 0, 0 , 1, 1, 4, 5}  // le fond de caisse pièces présente au premier démarrage
#define NBP 11 // nombre de produits que le distributeur peut proposer
#define DESIGNATION_PRODUITS {"Evian", "Coca cola", "Oasis Tropical", "Ice Tea Pêche", "Orangina", "Red Bull", "Schweppes Agrum", "Kinder Bueno", "Lay'S Sel", "Happy Life", "Duo Twix"}
#define PRIX_PRODUITS { 180, 200, 200, 200, 150 ,250 ,200, 180, 100, 200, 150 }

void continuer();
float conv(int centime);
int demanderBoisson();
int attendrePiece(int prixBoisson, int pieceUser[]);
int rendrePiece(int rendrePrix, int pieceCaisse[], int pieceRendu[]);
void ajouterPiece( int pieceCaisse[], int pieceUser[]);
void afficherMonnaieRendue(int pieceRendu[]);
void afficherCaisse( int pieceCaisse[]);

#endif // BIBLIOTHEQUE_PERSO_H_INCLUDED
