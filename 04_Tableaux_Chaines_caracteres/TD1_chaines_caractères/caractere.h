/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   caractere.h
 * Author: psimier
 *
 * Created on 12 novembre 2018, 09:25
 */

#ifndef CARACTERE_H
#define CARACTERE_H



int comptage(char phrase[], char lettre);
int isVoyelle(char lettre);
int isLettre(char lettre);
int comptageVoyelle(char phrase[]);
int isEspaceBlanc(char lettre);
int comptageConsonne(char phrase[]);
int comptageMots(char phrase[]);
void Inverser(char phrase[],char phraseInverse[]);

#endif /* CARACTERE_H */

