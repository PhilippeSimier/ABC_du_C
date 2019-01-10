/* Time-stamp: <strrev.c   8 Dec 2000 09:10:52> */

#include <stdio.h>

// �change de deux variables
void swapchar(char* s, char* t)
{
  char tmp;			// Variable d'�change
  
  tmp = *s;
  *s = *t;
  *t = tmp;
}
  
// Renversement d'une cha�ne
void strreverse(char *s)
{
  char* t;

  // Recherche de la fin de la cha�ne
  // En sortie de cette boucle, le pointeur t
  // pointe sur le '\0' de fin de cha�ne
  for (t = s; *t != '\0'; t++);
  
  // Retournement de la cha�ne
  // s parcours la cha�ne de gauche � droite 
  // t parcours la cha�ne de droite � gauche
  // jusqu'� ce que s et t se rejoignent au milieu
  for (t--; s < t; s++, t--)
    swapchar(s, t);
}

 

int main(void)
{

  char s[] = "bonjour � tous";
  strreverse(s);
  printf("s = \"%s\"\n", s);

  return 0;
}
