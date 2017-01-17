#ifndef BIBLIO_DRAPEAU_H_INCLUDED
#define BIBLIO_DRAPEAU_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#pragma pack(1)

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
  }BMPImageEnTete;

typedef
    struct BMPfichierHead{
        char            signature[2];
        int             taille;
        int             reserve;
        int             offsetImage;
        BMPImageEnTete imageHead;
    }BMPfichierHead;

typedef
    struct couleur{
        unsigned char bleu, vert, rouge, alpha;
} couleur;

void testErreur();
void creerImage(char *chemin, char *nomFichier, int largeur, int hauteur);

#endif // BIBLIO_DRAPEAU_H_INCLUDED
