/* Time-stamp: <strlength.c  28 Nov 2001 10:53:32> */

#include <stdio.h>

/* Calcul de la longueur d'une chaîne */
int strlength(char s[])
{
  int i;

  for (i = 0; s[i] != '\0'; i++);
  return i;
}


int main(int argc, char* argv[])
{
  if (argc > 1) {
    printf("%d\n", strlength(argv[1]));
  } else {
    printf("strlength <chaine>\n");
  }
  return 0;
}
