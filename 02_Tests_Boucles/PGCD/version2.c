/* 
 * File:   main.c
 * Author: psimier
 * Abstrac: Programme pour calculer le PGCD de deux nombres entiers
 *          Algorithme d'Euclide
 *
 * Created on 30 novembre 2023, 10:34
 */

#include <stdio.h>
#include <stdlib.h>

// Prototype
int obtenirReste(int dividende, int diviseur);

int main(int argc, char** argv) {

    // Lire dividende et diviseur
    int dividende, diviseur;

    printf("Donner deux nombres entiers ? ");
    scanf(" %d %d", &dividende, &diviseur);
    if (diviseur > dividende){
        // Permutation
        int temp = diviseur;  // etape 1
        diviseur = dividende; // étape 2
        dividende = temp;     // étape 3
    }

    printf("%d %d\n", dividende, diviseur);

    int memo;
    while (diviseur != 0) {
        memo = diviseur;

        int reste = dividende;
        diviseur = dividende % diviseur;

        dividende = memo;
    }

    printf("PGCD est %d ", dividende);

    return (EXIT_SUCCESS);
}

int obtenirReste(int dividende, int diviseur) {

    int reste = dividende;

    do {
        reste = reste - diviseur;
    } while (reste >= diviseur);

    return reste;
}

