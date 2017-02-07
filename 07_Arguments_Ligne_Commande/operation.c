/**********************************************************************
*	2. Ecrivez un programme "operation" qui prendra en paramètre
*          de la ligne de commande une opération, deux valeurs réelles
*          et affichera le résultat.
*
*       Compilation: gcc -Wall operation.c -o operation
**********************************************************************/
#include<stdio.h>
#include<stdlib.h>

void usage(char *);

int main(int argc, char *argv[]){

    float valeur1 = 0.0;
    float valeur2 = 0.0;

    if (argc != 4)
	usage(argv[0]);
    else{
        valeur1 = atof(argv[2]);  // Conversion chaîne de caractères en float
        valeur2 = atof(argv[3]);  // pour argv[2] et argv[3]

	switch(argv[1][0]){
            case '+':
            	printf("%s %s %s = %.1f\n", argv[2], argv[1], argv[3], valeur1 + valeur2);
		break;
	    case '-':
                printf("%s %s %s = %.1f\n", argv[2], argv[1], argv[3], valeur1 - valeur2);
                break;
	    case 'x':
                printf("%s %s %s = %.1f\n", argv[2], argv[1], argv[3], valeur1 * valeur2);
                break;
	    case '/':
                printf("%s %s %s = %.1f\n", argv[2], argv[1], argv[3], valeur1 / valeur2);
                break;
	}
    }
    return 0;
}

void usage(char *nom){

    printf("Usage : %s [+ - x /] nb1 nb2\n", nom);
}
