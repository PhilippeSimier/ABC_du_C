/***************************************************************************************
     Programmez une fonction qui prend une chaîne de caractères en argument
     et renvoie true si c’est un palindrome (phrase symétrique, qui s’écrit de la même
     manière de gauche à droite et de droite à gauche).

     Compilation : gcc palindrome.c -o palindrome -Wall

     Exécution   : ./palindrome
		   Saisir une phrase : kayak
		   La phrase kayak est un palindrome
     exemple	 : Engage le jeu que je le gagne !
		 : Un roc si biscornu.
***************************************************************************************/

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
#define LONG 1001

/* renvoie true si s est un palindrome, false sinon */
bool palindrome(const char* s)  // const car la chaîne s n'est pas modifiée
{

    int j = strlen(s);
    int i = 0;
    while ( i < j ) {
        while (!isalpha(s[i]))
	    { i++; }
        while (!isalpha(s[j]))
	    { j--; }
        if ( toupper(s[i]) != toupper(s[j]) ) return false; // echec!
    	i++;
    	j--;
    }
    return true; // OK
}

int main()
{
    char buffer[LONG];
    printf("Saisir une phrase (sans lettres accentuées) : ");
    scanf("%[^\n]",buffer);

    if(palindrome(buffer))
 	printf("La phrase \033[92m%s\033[0m est un palindrome\n", buffer);
    else
	printf("La phrase \033[92m%s\033[0m n'est pas un palindrome\n", buffer);

    return 0;
}

