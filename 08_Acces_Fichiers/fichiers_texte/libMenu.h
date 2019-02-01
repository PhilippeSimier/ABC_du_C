
/*
 * File:   libMenu.h
 * Author: psimier
 *
 * Created on 11 décembre 2018, 10:36
 */

#ifndef NEWFILE_H
#define NEWFILE_H

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

#define NB_CAR 50

/**

@brief : Lecture d'un fichier texte dans un tableau de chaîne de caractères

*/
int  lireFichier (char *nomFichier, char *options[]);

/**

@brief : Ecriture d'un tableau de chaine de caratères dans un fichier
*/

void ecrireFichier (char *nomFichier, char *config[], int nbItem);


#endif /* NEWFILE_H */

