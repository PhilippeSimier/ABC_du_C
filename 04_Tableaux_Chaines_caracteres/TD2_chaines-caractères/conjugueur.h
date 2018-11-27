/* 
 * File:   conjugueur.h
 * Author: psimier
 *
 * Created on 27 novembre 2018, 09:23
 */

#ifndef CONJUGUEUR_H
#define CONJUGUEUR_H

#include <string.h>
#include <stdio.h>
#include <stdlib.h>

typedef enum  { NON, OUI}logique;

void MettreEnMinuscule(char s[]);
logique deroger(char initial);
void conjuguerAuPresent(char verbe[]);
logique isPremierGroupe(char verbe[]);
int obtenirRadical(char radical[], char verbe[]);


#endif /* CONJUGUEUR_H */

