/****************************************************************************
*       Exercice: Lecture d'une phrase avec scanf
*	Dans scanf l'expression "%[^\n]" : elle indique à l'ordinateur
*       qu'il faut lire le texte tant qu'il n'a pas vu le caractère \n
*       qui indique la fin de la ligne.
*
*	gcc -Wall phrase.c -o phrase
****************************************************************************/
#include <stdio.h>
#include <string.h>

int main()
{
   char buffer[201];
   scanf("%[^\n]", buffer);
   printf("%s\n", buffer);
   return 0;
}
