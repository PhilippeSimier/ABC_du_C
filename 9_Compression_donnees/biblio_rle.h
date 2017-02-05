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

#ifndef BIBLIO_H_INCLUDED
#define BIBLIO_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#pragma pack(1)

typedef
    struct BMPImageEntete
    {
        unsigned int    taille_entete;
        int             largeur;
        int             hauteur;
        short           nbplans;     // toujours à 1
        short           BipParPixel;
        unsigned int    compression;
        unsigned int    tailleImage;
        unsigned int    HResolution;
        unsigned int    VResolution;
        unsigned int    nbCouleurs;  // nb de couleurs dans la palette
        unsigned int    nbCouleursImportantes;
    }BMPImageEntete;

typedef
struct BMPfichierHead
    {
        char            signature[2]; // BM pour les fichiers BMP
        unsigned int    taille;
        unsigned int    reserve;
        unsigned int    offsetimage; // offset des données images
        struct          BMPImageEntete imhead;
    }BMPfichierHead;

/* structure pour mémoriser une couleur  bleu vert rouge alpha              */
typedef struct couleur
{
	unsigned char   bleu,
                    vert,
                    rouge,
                    alpha;
} couleur;

typedef struct rle
{
    unsigned char  repetition,
                   valeur;
} rle;

void  afficheEnTeteFichier    (const char *nomFichier);
int  RLEdecompresse (const char *fichierSource,
                     const char *fichierDest);

int  RLEcompresse   (const char *fichierSource,
                     const char *fichierDest);

#endif // BIBLIO_H_INCLUDED
