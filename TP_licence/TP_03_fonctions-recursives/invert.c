/* Time-stamp: <invert.c  25 Oct 2000 15:13:34> */

/* Inversion d'un tableau */

#include <stdio.h>
#include <stdlib.h>

/* Insertion dans un tableau d�j� tri� */
void invert (float tab[], int size)
{
  int i;			/* Variable d'indice */
  float tmp;			/* Variable temporaire */

  /* On parcourt le tableau jusqu'� la moiti� et chaque 
   * �l�ment est �chang� avec celui en position sym�trique
   */
  for (i = 0; i < size/2; i++) {
    tmp = tab[i];
    tab[i] = tab[size-1-i];
    tab[size-1-i] = tmp;
  }
}

int main(void)
{
  const int size = 4;		/* Taille du tableau */
  float tab[size];		/* Tableau */
  int i;			/* Variable de boucle */

  /* Initialisation du tableau */
  for (i = 0; i < size; i++)
    tab[i] = random();

  /* Affichage du tableau initial */
  for (i = 0; i < size; i++)
    printf("%f ", tab[i]);
  printf("\n");
  
  invert(tab, size);
  /* Affichage du tableau invers� */
  for (i = 0; i < size; i++)
    printf("%f ", tab[i]);
  printf("\n");

  return 0;
}
