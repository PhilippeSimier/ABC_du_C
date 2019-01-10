/* Time-stamp: <fibonacci.c  25 Oct 2000 15:15:42> */

/* Calcul récursif des nombres de Fibonacci */

// Evaluation du nombre d'appels récursifs 
// =======================================
// Soit A_n le nombre d'appels récursifs pour calculer F_n
// D'après l'écriture de la fonction
// On a A_0 = 1 et A_1 = 1 
//   et A_n = 1 + A_{n-1} + A_{n-2}
// 
// On vérifie par récurrence que A_n = 2F_n - 1

#include <stdio.h>

int fibo(int n)
{
  if (n == 0 || n == 1)
    return 1;
  else 
    return fibo(n-1) + fibo(n-2);
}

int main(void)
{
  int k = 4;

  printf("%d", fibo(k));
  return 0;
}
