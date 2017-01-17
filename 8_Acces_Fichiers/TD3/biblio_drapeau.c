#include "biblio_drapeau.h"

void testErreur(){
    if(errno != 0){
        printf("Erreur fichier : erreur n'%d\n", errno);
        exit(0);
    }
}

void creerImage(char *chemin, char *nomFichier, int largeur, int hauteur){

    FILE * ptFichier;
    BMP_FICHIER_HEAD entete;             // un entête de fichier
    COULEUR palette[NB_COULEURS];        // une palette de 3 couleurs
    char *image;
    int i, j;

    char nomComplet[1024]={0};

    // création de l'entête fichier
     entete.signature[0]='B';
     entete.signature[1]='M';
     entete.taille = sizeof(BMP_FICHIER_HEAD)+sizeof(palette)+(largeur*hauteur)+2;
     entete.offsetImage = sizeof(BMP_FICHIER_HEAD)+sizeof(palette);
     entete.reserve = 0;

     // création de l'entête BMP
     entete.imageHead.bitParPixel = 8;
     entete.imageHead.compression = 0;
     entete.imageHead.hauteur = hauteur;
     entete.imageHead.hResolution = 2835;
     entete.imageHead.largeur = largeur;
     entete.imageHead.nbCouleur= NB_COULEURS;
     entete.imageHead.nbCouleurImportantes= NB_COULEURS;
     entete.imageHead.nbplans = 1;
     entete.imageHead.tailleImage = largeur*hauteur;
     entete.imageHead.taille_entete = sizeof(BMP_IMAGE_HEAD);

     // création de la palette
     for (i = 0; i < NB_COULEURS; i++){
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
    ptFichier = fopen(nomComplet, "wb");
    testErreur();
    if (ptFichier != NULL){
        if (fwrite(&entete, sizeof(BMP_FICHIER_HEAD), 1, ptFichier) != 1){
            printf("Erreur d'écriture fichier destination\n");
            return;
        }

    	if (fwrite(palette, sizeof(COULEUR), NB_COULEURS, ptFichier) != NB_COULEURS){
            printf("Erreur d'écriture de la palette\n");
            return;
    	}
    	if (fwrite(image, sizeof(char), largeur*hauteur, ptFichier) != largeur*hauteur){
	    printf("Erreur d'écriture de l'image\n");
	    return;
        }
        if (fwrite("\0\0", sizeof(char), 2, ptFichier) != 2){
            printf("Erreur d'écriture fin de fichier\n");
            return;
        }
    fclose (ptFichier);
    }
    return;
}
