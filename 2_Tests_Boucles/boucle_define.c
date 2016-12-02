/**************************************************************************
*   La structure repeat n'existe normalement pas en C. Comme elle facilite
*   grandement l'écriture de boucles, nous la construisons
*   avec la ligne commençant #define.
*   compilation:   gcc -std=c99 boucle_define.c -o boucle_define
*
**************************************************************************/

#include <stdio.h>
#define repeat(nb) for (int _loop = 1, _max = (nb); _loop <= _max; _loop++)

int main()
{
   int x;

   printf("Combient de fois voulez vous écrire coucou ? :");
   scanf("%d", &x);
   repeat (x)
   {
      printf("Coucou\n");
   }
}
