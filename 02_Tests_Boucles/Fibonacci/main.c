/* 
 * File:   main.c
 * Author: psimier
 *
 * Created on 16 novembre 2023, 10:33
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>


int main(int argc, char** argv) {
    
    int nbr = 25;
    int resultat = 0;
    int ancien;
    int ancienAvant;
    double nbOr = 1.61803398875;
    double g;
    double racine5 = sqrt(5);
    
    printf("Combien de lignes ? ");
    scanf (" %d",&nbr);
    printf("\n");
    
    printf("F 0 -> 0\r\n");
    printf("F 1 -> 1\r\n");
    
    if(nbr == 0 || nbr == 1){
        resultat = nbr;
    }else{
        ancien = 1;
        ancienAvant = 0;
        for (int indice = 2; indice <= nbr; indice++){
            resultat = ancien + ancienAvant;
            ancienAvant = ancien;
            ancien = resultat;
            g = pow(nbOr,indice)/ racine5;
            printf("F%2d -> %d -> %.2f\r\n",indice, resultat, g);
        }
    }
 
    return (EXIT_SUCCESS);
}

