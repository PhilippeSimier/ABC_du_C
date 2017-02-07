/**********************************************************************
*       1. programme permettant d'afficher l'ensembles des arguments
*          passés en ligne de commande
*
*
*       Compilation: gcc -std=c11 -Wall affiche.c -o affiche
**********************************************************************/
#include<stdio.h>
#include<stdlib.h>

int main(int argc, char *argv[]){

    for (int i = 0; i <argc; i++){
	printf("argv[%d] : %s\n",i ,argv[i]);
    }
    return 0;
}
