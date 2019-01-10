/* Time-stamp: <binomial.c  21 avr 2003 12:34:48> */

#include <stdio.h>

// Fonction factorielle
// Version r�cursive 
int factrec(int n)
{
  if (n <= 1)
    return 1;
  else
    return n * factrec(n-1);
}

// Version it�rative
// Avec des entiers sur 32 bits, la plus grande valeur qui puisse
// �tre calcul�e est 12! = 479001600.
// Pour n >= 34, la valeur calcul�e par l'algorithme est 0.
// La valuation 2-adique de n! est 
//         [n/2] + [n/4] + [n/8] + [n/16] + [n/32] + ���
// 34 est le plus petit entier pour lequel cette valuation vaut 32.
// 34 est le plus petit entier n tel que 2^32 divise n!.
int fact(int n)
{
  int f;			// R�sultat

  for (f = 1; n > 1; n--)
    f *= n;			// Identique � f = f * n;
  return f;
}


// Calcul d'un coefficient bin�mial
// Premi�re version en utilisant la formule directe C^p_n = n!/p!(n-p)!
// Cet algorithme n�cessite 2n-1 multiplications et 1 division.
// On est limit� � n <= 12.
int binomial1(int n, int p)
{
  return fact(n)/(fact(p)*fact(n-p));
}

// Calcul d'un coefficient bin�mial
// M�thode utilis�e
// - En utilisant la formule C^p_n = C^{n-p}_n, on se ram�ne au cas
//   o� p <= n-p pour minimiser le nombre d'op�rations.
//            n(n-1)(n-2)...(n-p+1)
// -  C^p_n = ---------------------
//              p(p-1)(p-2)... 1
// Cet algorithme n�cessite 2(p-1) multiplications et 1 division.
// L'inconv�nient de cette m�thode est que le calcul du num�rateur
// peut provoquer un d�bordement alors que la valeur de C^p_n est
// inf�rieure � la valeur maximal d'un entier.  
// Avec cet algorithme, on peut calculer C^7_14 = 3432.  Par contre,
// on ne peut pas calculer C^9_18 car le num�rateur vaut 17643225600.
int binomial2(int n, int p)
{
  int num;			// Num�rateur
  int k;			// Variable d'it�ration

  // On se ram�ne au cas o� p <= n-p
  if (p > n-p) 
    p = n-p;

  // Calcul du num�rateur
  for (num = 1, k = n-p+1; k <= n; k++)
    num *= k;

  // Calcul du bin�mial
  return num/fact(p);
}

// Calcul d'un coefficient bin�mial
// M�thode utilis�e
// - En utilisant la formule C^p_n = C^{n-p}_n, on se ram�ne au cas
//   o� p <= n-p pour minimiser le nombre d'op�rations.
// -  C^p_n = (n/p) C^{p-1}_{n-1}
// Cet algorithme n�cessite p-1 multiplications et p-1 divisions.
// Avec cet algorithme, on peut calculer C^9_18 = 48620 et m�me C^14_28.
// Par contre, on ne peut toujours pas calculer C^15_30 = 155117520.
int binomial3(int n, int p)
{
  int binom;			// R�sultat
  int k;			// Variable d'it�ration

  // On se ram�ne au cas o� p <= n-p
  if (p > n-p) 
    p = n-p;

  // k     prend les valeurs     1 ... p
  // n-p+k prend les valeurs n-p+1 ... n
  for (binom = 1, k = 1; k <= p; k++)
    // Il est important de faire la mutiplication avant la division.
    // Le r�sultat interm�diaire binom/k n'est pas n�cessairement un 
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
