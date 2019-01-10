/* Time-stamp: <subs.c   9 Nov 2000 16:57:18> */

#include <stdio.h>

// Substitution d'une chaîne dans une autre
// Paramètres : 
//     str : chaîne modifiée
//     mot : chaine substituée
//     pos : position de la subsitution
//     len : longueur de la subsitution
// Retour : 
//     nombre de caractères substitués
int strsubs(char str[], char mot[], int pos, int len)
{
  int i;			// Position dans str
  int j;			// Position dans motif

  // On vérifie que la chaîne str contient au moins pos caractères
  for (i = 0; str[i] != '\0' && i < pos; i++);
  // Sinon aucun caractère n'est substitué
  if (i < pos)
    return 0;

  // Subtitution
  // La substition s'arrête si 
  //     - la fin de la chaîne str est atteinte,
  //  ou - la fin de la chaîne motif est atteinte,
  //  ou - len caractères ont déjà été substitués.
  for (j = 0; str[i] != '\0' && mot[j] != '\0' && j < len; i++, j++)
    str[i] = mot[j];

  return j;			// Nombre de caractères substitués
}
  
int main(void)
{
  char s[] = "bonjour à tous";
  strsubs(s, "soirée", 3, 4);
  printf("s = \"%s\"\n", s);

  return 0;
}
