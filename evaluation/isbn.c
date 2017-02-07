/*****************************************************************
*	corrigé :
*       compilation : gcc -std=c11 -Wall isbn.c -o isbn
*****************************************************************/
#include <stdio.h>
#include <string.h>

char cleISBN(char *codeISBN){
    int somme = 0;
    int cle;
    int rang = 1;

    for (; *codeISBN; codeISBN++){
        if(*codeISBN >= '0' && *codeISBN <= '9' && rang <= 9){
            somme += rang * (*codeISBN - '0');
	    rang++;
        }
    }
    cle = somme % 11;
    if (cle == 10)
	return 'X';
    else
       	return cle + '0';
}

int verificationISBN(char *codeISBN){

    int longueur = strlen(codeISBN);
    if ((longueur == 13) && (cleISBN(codeISBN) == codeISBN[12]))
	return 1;
    else
    	return 0;
}

int main(){

    printf("%c\n",cleISBN("2-225-80068"));
    printf("%d\n",verificationISBN("2-101-48491-5"));
    printf("%d\n",verificationISBN("2-266-11156-6"));
    return 0;
}
