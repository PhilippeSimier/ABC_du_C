/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: psimier
 *
 * Created on 19 novembre 2018, 09:52
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define LONG 255



typedef enum  { FAUX, VRAI }logique;

/* 
 * Teste si le caractère est une lettre
 */
logique isLettre(char lettre){
  return (lettre >= 'a' && lettre <= 'z' || lettre >='A' && lettre <= 'Z');
    
}

void MettreEnMajuscule(char s[]){
    int i;
    for (i=0; s[i]!='\0'; i++){
        if(s[i] >= 'a' && s[i] <= 'z'){
            s[i] -=32;
        }
   } 
}

/*
 * Ne retient que les lettres
 */
void ObtenirLettres(char s[]){
    int i,j;
    j=0;
    for (i=0; s[i]!='\0'; i++){
        if (isLettre(s[i])){
            s[j] = s[i];
            j++;
        }
    }
    s[j]='\0';   
}

void Inverser(char phrase[],char phraseInverse[]){
    int longueur;
    int i;
    longueur = strlen(phrase);
    for(i=0; i<longueur; i++){
        phraseInverse[i] = phrase[longueur - i -1];
    }
    phraseInverse[i] = '\0';
}
 
logique isPalindrome(char s[]){
    
    // Ne garder que les lettres de s et
    // les mettre en majuscule
    ObtenirLettres(s);
    MettreEnMajuscule(s);
    // Mettre s à l'envers dans sInverse
    char sInverse[LONG];
    Inverser(s,sInverse);
    
    // Comparer s avec sInverse
    return !strcmp(s,sInverse);
}        
    
    


int main(int argc, char** argv) {

    char phrase[LONG];
    printf("Saisir une phrase \n");
    fgets(phrase, LONG, stdin );
    ObtenirLettres(phrase);

    if (isPalindrome(phrase)){
        printf("%s : est un palimdrome\n", phrase);
    }
    return (EXIT_SUCCESS);
}

