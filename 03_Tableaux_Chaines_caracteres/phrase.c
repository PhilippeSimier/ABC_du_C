/*******************************************************
*  Écrivez un programme demandant		       *
*  une phrase à l'utilisateur                          *
*  puis affiche le nombre de fois où apparaît 'a'      *
*  le nombre de voyelles			       *
*  le nombre de consommes			       *
*  le nombre de mots présents			       *
*                                                      *
*  gcc phrase.c -o phrase -std=c99 -Wall 	       *
********************************************************/

#include <stdio.h>
#include <stdbool.h>  // pour avoir le type bool
#define LONG 255

bool isVoyelle(char car)
{
   char voyelles[7] = "aeiouy";

   if (car < 'a')
        car += 32;

   for (int i = 0; i < 7; i++){
      if (car == voyelles[i])
         return true;
   }
   return false;
}

bool isConsonne(char lettre){
    if (lettre < 'a')
	lettre += 32;
    return  (lettre >= 'a' && lettre <= 'z' && !isVoyelle(lettre));
}

// fonction pour compter le nombre de caractères  dans une chaîne s
int occ(char s[], char caractere)
{
    int occurence = 0;
    for (; *s; s++)
    {
    	if (*s == caractere)
	    occurence++;
    }
    return occurence;
}

// fonction pour compter le nombre de voyelles
int voyelle(char s[])
{
    int occurence = 0;
    for (; *s; s++)
    {
        if (isVoyelle(*s))
            occurence++;
    }
    return occurence;
}

// fonction qui compte le nombre de consonnes

int consonne(char s[])
{
    int occurence = 0;
    for (; *s; s++)
    {
        if (isConsonne(*s))
            occurence++;
    }
    return occurence;
}
// fonction pour obtenir la longueur de la phrase
int len(char s[])
{
    int longueur = -1;
    for (; *s; s++)
	longueur++;
    return longueur;
}

// fonction pour inverser l'ordre des lettres
void inverse(char s[])
{
    int longueur = len(s);
    int i;
    char temp;

    for (i=0 ; i<(longueur/2); i++){
    	temp  = s[i];
    	s[i] =  s[longueur -i -1];
        s[longueur -i -1] = temp;
    }
}
// fonction pour transformer les majuscules en miniscules et vice versa
void inverse_majuscule(char s[])
{
    for(; *s; s++){
    	if ( *s >= 'a' && *s <= 'z'){
             *s = *s - 32;
	     continue;
	}
    	if ( *s >= 'A' && *s <= 'Z') *s = *s + 32;
    }
}

int main()
{

    char buffer[LONG];
    printf("Saisir une phrase \n");
    scanf("%[^\n]", buffer);
    printf("La phrase est : \"%s\"\n", buffer);
    printf("Le nombre de caractères 'a' est : %d\n", occ(buffer, 'a'));
    printf("Le nombre de voyelles est       : %d\n", voyelle(buffer));
    printf("Le nombre de consonnes est      : %d\n", consonne(buffer));
    printf("Le nombre de mots est           : %d\n", occ(buffer,' ') + occ(buffer,'\t') + occ(buffer,'\'') + occ(buffer,'-') + 1);
    inverse(buffer);
    printf("La phrase inversée est : %s\n", buffer);
    inverse(buffer);
    inverse_majuscule(buffer);
    printf("Minuscules et majuscules inversées : %s\n", buffer);
}
