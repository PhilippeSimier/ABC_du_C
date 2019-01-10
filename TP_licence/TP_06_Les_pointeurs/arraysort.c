/* Time-stamp: <arraysort.c  29 Nov 2001 09:24:58> */

// Tri d'un tableau de chaînes de caractères
// Utilisation du tri par insertion 

#include <stdio.h>
#include <string.h>

void arraysort(char* tab[], int size)
{
  int i;			// Indice de l'élément à insérer 
  int j;			// Indice de la position d'insertion 
  char* save;			// Sauvegarde de l'élément à insérer
  for (i = 1; i < size; i++) {
    // Sauvegarde de l'élément
    save = tab[i];
    // Recherche de la position d'insertion
    for (j = i-1; j >= 0 && strcmp(tab[j], save) > 0; j--)
      tab[j+1] = tab[j];
    // Insertion proprement dite
    tab[j+1] = save;
  }
}
    
int main(int argc, char* argv[])
{
  int i;			/* Variable de boucle */

  // Tri des arguments
  arraysort(argv, argc);

  // Affichage dans l'ordre
  for (i = 0; i < argc; i++)
    printf("argv[%d] = \"%s\"\n", i, argv[i]);


  return 0;
}
