/*
 * Ecrire un programme qui lit une ligne de texte sur l'entrée standard,
 * et affiche cette ligne retournée, c'est-à-dire en commençant
 * par le dernier caractère.
 * Votre programme doit impérativement utiliser une fonction récursive,
 * et non une boucle..
 */

/*
 * File:   main.c
 * Author: psimier
 *
 * Created on 28 janvier 2019, 11:06
 */

#include <stdio.h>
#include <stdlib.h>



void retournerChaine()
{
   char lu;
   scanf("%c", &lu);
   if (lu == '\n')
      return;
   retournerChaine();
   printf("%c", lu);
}

int main(int argc, char** argv) {

    retournerChaine();
    putchar('\n');
    return (EXIT_SUCCESS);
}
