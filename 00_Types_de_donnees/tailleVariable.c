/**********************************************************************
*   l'opérateur sizeof renvoie la taille d'un type ou d'une variable
*   en octets
*   %zu permet d'afficher la valeur renvoyée par sizeof
*
*   Compilation : gcc -Wall tailleVariable.c -o tailleVariable
**********************************************************************/
#include <stdio.h>
#include <limits.h>

int main(){
    char c;
    short s;
    int  i;
    long l;
    long long ll;

    float f;
    double d;

    printf("Taille d'un char      : %zu octet(s)\n", sizeof(c));
    printf("Taille d'un short     : %zu octet(s)\n", sizeof(s));
    printf("Taille d'un int       : %zu octet(s)\n", sizeof(i));
    printf("Taille d'un long      : %zu octet(s)\n", sizeof(l));
    printf("Taille d'un long long : %zu octet(s)\n", sizeof(ll));
    printf("Taille d'un float     : %zu octet(s)\n", sizeof(f));
    printf("Taille d'un double    : %zu octet(s)\n", sizeof(d));

    return 0;
}
