/**********************************************************************
*   l'opérateur sizeof renvoie la taille d'un type ou d'une variable
*   en octets
*   %zu permet d'afficher la valeur renvoyée par sizeof
*
*   Compilation : gcc -Wall tailleVariable.c -o tailleVariable
**********************************************************************/
#include <stdio.h>

int main(){
    char c;
    int  i;
    double d;
    char tabchar[3];
    int tabint[3];
    double tabdouble[3];

    printf("Taille d'un char   :%zu\n", sizeof(c));
    printf("Taille d'un int    :%zu\n", sizeof(int));
    printf("Taille d'un double :%zu\n\n", sizeof(double));

    printf("Taille d'un tableau de 3 char   :%zu\n", sizeof(tabchar));
    printf("Taille d'un tableau de 3 int    :%zu\n", sizeof(tabint));
    printf("Taille d'un tableau de 3 double :%zu\n", sizeof(tabdouble));
    return 0;
}
