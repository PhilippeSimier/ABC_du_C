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

int main(int argc, char** argv) {

    // Lire dividende
    int dividende;
    printf("Dividende ? ");
    scanf(" %d", &dividende);

    // Lire diviseur
    int diviseur;
    do {
        printf("Diviseur ? ");
        scanf(" %d", &diviseur);
    }    while (diviseur > dividende);
    
    printf("%d %d\n", dividende, diviseur);
    
    int memo;
    while(diviseur != 0){
        memo = diviseur;
        
        int reste = dividende;
        do{
            reste = reste - diviseur;
        }       
        while(reste >= diviseur);
        diviseur = reste;
        
        // ou diviseur = dividende % diviseur;
               
        dividende = memo;        
    }
    
    printf("PGCD est %d ", dividende);

    return (EXIT_SUCCESS);
}

