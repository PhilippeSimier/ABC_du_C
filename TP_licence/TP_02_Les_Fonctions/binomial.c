/* Time-stamp: <binomial.c  21 avr 2003 12:34:48> */

#include <stdio.h>

// Fonction factorielle
// Version récursive 
int factrec(int n)
{
  if (n <= 1)
    return 1;
  else
    return n * factrec(n-1);
}

// Version itérative
// Avec des entiers sur 32 bits, la plus grande valeur qui puisse
// être calculée est 12! = 479001600.
// Pour n >= 34, la valeur calculée par l'algorithme est 0.
// La valuation 2-adique de n! est 
//         [n/2] + [n/4] + [n/8] + [n/16] + [n/32] + ···
// 34 est le plus petit entier pour lequel cette valuation vaut 32.
// 34 est le plus petit entier n tel que 2^32 divise n!.
int fact(int n)
{
  int f;			// Résultat

  for (f = 1; n > 1; n--)
    f *= n;			// Identique à f = f * n;
  return f;
}


// Calcul d'un coefficient binômial
// Première version en utilisant la formule directe C^p_n = n!/p!(n-p)!
// Cet algorithme nécessite 2n-1 multiplications et 1 division.
// On est limité à n <= 12.
int binomial1(int n, int p)
{
  return fact(n)/(fact(p)*fact(n-p));
}

// Calcul d'un coefficient binômial
// Méthode utilisée
// - En utilisant la formule C^p_n = C^{n-p}_n, on se ramène au cas
//   où p <= n-p pour minimiser le nombre d'opérations.
//            n(n-1)(n-2)...(n-p+1)
// -  C^p_n = ---------------------
//              p(p-1)(p-2)... 1
// Cet algorithme nécessite 2(p-1) multiplications et 1 division.
// L'inconvénient de cette méthode est que le calcul du numérateur
// peut provoquer un débordement alors que la valeur de C^p_n est
// inférieure à la valeur maximal d'un entier.  
// Avec cet algorithme, on peut calculer C^7_14 = 3432.  Par contre,
// on ne peut pas calculer C^9_18 car le numérateur vaut 17643225600.
int binomial2(int n, int p)
{
  int num;			// Numérateur
  int k;			// Variable d'itération

  // On se ramène au cas où p <= n-p
  if (p > n-p) 
    p = n-p;

  // Calcul du numérateur
  for (num = 1, k = n-p+1; k <= n; k++)
    num *= k;

  // Calcul du binômial
  return num/fact(p);
}

// Calcul d'un coefficient binômial
// Méthode utilisée
// - En utilisant la formule C^p_n = C^{n-p}_n, on se ramène au cas
//   où p <= n-p pour minimiser le nombre d'opérations.
// -  C^p_n = (n/p) C^{p-1}_{n-1}
// Cet algorithme nécessite p-1 multiplications et p-1 divisions.
// Avec cet algorithme, on peut calculer C^9_18 = 48620 et même C^14_28.
// Par contre, on ne peut toujours pas calculer C^15_30 = 155117520.
int binomial3(int n, int p)
{
  int binom;			// Résultat
  int k;			// Variable d'itération

  // On se ramène au cas où p <= n-p
  if (p > n-p) 
    p = n-p;

  // k     prend les valeurs     1 ... p
  // n-p+k prend les valeurs n-p+1 ... n
  for (binom = 1, k = 1; k <= p; k++)
    // Il est important de faire la mutiplication avant la division.
    // Le résultat intermédiaire binom/k n'est pas nécessairement un 
    // entier.
    binom = (binom * (n-p+k)) / k;

  return binom;
}

int main(void)
{
  int p,n;

  // Saisie de p
  printf("p : ");
  scanf("%d", &p);
  // Saisie de n
  printf("n : ");
  scanf("%d", &n);

  // Calcul et affichage
  printf("Version 1 : C_^%d_%d = %d\n", p, n, binomial1(n, p));
  printf("Version 2 : C_^%d_%d = %d\n", p, n, binomial2(n, p));
  printf("Version 3 : C_^%d_%d = %d\n", p, n, binomial3(n, p));

  return 0;
}
