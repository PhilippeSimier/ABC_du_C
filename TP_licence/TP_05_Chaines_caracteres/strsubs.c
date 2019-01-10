/* Time-stamp: <subs.c   9 Nov 2000 16:57:18> */

#include <stdio.h>

// Substitution d'une cha�ne dans une autre
// Param�tres : 
//     str : cha�ne modifi�e
//     mot : chaine substitu�e
//     pos : position de la subsitution
//     len : longueur de la subsitution
// Retour : 
//     nombre de caract�res substitu�s
int strsubs(char str[], char mot[], int pos, int len)
{
  int i;			// Position dans str
  int j;			// Position dans motif

  // On v�rifie que la cha�ne str contient au moins pos caract�res
  for (i = 0; str[i] != '\0' && i < pos; i++);
  // Sinon aucun caract�re n'est substitu�
  if (i < pos)
    return 0;

  // Subtitution
  // La substition s'arr�te si 
  //     - la fin de la cha�ne str est atteinte,
  //  ou - la fin de la cha�ne motif est atteinte,
  //  ou - len caract�res ont d�j� �t� substitu�s.
  for (j = 0; str[i] != '\0' && mot[j] != '\0' && j < len; i++, j++)
    str[i] = mot[j];

  return j;			// Nombre de caract�res substitu�s
}
  
int main(void)
{
  char s[] = "bonjour � tous";
  strsubs(s, "soir�e", 3, 4);
  printf("s = \"%s\"\n", s);

  return 0;
}
