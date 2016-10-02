/************************************************************************
*   Il est possible d'initialiser plusieurs variables.
*   pour séparer nos variables, nous utilisons des VIRGULES.
*   Donc utilisez cette notation avec parcimonie
*   car elle est source de bugs !!!
*
*   Compilation :   gcc boucle_for.c -o boucle_for -std=c99
*
************************************************************************/

#include <stdio.h>
#include <stdlib.h>

int main(){
    // boucle avec plusieurs variables initialisées et plusieurs variables incrémentées
    for (int i=0, j=100, k=10; i<10; i++, k++) {
    	j += k;
    	printf("i vaut %i, j vaut %i et k vaut %i\n", i, j, k);
    }

    // boucle avec incrémentation de 5
    for (int i =0; i< 100; i+=5)
        printf("%d\n", i);

    return 0;
}
