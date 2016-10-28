/***************************************************************************************
     Programmez une fonction qui prend une chaîne de caractères en argument
     et renvoie 1 si c’est un palindrome (mot symétrique, qui s’écrit de la même
     manière de gauche à droite et de droite à gauche).

     Compilation : gcc palindrome.c -o palindrome -Wall

     Exécution   : ./palindrome
		   Saisir un mot : kayak
		   Le mot kayak est un palindrome

***************************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define LONG 26

/* renvoie 1 si s est un palindrome, 0 sinon */
int palindrome(const char* s)  // const car la chaîne s n'est pas modifiée
{

    int n = strlen(s);
    int i = 0;
    printf(" n = %d\n", n);
    while ( i < n/2 ) {
    	//ATTENTION: l’indice symétrique de i est n-1-i, pas n-i!
	// car les indices vont de 0 à n-1 dans le tableau de caratères s
    	if ( s[i] != s[n-1-i] ) return 0; // echec!
    i++;
    }
    return 1; // OK
}

int main()
{

    char buffer[LONG];
    printf("Saisir un mot (sans lettres accentuées) : ");
    scanf("%s",buffer);

    if(palindrome(buffer))
 	printf("Le mot \033[92m%s\033[0m est un palindrome\n", buffer);
    else
	printf("Le mot \033[92m%s\033[0m n'est pas un palindrome\n", buffer);

    return 0;
}

