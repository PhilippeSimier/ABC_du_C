/***************************************************************
*  Compter le nombre de lettres minuscules dans le fichier
*  fichierTexte.txt
*
***************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <ctype.h>

void testErreur(){
    if(errno != 0){
        printf("Erreur fichier : erreur n'%d\n", errno);
        exit(0);
    }
}

int main()
{
    FILE * fp;
    char retour;
    int cptlower = 0;
    int cptupper = 0;

    fp = fopen("fichierTexte.txt","r");
    testErreur();
    while (!feof(fp)){   // tant que pas la fin de fichier
        retour = fgetc(fp);   // lecture d'un caractère
        if (islower(retour)) cptlower++;   // si minuscule
        if (isupper(retour)) cptupper++;   // si majuscule
    }
    printf("Minuscules = %d\nMajuscules = %d \n", cptlower, cptupper);
    fclose(fp);
    return 0;
}
