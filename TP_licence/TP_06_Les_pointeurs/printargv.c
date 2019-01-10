/* Time-stamp: <printargv.c  28 Nov 2001 17:46:40> */

/* Affichage des arguments de la ligne de commande */

#include <stdio.h>

int main(int argc, char* argv[])
{
  int i;			/* Variable de boucle */

  for (i = 0; i < argc; i++)
    printf("argv[%d] = \"%s\"\n", i, argv[i]);

  return 0;
}
