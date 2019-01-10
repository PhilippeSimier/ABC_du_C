/* Time-stamp: <array.c  24 Nov 2000 09:39:36> */

#include <stdio.h>
#include <stdlib.h>

typedef struct {
  int* tab;
  int size;
} Array;

Array arrayAlloc(int size)
{
  Array a;

  // Taille
  a.size = size;

  // Allocation du tableau
  if (size > 0)
    a.tab = (int *) malloc (size * sizeof(int));
  else
    a.tab = 0;

  return a;
}  

// Lib�ration d'un tableau
void arrayFree(Array* a)
{
  if (a->size > 0) {
    free(a->tab);
  }
}

// Acc�s � la valeur d'un �l�ment du tableau
int get(Array a, int i)
{
  // V�rification des bornes
  if (i < 0 || a.size <= i) {
    printf("Erreur de borne\n");
    return 0;
  }
  return a.tab[i];
}

// Acc�s � un �l�ment du tableau
// Il est possible de passer la structure Array
// par valeur puisque c'est la zone m�moire 
// sur laqu'elle pointe qui est modifi�e.
void set(Array a, int i, int value)
{
  // V�rification des bornes
  if (i < 0 || a.size <= i) {
    printf("Erreur de borne\n");
  }
  a.tab[i] = value;
}

// Acces � un �l�ment du tableau
// Utilisation d'un pointeur
int* arrayAccesP(Array a, int i)
{
  // V�rification des bornes
  if (i < 0 || a.size <= i) {
    printf("Erreur de borne\n");
    return 0;
  }
  return a.tab + i;
}
	   
// Acces � un �l�ment du tableau
// Utilisation d'une r�f�rence
int& arrayAccesR(Array& a, int i)
{
  // V�rification des bornes
  if (i<0 || a.size<=i)
  {
    printf("Erreur de borne\n");
    exit(1);
  }
  return a.tab[i];
}

// Il suffit d'echanger les adresses des blocs memoires ou sont stockees
// les vaeurs des tableaux.  Il est inutile d'allouer une zone memoire pour
// la variable intermediare *tmp car elle pointe sur rien, elle sert juste
// de transfert.
void arraySwap(Array& a, Array& b)	
{
  int stmp;			// Variable d'�change
  int *ttmp;			// Variable d'�change

  // �change des tailles
  stmp    = a.size;
  a.size = b.size;
  b.size = stmp;
  // �change des tableaux
  ttmp    = a.tab;
  a.tab  = b.tab;
  b.tab  = ttmp;
}	

// Concat�nation de deux tableaux
Array arrayConcat(Array& a, Array& b)
{
  int i;			// Parcours de A et B
  int j = 0;			// Parcours de C
  Array c = arrayAlloc(a.size + b.size);

  // Recopie de A dans C
  for (i = 0; i < a.size; i++, j++)
    c.tab[j] = a.tab[i];
  // Recopie de B dans C
  for (i = 0; i < b.size; i++, j++)
    c.tab[j] = b.tab[i];
	
  return c;	
}	

// Saisie d'un tableau
Array arrayScan(int size)
{
  int i;			// Variable de boucle
  Array a = arrayAlloc(size);	// Allocation du tableau

  for (i = 0; i < a.size; i++)
    scanf("%d", a.tab+i);
  
  return a;
}

// Affichage d'un tableau
void arrayPrint(Array& a)
{
  int i;			// Variable de boucle

  for (i = 0; i < a.size; i++)
    printf("%d ", a.tab[i]);
  printf("\n");	
}

int main(void)
{
  const int size = 2;
  Array A,B,C,D;
	
  A = arrayScan(size);
  printf("A : "); arrayPrint(A);
  B = arrayScan(size);
  printf("B : "); arrayPrint(B);
	
  arraySwap(A, B);
  printf("A : "); arrayPrint(A);
  printf("B : "); arrayPrint(B);
  arraySwap(A, B);
  printf("A : "); arrayPrint(A);
  printf("B : "); arrayPrint(B);
	
  C = arrayConcat(A,B);
  printf("C : "); arrayPrint(C);
  D = arrayConcat(C,C);
  printf("D : "); arrayPrint(D);

  return 0;
}
