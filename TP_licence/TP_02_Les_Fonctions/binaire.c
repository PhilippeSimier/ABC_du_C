/* Time-stamp: <binaire.c  29 Oct 2001 11:59:14> */

/* Affichage d'un entier en binaire */
    
#include <stdio.h>

// Version récursive 
// L'écriture de n se décompose en 
//  - l'écriture de n/2 si n > 1
//  - le chiffre des unités (0 ou 1)
void binairerec(int n)
{
  if (n > 1)
    binairerec(n/2);
  printf("%d", n%2);
}

// Version itérative
// On utilise un tableau pour stocker les chiffres
void binaireite(int n)
{
  int e;			// Exposant

  // On suppose que les entiers n'ont pas plus de 32 bits
  int bits[32];

  // Remplissage du tableau
  for (e = 0; n > 0; n = n/2, e++)
    bits[e] = n%2;		// Bit de 2^e

  // Affichage du tableau en partant du bit de poids fort
  for (e--; e >= 0; e--)
    printf("%d", bits[e]);	// Affichage du bit de 2^e
}
	   
int main(void)
{
  int n;

  // Saisie de n
  printf("n : ");
  scanf("%d", &n);
  // Affichage en utilisant la version récursive
  binairerec(n);
  printf("\n");
  // Affichage en utilisant la version itérative
  binaireite(n);
  printf("\n");

  return 0;
}
