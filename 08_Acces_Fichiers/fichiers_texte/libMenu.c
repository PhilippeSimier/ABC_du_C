/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include "libMenu.h"

int lireFichierMenu (char *nomFichier, char *options[]){ // *options[] = **options
    FILE *ficMenu;
    int i=0;
    char ligne[NB_CAR];
    int nbCar = 0;
    
    ficMenu = fopen(nomFichier, "r");
    if(ficMenu == NULL){
        perror("Erreur Ouverture du fichier");
        exit(errno);
    }
    
    while(fgets(ligne,NB_CAR,ficMenu) != NULL){
        
        nbCar = strlen(ligne);
        if(nbCar > 1){
        options[i]=(char *)malloc(sizeof(char)*nbCar+1);
            if(options[i] != NULL){
                strcpy(options[i],ligne);
                i++;
            }else{
                perror("Erreur Ouverture du fichier");
            exit(errno);
            }
        }
    }
    fclose(ficMenu);
    return (i);
}

void ecrireFichierConfig (char *nomFichier, char *config[], int nbItem){
    
    FILE *ficMenu;
    int i=0;
    char ligne[NB_CAR];
    int nbCar = 0;
    
    ficMenu = fopen(nomFichier, "w");
    if(ficMenu == NULL){
        perror("Erreur Ouverture du fichier");
        exit(errno);
    }
    
    while(fputs(ligne, ficMenu) == 0){
        nbCar = strlen(ligne);
        if(nbCar > 1){
        config[i]=(char *)malloc(sizeof(char)*nbCar+1);
        strcpy(config[i],ligne);
        i++;
        }
    }
    fclose(ficMenu);
}