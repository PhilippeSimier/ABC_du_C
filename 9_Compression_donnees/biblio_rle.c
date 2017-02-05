/*************************************************************
 *                                                           *
 * Auteur   :   Philippe SIMIER                              *
 * Date     :   27/01/2017                                   *
 * Version  :   2.0                                          *
 * SUJET    :   Correction du TD sur la compression RLE      *
 *              Bibliothèque de fonctions                    *
 *              pour compresser les fichiers au format BMP   *
 *                                                           *
 *************************************************************/

#include "biblio_rle.h"

/*-----------------------------------------------------------*/
/*     Fonction pour la compression RLE d'un fichier BMP     */
/*-----------------------------------------------------------*/

int RLEcompresse(const char *fichierSource,
                 const char *fichierDest)
{
    FILE* fichierS = NULL;
    FILE* fichierD = NULL;
    BMPfichierHead entete;
    couleur palette[256];
    rle couple;
    int i,j;
    int cpt = 0;
    unsigned char *ligne;
    int nbLigne;

    fichierS = fopen(fichierSource, "rb");
    if (fichierS == NULL)  return 1;

    fichierD = fopen(fichierDest, "wb");
    if (fichierD == NULL)  return 2;

    /* lecture de l'entête  */
    if (fread(&entete,sizeof(BMPfichierHead),1,fichierS) !=1)
        return 3;

    /* ecriture de l'entête */
    if (fwrite(&entete,sizeof(BMPfichierHead),1,fichierD) !=1)
        return 4;

    /* lecture de la palette des couleurs */
    if (fread(palette, sizeof(couleur), 256, fichierS) != 256)
        return 5;

    /* Ecriture de la palette des couleurs */
    if (fwrite(palette, sizeof(couleur), 256, fichierD) != 256)
        return 6;

    /* tableau de char pour une ligne */
    ligne = (unsigned char *)(malloc(entete.imhead.largeur * sizeof(char)));
    /* la hauteur d'une image peut être négative  avec Photoshop */
    if (entete.imhead.hauteur <0)
        nbLigne = entete.imhead.hauteur * -1;
    else
        nbLigne = entete.imhead.hauteur;

    for (j=0; j<nbLigne; j++){
        if (fread(ligne, sizeof(char), entete.imhead.largeur, fichierS )
            != entete.imhead.largeur)
            return 7;

        couple.valeur = ligne[0];
        couple.repetition = 1;
        for (i=1; i<entete.imhead.largeur; i++){
            if (ligne[i] == couple.valeur) {
                couple.repetition++;
                if (couple.repetition == 255) {
                    if (fwrite(&couple, sizeof(couple), 1, fichierD) != 1)
                        return 8;
                    cpt = cpt + 2;
                    couple.repetition = 0;
                }
            }
            else {
                if (fwrite (&couple, sizeof(couple), 1, fichierD) != 1)
                    return 9;
                cpt = cpt + 2;
                couple.valeur = ligne[i];
                couple.repetition = 1;

            }
        }
        if (couple.repetition >0) {
            if (fwrite (&couple, sizeof(couple), 1, fichierD) != 1)
                return 10;
            cpt = cpt + 2;
        }

        /*  Ecriture  Fin de ligne BMP     00 00   */
        couple.valeur = 0;
        couple.repetition = 0;
        if (fwrite (&couple, sizeof(couple), 1, fichierD) != 1)
            return 11;
        cpt = cpt + 2;
    }
    /*  Ecriture  Fin de fichier BMP       00 01   */
    couple.repetition = 0;
    couple.valeur = 1;
    if (fwrite (&couple, sizeof(couple), 1, fichierD) != 1)
        return 12;
    cpt = cpt + 2;

    /* Mise à jour de l'entête du fichier destination */
    entete.imhead.compression = 1;
    entete.imhead.tailleImage = cpt;
    entete.taille = cpt +1078;
    fseek(fichierD,0,SEEK_SET);
    if (fwrite(&entete, sizeof(BMPfichierHead),1, fichierD) != 1)
        return 13;

    fclose(fichierS);
    fclose(fichierD);
    return 0;
}


/*-----------------------------------------------------------*/
/*     Fonction pour la décompression RLE d'un fichier BMP   */
/*-----------------------------------------------------------*/
int  RLEdecompresse (const char *fichierSource, const char *fichierDest)
{
    FILE* fichierS = NULL;
    FILE* fichierD = NULL;
    BMPfichierHead entete;
    couleur palette[256];
    rle couple;
    int cpt,i;
    int val;



    fichierS = fopen(fichierSource, "rb");
    if (fichierS == NULL) return 1;
    fichierD = fopen(fichierDest, "wb");
    if (fichierD == NULL) return 2;

    /* lecture de l'entête  */
    if (fread(&entete,sizeof(BMPfichierHead),1,fichierS) !=1)
        return 3;

    /* ecriture de l'entête */
    if (fwrite(&entete,sizeof(BMPfichierHead),1,fichierD) !=1)
        return 4;

    /* lecture de la palette des couleurs */
    if (fread(palette, sizeof(couleur), 256, fichierS) != 256)
        return 5;

    /* Ecriture de la palette des couleurs */
    if (fwrite(palette, sizeof(couleur), 256, fichierD) != 256)
        return 6;

    cpt = 0;
    while(fread(&couple, sizeof(rle), 1, fichierS) == 1){

        for (i=0;i<couple.repetition;i++){
            if (fwrite(&couple.valeur, sizeof(char),1, fichierD) != 1){
                return 7;
                }
            cpt++;
            }
    }
    /* le compteur cpt doit correspondre au produit de la largeur par la hauteur */
    /* attention la hauteur peut être négative */

    if (entete.imhead.hauteur<0) {
            val = entete.imhead.hauteur * -1;
    }
    else{
            val = entete.imhead.hauteur;
    }
    if (cpt != (entete.imhead.largeur * val))
        return 8;
    /* Ecriture fin de fichier 00 00 */
    couple.repetition = 0;
    couple.valeur = 0;
    cpt +=2;
    if (fwrite (&couple, sizeof(couple), 1, fichierD) != 1)
        return 9;

    /* Mise à jour de l'entête du fichier destination */
    entete.imhead.compression = 0;
    entete.imhead.tailleImage = cpt;
    entete.taille = cpt +1078;
    fseek(fichierD,0,SEEK_SET);
    if (fwrite(&entete, sizeof(BMPfichierHead),1, fichierD) != 1)
        return 10;

    fclose(fichierS);
    fclose(fichierD);
    return 0;
}



/*-----------------------------------------------------------*/
/*   Fonction pour afficher l'entête complet du fichier BMP  */
/*-----------------------------------------------------------*/
void afficheEnTeteFichier(const char *nomFichier){

    FILE* fichierSource;
    BMPfichierHead entete;
    int result=0;

    fichierSource = fopen(nomFichier,"rb");  /*  ouverture en mode read binaire */
    if (fichierSource != NULL){

        /*lecture de l'entete fichier */
        result = fread(&entete,sizeof(BMPfichierHead),1,fichierSource);
        if(result>0){
            printf("Proprietes du fichier   : %s\n",nomFichier);

            printf("Signature               : %c%c\n",
                   entete.signature[0],
                   entete.signature[1]);
            printf("Taille du fichier       : %dKo (%d octets)\n",
                   entete.taille/1024,
                   entete.taille);
            printf("Offset image            : %d\n\n",entete.offsetimage);
            printf("Dimensions              : %d x %d\n",
                   entete.imhead.largeur,
                   entete.imhead.hauteur);

            printf("Bits par pixel          : %d\n",
                   entete.imhead.BipParPixel);
            printf("Compression             : %d\n",
                   entete.imhead.compression);
            printf("Taille de l'image       : %d Ko (%d octets)\n",
                   entete.imhead.tailleImage/1024,
                   entete.imhead.tailleImage);
            printf("Resolution h            : %d\n",
                   entete.imhead.HResolution);
            printf("Resolution v            : %d\n",
                   entete.imhead.VResolution);
            printf("Nb couleurs utilisees   : %d\n",
                   entete.imhead.nbCouleurs);
            printf("Nb couleurs importantes : %d\n",
                   entete.imhead.nbCouleursImportantes);
            fclose(fichierSource);

        }
    }
    else{
      printf("Erreur d'ouverture du fichier !\n");
      printf("%s \n",nomFichier );

    }
}

