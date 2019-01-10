/* Time-stamp: <exo1.c  16 Oct 2000 19:52:02> */

/* Un premier programme */

#include <stdio.h>

int main(void)
{
  float f;			/* Pour la saisie */
  float g;			/* Pour le résultat */

  printf("Entrer un flottant : ");
  scanf("%f", &f);
  g = f * 3;
  printf("3 * %f = %f\n", f, g);
    
  return 0;
}
