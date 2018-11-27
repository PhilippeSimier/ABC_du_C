#ifndef CRYPTEUR_H
#define CRYPTEUR_H

#include <stdio.h>
#include <stdlib.h>
#define LONG 255

typedef enum {NON, OUI}logique;

void mettreMajuscule(char s[]);
void saisirPhrase(char phrase[]);
logique isLettre(char caractere);
void crypter(char phrase[], char cle[]);
void decrypter(char phrase[], char cle[]);


#endif /* CRYPTEUR_H */

