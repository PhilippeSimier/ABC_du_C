/* Time-stamp: <length.c  28 Nov 2001 10:51:21> */

#include <stdio.h>

/* Calcul de la longueur d'une chaine */
int strlength(char s[])
{
  int i;

  for (i = 0; s[i] != '\0'; i++);
  return i;
}


int main()
{
  if (argc > 1) {
    printf("%d\n", strlength(argv[1]));
  } else {
    printf("length <chaine>\n");
  }
  return 0;
}
