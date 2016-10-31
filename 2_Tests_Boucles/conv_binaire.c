/************************************************************
*    Correction Exercice n°1 Question 1
*    Sujet : Conversion binaire
*    Compilation : gcc conv_binaire.c -o conv_binaire -Wall
*************************************************************/
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int nombre;
    unsigned char poids,n;
    do{
    	printf("Saisir le nombre compris entre 0 et 255 : ");
        scanf("%d", &nombre);
    }
    while(nombre > 255);

    poids = 0x80;
    for ( n=0 ; n<8 ; n++){
	if (nombre >= poids) {
	    printf("1");
	    nombre = nombre - poids;
	}
	else{
	    printf("0");
        }
	poids = poids/2;
    }
    printf("\n");
    return 0;
}
