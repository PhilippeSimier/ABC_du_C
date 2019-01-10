/* Time-stamp: <exo4.c  16 Oct 2000 19:51:12> */

/* Comptage d'entiers positifs et calcul de la somme et du maximum */

#include <stdio.h>

int main(void)
{
  int n;			/* Entier saisi */
  int nbr = 0;			/* Compteur */
  int sum = 0;			/* Somme */
  int max;			/* Maximum */
  int scan;			/* Nombre de valeurs saisies par scanf */

  /* Saisie d'un premier entier pour initialiser le max */
  printf("Entrer un entier : ");
  scan = scanf("%d", &n);
  max = n;

  /* Saisie d'autres entiers */
  while (scan > 0) {
    /* Mise à jour */
    nbr++;
    sum += n;
    if (n > max)
      max = n;

    /* Saisie d'un nouvel entier */
    printf("Entrer un entier : ");
    scan = scanf("%d", &n);
  }
  printf("Compteur = %d, somme = %d, maximum = %d\n", nbr, sum, max);
  
  return 0;
}
