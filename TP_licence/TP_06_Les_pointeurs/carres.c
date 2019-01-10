/* Time-stamp: <carres.c  10 Nov 2000 10:36:58> */

#include <stdio.h>

int main(void)
{
  const int n = 10;
  int T[n];
  int i,j;

  // Initialisation
  for (i = 0; i < n; i++)
    T[i] = 0;
  T[1] = T[2] = 1;

  // Calcul 
  for (j = 0; j < 3; j++)
    for (i = 1; i < n; i++)
      T[i] = T[i] + T[i-1];

  // Affichage
   for (i = 0; i < n; i++)
     printf("%d ", T[i]);
    
  return 0;
}
