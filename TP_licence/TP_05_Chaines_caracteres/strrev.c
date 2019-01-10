/* Time-stamp: <strrev.c   8 Dec 2000 09:10:52> */

#include <stdio.h>

// Échange de deux variables
void swapchar(char* s, char* t)
{
  char tmp;			// Variable d'échange
  
  tmp = *s;
  *s = *t;
  *t = tmp;
}
  
// Renversement d'une chaîne
void strreverse(char *s)
{
  char* t;

  // Recherche de la fin de la chaîne
  // En sortie de cette boucle, le pointeur t
  // pointe sur le '\0' de fin de chaîne
  for (t = s; *t != '\0'; t++);
  
  // Retournement de la chaîne
  // s parcours la chaîne de gauche à droite 
  // t parcours la chaîne de droite à gauche
  // jusqu'à ce que s et t se rejoignent au milieu
  for (t--; s < t; s++, t--)
    swapchar(s, t);
}

 

int main(void)
{

  char s[] = "bonjour à tous";
  strreverse(s);
  printf("s = \"%s\"\n", s);

  return 0;
}
