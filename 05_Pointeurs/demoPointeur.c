/***********************************************************
*    programme démonstration sur les pointeurs
*
*    compilation : gcc -Wall demoPointeur.c -o demoPointeur
***********************************************************/

#include <stdio.h>
int main(){
    //! showMemory(start=65520)
    char caractere = 'z';
    int entier = 42;
    double nbVirgule = 58.394;
    char * adresseDeCaractere = &caractere;
    printf("adresse de caractere: %p\n", adresseDeCaractere);
    adresseDeCaractere++;
    printf("adresse de caractere + 1: %p\n", adresseDeCaractere);
    int * adresseDeEntier = &entier;
    printf("adresse de entier: %p\n", adresseDeEntier);
    adresseDeEntier++;
    printf("adresse de entier + 1: %p\n", adresseDeEntier);
    double * adresseDeNbVirgule = &nbVirgule;
    printf("A l'adresse de nbVirgule: %p il y a %.3f\n", adresseDeNbVirgule, *adresseDeNbVirgule);
    adresseDeNbVirgule++;

    printf("adresse de nbVirgule + 1: %p\n", adresseDeNbVirgule);
    printf("A l'adresse de nbVirgule: %p il y a %.3f\n", adresseDeNbVirgule, *adresseDeNbVirgule);
    return 0;
}
