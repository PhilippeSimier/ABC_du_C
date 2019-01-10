/* Time-stamp: <insert.c  25 Oct 2000 15:02:36> */

/* Insertion dans un tableau tri� */

#include <stdio.h>

/* Insertion dans un tableau d�j� tri� */
void insert (int tab[], int nbr, int value)
{
  int i;			/* Variable de boucle */

  /* Recherche du point d'insertion et d�calage */
  /* On parcourt le tableau de la droite vers la gauche
   * jusqu'� retrouver le premier �l�ment qui est plus
   * petit que la valeur � ins�rer.  Les �l�ments plus
   * grands que la valeur sont d�cal�s d'une case vers 
   * la droite.
   */
  for (i = nbr-1;  i >=0 && tab[i] > value; i--)
    tab[i+1] = tab[i];
  /* Insertion proprement dite */
  /* En sortie de boucle on a i == -1 ou tab[i] <= value 
   * Dans les deux cas, la valeur doit �tre ins�r�e
   * en tab[i+1].
   */
  tab[i+1] = value;
}

int main(void)
{
  const int size = 100;		/* Taille du tableau */
  int tab[size];		/* Tableau */
  int nbr = 0;			/* Nombre de valeurs ins�r�es */
  int value;			/* Valeur saisie */
  int i;			/* Variable de boucle */

  /* Saisie et insertion des valeurs */
  while (scanf("%d", &value)) 
    insert(tab, nbr++, value);

  /* Affichage du tableau tri� */
  for (i = 0; i < nbr; i++)
    printf("%d ", tab[i]);
  printf("\n");

  return 0;
}
