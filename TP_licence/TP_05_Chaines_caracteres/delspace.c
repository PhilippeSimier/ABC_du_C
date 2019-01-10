/* Time-stamp: <delspace.c  29 Nov 2001 15:55:51> */

// Effacement des des epsqces et des tabulations

#include <stdio.h>

void delspace(char s[])
{
  int r;			// Indice de lecture
  int w;			// Indice d'écriture

  for (w = r = 0; s[r] != '\0'; r++)
    if (s[r] != ' ' && s[r] != '\t') {
      s[w] = s[r];
      w++;
    }
  // Mise en place de la fin de la chaîne
  s[w] = '\0';
}

int main(int argc, char* argv[])
{
  if (argc > 1) {
    delspace(argv[1]);  
    printf("chaine = \"%s\"\n", argv[1]);
  } else {
    printf("delspace <chaine>\n");
  }

  return 0;
}
