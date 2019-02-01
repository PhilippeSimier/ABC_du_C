/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   newfile.h
 * Author: nderouelle
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

int lireFichierMenu (char *nomFichier, char *options[]);
void ecrireFichierConfig (char *nomFichier, char *config[], int nbItem);


#endif /* NEWFILE_H */

