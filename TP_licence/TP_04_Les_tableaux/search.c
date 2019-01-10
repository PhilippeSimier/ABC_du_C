/* Time-stamp: <exo2.c  17 Oct 2000 09:24:02> */

/* Recherche d'une valeur dans un tableau */

#include <stdio.h>
#include <stdlib.h>

int search(float tab[], int size, float cle)
{
  int i;			/* Indice */

  for (i = 0; i < size; i++)
    if (tab[i] == cle)
      return i;			/* Bingo */
  return -1;			/* Cl� non trouv�e */
}

int main(void)
{
  const int size = 10;		/* Taille du tableau */
  float tab[size];		/* Tableau */
  float x;			/* Cl� � rechercher */
  int i;			/* Indice */

  /* Remplissage du tableau */
  for (i = 0; i < size; i++)
    tab[i] = random();

  /* Affichage du tableau */
  for (i = 0; i < size; i++)
    printf("T[%d] = %f\n", i, tab[i]); 

  /* Saisie de la cl� � rechercher */
  printf("Entrer la cl� : ");
  scanf("%f", &x);

  /* Affichage du r�sultat */
  printf("%d\n", search(tab, size, x));

  return 0;
}
