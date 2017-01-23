#include "biblio_drapeau.h"

void testErreur(){
    if(errno != 0){
        printf("Erreur fichier : erreur n'%d\n", errno);
        exit(0);
    }
}

void creerImage(char *chemin, char *nomFichier, int largeur, int hauteur){

    FILE * ptFichier;
    BMP_FICHIER_HEAD entete;                   // un entête de fichier
    COULEUR palette[NB_COULEURS]={{0}};        // une palette de NB couleurs
    char *bipMapData;                          // Un tableau de données
    INDICE i;
    int j;
    int largeur4;                               // nb d'octet d'une ligne

    char nomComplet[1024]={0};

    /** Chaque ligne de l'image doit comporter un nombre total d'octets
        qui soit un multiple de 4; si ce n'est pas le cas, la ligne doit
        être complétée par des 0 de telle manière à respecter ce critère.
    **/

     if ((largeur%4) != 0){
        largeur4 = (largeur/4)*4 + 4;
     }
     else
        largeur4 = largeur;

    // création de l'entête fichier
     entete.signature[0]='B';
     entete.signature[1]='M';
     entete.taille = sizeof(BMP_FICHIER_HEAD) + sizeof(palette) + (largeur4 *hauteur)+2 ;
     entete.offsetImage = sizeof(BMP_FICHIER_HEAD) + sizeof(palette);
     entete.reserve = 0;

     // création de l'entête BMP
     entete.imageHead.bitParPixel = 8;  //Cette valeur peut-être égale à 1, 4, 8, 16, 24 ou 32
     entete.imageHead.compression = 0;  // 0 lorsque l'image n'est pas compressée
     entete.imageHead.hauteur = hauteur;
     entete.imageHead.largeur = largeur;
     entete.imageHead.hResolution = 100 * RESOLUTION /2.54;   // c'est  le nombre de pixels par mètre
     entete.imageHead.vResolution = 100 * RESOLUTION /2.54;
     entete.imageHead.nbCouleur= NB_COULEURS;  // Le nombre de couleurs de la palette
     entete.imageHead.nbCouleurImportantes= NB_COULEURS;
     entete.imageHead.nbplans = 1;   // Cette valeur vaut toujours 1
     entete.imageHead.tailleImage = largeur*hauteur;
     entete.imageHead.taille_entete = sizeof(BMP_IMAGE_HEAD);

     // création de la palette
     for (i = BLANC; i < NB_COULEURS; i++){
          palette[i].bleu = 255;
          palette[i].rouge = 255;  // blanc pour toutes les couleurs de la palette
          palette[i].vert = 255;
          palette[i].alpha = 0;
     }
     palette[BLEU].rouge = 0;
     palette[BLEU].vert = 0;  // RVB pour le bleu
     palette[ROUGE].bleu = 0;
     palette[ROUGE].vert = 0;  // RVB pour le rouge


     /** création du bipMapData
        Le codage de l'image se fait en écrivant successivement les octets
        correspondant à chaque pixel, ligne par ligne en commençant
        par le pixel en bas à gauche. **/


     bipMapData = (char *) malloc(sizeof(char) * largeur4 * hauteur + 2);
     memset(bipMapData, 0, largeur4 * hauteur + 2);

     for (i = 0; i< (hauteur); i++){  // pour chacune des lignes
         for (j = 0; j< largeur/3; j++){  // premier tiers en bleu
            bipMapData[i*largeur4 + j]= BLEU;
         }
         for (j = largeur/3; j< 2*largeur/3; j++){  // deuxième tiers en blanc
            bipMapData[i*largeur4 + j]= BLANC;
         }
         for (j = 2*largeur/3; j< largeur; j++){  // troisième tiers en rouge
            bipMapData[i*largeur4 + j]= ROUGE;
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
    	if (fwrite(bipMapData, sizeof(char), largeur4*hauteur+2, ptFichier) != largeur4*hauteur+2){
	    printf("Erreur d'écriture de l'image\n");
	    return;
        }

    fclose (ptFichier);
    }
    return;
}
