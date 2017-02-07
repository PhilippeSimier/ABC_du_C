/****************************************************************************
*  Librairie Gestion des livres
*
*  Compilation :
*  gcc -Wall -std=c11 livre.c biblio_livre.c -o livre
*****************************************************************************/
#include "biblio_livre.h"

int main()
{
  int compteurLivre=0;
  LIVRE *tab[5000];
  compteurLivre = ouvrirBase(tab, compteurLivre);
  afficheMenu(tab, compteurLivre);
  return 0;
}

