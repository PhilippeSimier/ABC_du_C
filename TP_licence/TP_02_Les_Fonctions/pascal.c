/* Time-stamp: <pascal.c  23 Oct 2000 13:54:46> */

/* Calcul du triangle de Pascal */

#include <stdio.h>

/* 
 * Calcul et affichage des n premières lignes
 * avec un tableau à deux dimensions
 */
void pascal1(int n)
{
  int l;			/* Indice de lignes */
  int c;			/* Indice de colonnes */
  int p[n][n];			/* Le tableau */

  /* Calcul du tableau */
  for (l = 0; l < n; l++) {
    p[l][0] = 1;		/* Colonne 0 */
    p[l][l] = 1;		/* Colonne l */
    /* Colonne de 1 à l-1 */
    for (c = 1; c < l; c++)
      p[l][c] = p[l-1][c-1] + p[l-1][c];
  }

  /* Affichage */
  for (l = 0; l < n; l++) {
    for (c = 0; c <= l; c++)
      printf("%d\t", p[l][c]);
    printf("\n");
  }
}
	     
/* 
 * Calcul et affichage des n premières lignes
 * avec deux tableaux à une dimension
 */
void pascal2(int n)
{
  int l;			/* Indice de lignes */
  int c;			/* Indice de colonnes */
  int tab1[n];			/* Le premier tableau */
  int tab2[n];			/* Le deuxième  tableau */
  int* connue = tab1;		/* Ligne connue */
  int* calcul = tab2;		/* Ligne calculée */
  int* tmp;			/* Variable d'échange */
  
  /* Calcul et affichage du tableau */
  connue[0] = 0;		/* Ligne 0 */
  printf("%d\n", connue[0]);
  for (l = 1; l < n; l++) {

    /* Calcul de la nouvelle ligne */
    calcul[0] = 1;		/* Colonne 0 */
    calcul[l] = 1;		/* Colonne l */
    /* Colonne de 1 à l-1 */
    for (c = 1; c < l; c++)
      calcul[c] = connue[c-1] + connue[c];

    /* Échange de la ligne connue et de la ligne calculée */
    tmp = connue;
    connue = calcul;
    calcul = tmp;

    /* Affichage de la ligne connue */
    for (c = 0; c <= l; c++)
      printf("%d\t", connue[c]);
    printf("\n");
     
  }
}

/* 
 * Calcul et affichage des n premières lignes
 * avec un tableau à une dimension
 */
void pascal3(int n)
{
  int l;			/* Indice de lignes */
  int c;			/* Indice de colonnes */
  int tab[n];			/* Le tableau */
  
  /* Calcul et affichage du tableau */
  tab[0] = 1;		/* Ligne 0 */
  printf("%d\n", tab[0]);
  for (l = 1; l < n; l++) {

    /* Calcul de la nouvelle ligne */
    tab[l] = 1;			/* Colonne l */
    /* Colonne de 1 à l-1 */
    for (c = l-1; c > 0; c--)
      tab[c] = tab[c-1] + tab[c];

    /* Affichage de la ligne connue */
    for (c = 0; c <= l; c++)
      printf("%d\t", tab[c]);
    printf("\n");
     
  }
}

     
    
int main(void)
{
  pascal1(10);
  pascal2(10);
  pascal3(10);
  return 0;
}
