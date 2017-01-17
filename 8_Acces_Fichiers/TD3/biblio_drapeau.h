#ifndef BIBLIO_DRAPEAU_H_INCLUDED
#define BIBLIO_DRAPEAU_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#pragma pack(1)

#define NB_COULEURS 3

typedef
    struct BMPImageEntete{
        unsigned int    taille_entete;
        unsigned int    largeur;
        unsigned int    hauteur;
        short           nbplans;
        short           bitParPixel;
        int             compression;
        unsigned int    tailleImage;
        int             hResolution;
        int             vTesolution;
        unsigned int    nbCouleur;
        int             nbCouleurImportantes;
  }BMP_IMAGE_HEAD;

typedef
    struct BMPfichierHead{
        char            signature[2];
        int             taille;
        int             reserve;
        int             offsetImage;
        BMP_IMAGE_HEAD  imageHead;
    }BMP_FICHIER_HEAD;

typedef
    struct couleur{
        unsigned char bleu, vert, rouge, alpha;
} COULEUR;

void testErreur();
void creerImage(char *chemin, char *nomFichier, int largeur, int hauteur);

#endif // BIBLIO_DRAPEAU_H_INCLUDED
