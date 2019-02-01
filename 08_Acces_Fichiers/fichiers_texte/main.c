/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: nderouelle
 *
 * Created on 11 décembre 2018, 10:34
 */

#include "libMenu.h"
/*
 * 
 */
int main(int argc, char** argv) {
    char *optionsMenu[10];
    //char *configMenu[10];
    int nbOptions;
    //int nbItem;
    
    nbOptions = lireFichierMenu("menu.txt",optionsMenu);
    for(int i=0; i < nbOptions; i++){
        printf("%d - %s", i+1 , optionsMenu[i]);
    }
    printf("\nVotre choix: \n");
    
    
    return (EXIT_SUCCESS);
}

