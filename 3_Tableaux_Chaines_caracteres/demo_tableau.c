/***********************************************************
*  Programme pour demonstration de tableau de tableaux
*  ou tableau de pointeurs car un tableau est une pointeur
*  Compilation : gcc -Wall demo_tableau.c -o demo_tableau
***********************************************************/

#include <stdio.h>
int main(){

     short a[3] = {1245, 2312, 234};   // premier tableau
     short b[2] = {24, 2451};          // deuxième tableau
     short c[4] = {23345, 2343, 8763, 3456};   // troisieme tableau
     short * tabs[3] = {a,b,c};    // tableau de tableaux
     * tabs[0] = 5;    // correspond à l'emplacement a[0]
     tabs[0][0] = 0;   // même chose avec une autre écriture
     * (tabs[0] + 1) = 6;
     tabs[0][1] = 0;
     * (tabs[0] + 2) = 7;
     tabs[0][2] = 0;
     * tabs[1] = 3;
     tabs[1][0] = 0;
     * (tabs[1] + 1) = 4;
     tabs[1][1] = 0;

     return 0;
}
