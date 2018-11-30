/* 
 * File:   accordeur.h
 * Author: psimier
 *
 * Created on 30 novembre 2018, 11:09
 */

#ifndef ACCORDEUR_H
#define ACCORDEUR_H

#include <ctype.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#define LONG 255
#define MAXMOTS 100

// Les couleurs
#define RESET "\033[1;0m"
#define ROUGE "\033[1;31m"
#define VERT "\033[1;32m"

typedef enum { NON, OUI}logique;

void    viderBuffer();
void    saisirPhrase(char phrase[]);
int     decouperPhrase(char phrase[], char *tableau[]);
logique estPluriel(char *mot);


#endif /* ACCORDEUR_H */

