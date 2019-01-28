/*
 * File:   main.c
 * Author: psimier
 *
 * Created on 28 janvier 2019, 11:06
 */

#include <stdio.h>
#include <stdlib.h>

void afficherNombre(int n, int base){

    if (n < 0){
        putchar('-');
        n = -n;
    }
    int i = n/base;
    if(i != 0){

        afficherNombre(i, base);
        putchar(' ');
    }
    if (n % base < 10) 
        putchar(n % base + '0');
    else
        putchar(n % base + 'A' - 10);
}

int main(int argc, char** argv) {
    int n = 255;
    afficherNombre(n, 16); 
    putchar('\n');
    afficherNombre(n, 8);
    putchar('\n');
    afficherNombre(n, 2);
    putchar('\n');
    return (EXIT_SUCCESS);
}
