/****************************************************************************
    Correction question 9 TP pointeur
    résolution de l'équation du second degré
    Attention à ne pas oublier de linker avec la librairie  math -lm
    compilation : gcc exo9.c biblio_pointeur.c -lm -o exo9 -Wall

    test   0.3 x2 + 2.1 x + 3.675 = 0
    Donne une racine double racine = -3.5
    Le discriminant calculé est très proche de zéro dans les réels négatifs
    Celà est du au mode d'arrondi sur le résultat du calcul du discriminant
    cependant il y a bien une racine double !!!!
*****************************************************************************/

#include <stdio.h>
#include "biblio_pointeur.h"


int  main(){

    float a,b,c;
    float r1,r2;
    int nb;

printf("Résolution de l'équation du second degré.\n");
    printf("a: ");
    scanf("%f", &a);
    printf("b: ");
    scanf("%f", &b);
    printf("c: ");
    scanf("%f", &c);

    nb = resoSecondDegre(a, b, c, &r1,  &r2);

    if(nb == 2){
        printf("r1 : %f\t r2 : %f\n", r1, r2);
    }else{
	if (nb == 1)
	    printf("une racine double : %f\n", r1);
	else
            printf("Pas de  racine dans l'ensemble des réels.\n");
    }
    return 0;
}

