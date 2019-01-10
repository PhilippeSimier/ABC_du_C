/* Time-stamp: <insert.c  25 Oct 2000 15:02:36> */

/* Insertion dans un tableau trié */

#include <stdio.h>

/* Insertion dans un tableau déjà trié */
void insert (int tab[], int nbr, int value)
{
  int i;			/* Variable de boucle */

  /* Recherche du point d'insertion et décalage */
  /* On parcourt le tableau de la droite vers la gauche
   * jusqu'à retrouver le premier élément qui est plus
   * petit que la valeur à insérer.  Les éléments plus
   * grands que la valeur sont décalés d'une case vers 
   * la droite.
   */
  for (i = nbr-1;  i >=0 && tab[i] > value; i--)
    tab[i+1] = tab[i];
  /* Insertion proprement dite */
  /* En sortie de boucle on a i == -1 ou tab[i] <= value 
   * Dans les deux cas, la valeur doit être insérée
   * en tab[i+1].
   */
  tab[i+1] = value;
}

int main(void)
{
  const int size = 100;		/* Taille du tableau */
  int tab[size];		/* Tableau */
  int nbr = 0;			/* Nombre de valeurs insérées */
  int value;			/* Valeur saisie */
  int i;			/* Variable de boucle */

  /* Saisie et insertion des valeurs */
  while (scanf("%d", &value)) 
    insert(tab, nbr++, value);

  /* Affichage du tableau trié */
  for (i = 0; i < nbr; i++)
    printf("%d ", tab[i]);
  printf("\n");

  return 0;
}
