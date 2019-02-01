
/*
 * File:   main.c
 * Author: psimier
 *
 * Created on 11 décembre 2018, 10:34
 */

#include "libMenu.h"

int main(int argc, char** argv) {

    char *optionsMenu[10];
    int nbOptions;

    nbOptions = lireFichier( "menu.txt" , optionsMenu);

    // Affichage de tableau optionsMenu
    for(int i=0; i < nbOptions; i++){
        printf("%d - %s", i+1 , optionsMenu[i]);
    }
    printf("\nVotre choix: \n");
    ecrireFichier( "config.txt", optionsMenu, nbOptions);
    return (EXIT_SUCCESS);
}

