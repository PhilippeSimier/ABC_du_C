/*
 * Écrire un programme qui lit deux entiers sur l'entrée, 
 * et qui affiche le premier entier, entouré d'autant de paires de crochets '[' et ']', 
 * qu'indiqué par la valeur du deuxième nombre.
 */

/* 
 * File:   main.c
 * Author: Philippe Simier
 *
 * Created on 29 janvier 2019, 19:54
 */

#include <stdio.h>
#include <stdlib.h>

void boucle(int i, char nombre) {
if (i > 0) {
    printf ("[");
    boucle(i - 1, nombre);
    printf ("]");
}
//sinon on ne relance pas => fin du programme
else
    printf("%d", nombre);
return;
}

int main(int argc, char** argv) {
    int nombre, nb;
    scanf("%d %d", &nombre, &nb);
    boucle(nb, nombre);
    putchar('\n');
    return (EXIT_SUCCESS);
}
