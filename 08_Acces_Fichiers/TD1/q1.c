/* 
 * File:   main.c
 * Author: psimier
 *
 * Created on 4 janvier 2021, 11:03
 * Compilation gcc q1.c -o q1
 */

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

void afficherErreur();

int main(int argc, char** argv) {
    
    FILE* fp;
    
    fp = fopen("essai.txt","w");
    if (fp == NULL) 
        afficherErreur();

    int nb = fputs("bonjour\n", fp);
    printf("Valeur de retour fputs: %d ", nb);
    fclose(fp);

    return (EXIT_SUCCESS);
}

void afficherErreur(){
    if(errno != 0){
        printf("Erreur : %s\n", strerror(errno));
        exit(errno);
    }
}
