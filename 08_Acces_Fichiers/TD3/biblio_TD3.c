#include "biblio_TD3.h"

void testErreur(){
    if(errno != 0){
        printf("Erreur fichier : erreur n'%d\n", errno);
        exit(0);
    }
}

void afficheEnTeteFichierBmp(char *chemin, char *nomFichier){

    FILE * ptFichier;
    BMPfichierHead *entete;
    int resultat;

    char nomComplet[1024]="";

    strcat(nomComplet, chemin);
    strcat(nomComplet, nomFichier);
    printf("Propriété de l'image    : %s\n", nomFichier);
    printf(" Emplacement            : %s\n", chemin);
    printf("\nEntête du fichier\n");
    ptFichier = fopen(nomComplet, "r"); /** ouverture en mode read **/
    testErreur();

    if( ptFichier != NULL){
        entete = (BMPfichierHead *) malloc(sizeof(BMPfichierHead));
        resultat = fread(entete, sizeof(BMPfichierHead), 1, ptFichier);

        if(resultat > 0){
            printf(" Signature              : %c%c\n",entete->signature[0], entete->signature[1]);
            printf(" Taille du fichier      : %d Ko (%d Octets)\n", entete->taille/1000, entete->taille);
            printf(" Reserve                : %d \n", entete->reserve);
            printf(" Offset image           : %d\n", entete->offsetImage);

        }
    fclose(ptFichier);
    }
}

void afficheEnTeteImageBMP(char *chemin, char *nomFichier){

    FILE * ptFichier;
    BMPImageEnTete *entete;
    int resultat;

    char nomComplet[1024]="";

    strcat(nomComplet, chemin);
    strcat(nomComplet, nomFichier);
    printf("\nEntête de l'image\n");
    ptFichier = fopen(nomComplet, "r"); /** ouverture en mode read **/
    testErreur();

    if( ptFichier != NULL){
        fseek(ptFichier, 14, SEEK_SET);
        entete = (BMPImageEnTete *) malloc(sizeof(BMPImageEnTete));
        resultat = fread(entete, sizeof(BMPImageEnTete), 1, ptFichier);
        if(resultat > 0){

            printf(" - Taille de l'entête   : %d octets\n", entete->taille_entete);
            printf(" - Dimensions           : %d px x %d px\n", entete->largeur, entete->hauteur);
            printf(" - Bits par pixel       : %d\n", entete->bitParPixel);
            switch(entete->compression){

                case 0: printf(" - Pas de Compression \n"); break;
                case 1: printf(" - Compression RLE 8 bits \n"); break;
                case 2: printf(" - Compression RLE 4 bits \n"); break;
                case 3: printf(" - bitfiel"); break;
                default: printf(" - Code Compression inconnu\n");
            }
            printf(" - Taille de l'image    : %u Ko (%d octets)\n", entete->tailleImage/1000, entete->tailleImage);
            printf(" - Resolution H         : %d\n", entete->hResolution);
            printf(" - Resolution V         : %d\n", entete->hResolution);
            printf(" - Nb couleurs          : %d\n", entete->nbCouleur);

        }
        fclose(ptFichier);
    }

}

void desaturation(couleur *c){
    int val;
    val = (c->rouge + c->bleu + c->vert)/3;
    c->rouge = (char)val;
    c->bleu = 0;
    c->vert = 0;
    c->alpha = 0;
}


void changePaletteBMP(char *chemin, char *FichierSource, char * FichierDest){
    FILE * ptFSource;
    FILE * ptFDest;
    BMPfichierHead *entete;
    couleur palette[256];
    char nomCompletSource[1024]={0};
    char nomCompletDest[1024]={0} ;
    char buffer[1024];
    int i;

    printf("\nApplication du filtre Rouge\n");
    strcpy(nomCompletSource, chemin);
    strcat(nomCompletSource, FichierSource);
    printf("Ouverture fichier en lecture: %s\n", nomCompletSource);
    ptFSource = fopen(nomCompletSource, "r");
    testErreur();

    strcpy(nomCompletDest, chemin);
    strcat(nomCompletDest, FichierDest);
    printf("Ouverture fichier en écriture: %s\n", nomCompletDest);
    ptFDest = fopen(nomCompletDest, "w");
    testErreur();

    if (ptFDest != NULL && ptFSource != NULL){
        entete = (BMPfichierHead *) malloc(sizeof(BMPfichierHead ));
        if (fread(entete, sizeof(BMPfichierHead), 1, ptFSource) != 1){
	    printf("Erreur de lecture fichier source\n");
            return;
        }
        if (fwrite(entete, sizeof(BMPfichierHead), 1, ptFDest) != 1){
	    printf("Erreur d'écriture fichier destination\n");
            return;
	}
        if (fread(palette, sizeof(couleur), 256, ptFSource) != 256){
            printf("Erreur de lecture de la palette\n");
            return;
        }
        /** modification de la palette **/
        for( i = 1; i < 256; i++){
            desaturation(&palette[i]); // appelle de la  fonction désaturation
        }
        if (fwrite(palette, sizeof(couleur), 256, ptFDest) != 256){
            printf("Erreur de Ecriture de la palette\n");
            return;
        }
        /** recopie de l'image **/
        int nb;
        while( (nb = fread(buffer, sizeof(char), 1024, ptFSource)) > 0){
            fwrite(buffer, sizeof(char), nb, ptFDest);
        }
        fclose (ptFDest);
        fclose (ptFSource);
    }






}
