/* Time-stamp: <exo2.c  16 Oct 2000 19:51:40> */

/* Affichage de la valeur absolue */

#include <stdio.h>

int main(void)
{
  int n;

  /* Saisie */
  printf("Entrer un entier : ");
  scanf("%d", &n);
  /* Calcul et affichage */
  if (n < 0)
    n = -n;
  printf("Abs = %d\n", n);

  return 0;
}
