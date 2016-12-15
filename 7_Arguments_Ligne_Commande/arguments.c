/**********************************************************************
*	Programme demo pour lire et convertir les arguments en ligne
*       de commande.
*
*       Compilation: gcc -Wall arguments.c -o arguments
**********************************************************************/
#include<stdio.h>
#include<stdlib.h>

int main(int argc, char *argv[]){

    int entier = 0;
    double virgule = 0.0;

    if (argc != 3)
	return 1;
    else{
        entier = atoi(argv[1]);
        virgule = atof(argv[2]);
        printf("%d %.2lf\n", entier, virgule);
    }
    return 0;
}
