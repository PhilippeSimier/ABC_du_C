#include "biblio_drapeau.h"

void testErreur(){
    if(errno != 0){
        printf("Erreur fichier : erreur n'%d\n", errno);
        exit(0);
    }
}

void creerImage(char *chemin, char *nomFichier, int largeur, int hauteur){

    FILE * ptFichier;
    BMPfichierHead entete;   // un entête de fichier
    couleur palette[256];    // une palette de couleurs
    char *image;
    int i, j;

    char nomComplet[1024]={0};

    // création de l'entête fichier
     entete.signature[0]='B';
     entete.signature[1]='M';
     entete.taille = 40+14+1024+(largeur*hauteur);
     entete.offsetImage = 1078;
     entete.reserve = 0;

     // création de l'entête BMP
     entete.imageHead.bitParPixel = 8;
     entete.imageHead.compression = 0;
     entete.imageHead.hauteur = hauteur;
     entete.imageHead.hResolution = 2835;
     entete.imageHead.largeur = largeur;
     entete.imageHead.nbCouleur= 256;
     entete.imageHead.nbCouleurImportantes= 256;
     entete.imageHead.nbplans = 1;
     entete.imageHead.tailleImage = largeur*hauteur;
     entete.imageHead.taille_entete = 40;

     // création de la palette
     for (i = 0; i < 256; i++){
          palette[i].bleu = 255;
          palette[i].rouge = 255;  // blanc pour toute la palette
          palette[i].vert = 255;
          palette[i].alpha = 0;
     }
     palette[0].rouge = 0;
     palette[0].vert = 0;  // bleu pour couleur 0
     palette[2].bleu = 0;
     palette[2].vert = 0;  // rouge pour couleur 2

     // création de l'image
     image = (char *) malloc(sizeof(char) * largeur * hauteur);
     for (i = 0; i< (hauteur); i++){  // pour chacune des lignes
         for (j = 0; j< largeur/3; j++){  // 1/3 en bleu
            image[i*largeur + j]= 0;
         }
         for (j = largeur/3; j< 2*largeur/3; j++){  // deuxième 1/3 en blanc
            image[i*largeur + j]= 1;
         }
         for (j = 2*largeur/3; j< largeur; j++){  // troisième 1/3 en rouge
            image[i*largeur + j]= 2;
         }


     }


    strcpy(nomComplet, chemin);
    strcat(nomComplet, nomFichier);
    printf("Ouverture fichier en écriture: %s\n", nomComplet);
    ptFichier = fopen(nomComplet, "w");
    testErreur();
    if (ptFichier != NULL){
        if (fwrite(&entete, sizeof(BMPfichierHead), 1, ptFichier) != 1){
            printf("Erreur d'écriture fichier destination\n");
            return;
        }
    }
    if (fwrite(palette, sizeof(couleur), 256, ptFichier) != 256){
                printf("Erreur de Ecriture de la palette\n");
                return;
    }
    fwrite(image, sizeof(char), largeur*hauteur, ptFichier);
    fclose (ptFichier);
    return;
}
