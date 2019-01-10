/* Time-stamp: <map.c  30 Oct 2000 20:29:15> */

#include <stdio.h>
#include <stdlib.h>

/*
 * Fonction map
 * [x_0,x_1,...,x_n] -> [f(x_0),f(x_1),...,f(x_n)] 
 */
void map(int f(int), int tab[], int size)
{
  int i;			/* Variable d'indice */

  /* Parcours  du tableau */
  /* La fonction f est appliqué à chacun des éléments du tableau */
  for (i = 0; i < size; i++) 
    tab[i] = f(tab[i]);
}

/*
 * Fonction itarray (version itérative)
 * [x_0,x_1,...,x_n] ->  f(f(...f(f(x_0,x_1),x_2)...)x_n)
 */
int itarray(int f(int, int), int tab[], int size)
{
  int result = tab[0];		/* Résultat partiel */
  int i;			/* Variable d'indice */

  for (i = 1; i < size; i++)
    result = f(result, tab[i]);

  return result;
}

/*
 * Fonction itarray (version récursive)
 * [x_0,x_1,...,x_n] ->  f(f(...f(f(x_0,x_1),x_2)...)x_n)
 */
int itarrayrec(int f(int, int), int tab[], int size)
{
  if (size == 1)
    return tab[0];
  else 
    return f(itarrayrec(f, tab, size-1), tab[size-1]);
}

/* 
 * Fonction Maximum
 */
int max(int i, int j)
{
  return i > j ? i : j;
}
/* 
 * Fonction Somme
 */
int sum(int i, int j)
{
  return i + j;
}

/* 
 * Fonction produit
 */
int prod(int i, int j)
{
  return i * j;
}

int main(void)
{
  const int size = 10;		/* Taille du tableau */
  int tab[size];		/* Tableau proprement dit */
  int i;			/* Variable de boucle */


  /* Initialisation du tableau */
  for (i = 0; i < size; i++) 
    tab[i] = random()/(RAND_MAX/100);

  /* Affichage du tableau */
  for (i = 0; i < size; i++) 
    printf("%d ", tab[i]);
  printf("\n");

  /* Affichage des résultats */
  printf("Maximum = %d\n", itarray(max, tab, size));
  printf("Somme   = %d\n", itarray(sum, tab, size));
  printf("Produit = %d\n", itarray(prod, tab, size));

  return 0;
}
