
#include "libMenu.h"

int lireFichier(char *nomFichier, char *options[]){    // *options[] = **options

    FILE *ficMenu;
    int i=0;
    char ligne[NB_CAR];
    int nbCar = 0;

    if((ficMenu = fopen(nomFichier, "r")) == NULL){
        perror("Erreur Ouverture du fichier");
        exit(errno);
    }

    while(fgets(ligne,NB_CAR,ficMenu) != NULL){

        nbCar = strlen(ligne);
        if(nbCar > 1){
            if(( options[i] = (char *)malloc(sizeof(char)*nbCar+1)) != NULL){
                strcpy(options[i],ligne);
                i++;
            }else{
                perror("Erreur Lecture du fichier");
            exit(errno);
            }
        }
    }
    fclose(ficMenu);
    return (i);
}

void ecrireFichier(char *nomFichier, char *config[], int nbItem){

    FILE *ficMenu;

    if((ficMenu = fopen(nomFichier, "w")) == NULL){
        perror("Erreur Ouverture du fichier");
        exit(errno);
    }

    for (int i=0; i< nbItem; i++){
        fputs(config[i], ficMenu);
    }
    fclose(ficMenu);
}
