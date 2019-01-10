/* Time-stamp: <sample.c  25 Oct 2001 13:41:22> */

/* Calcul récursif des nombres de Fibonacci */

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
