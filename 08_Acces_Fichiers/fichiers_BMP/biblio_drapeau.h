#ifndef BIBLIO_DRAPEAU_H_INCLUDED
#define BIBLIO_DRAPEAU_H_INCLUDED



#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

#pragma pack(push, 1)

#define NB_COULEURS 8
#define RESOLUTION  75

typedef
    enum{
    	BLANC,
    	BLEU,
    	ROUGE
}INDICE;

typedef
    struct BMPImageEntete{
        unsigned int    taille_entete;
        unsigned int    largeur;
        unsigned int    hauteur;
        unsigned short  nbplans;
        unsigned short  bitParPixel;
        unsigned int    compression;
        unsigned int    tailleImage;
        unsigned int    hResolution;
        unsigned int    vResolution;
        unsigned int    nbCouleur;
        unsigned int    nbCouleurImportantes;
  }BMP_IMAGE_HEAD;

typedef
    struct BMPfichierHead{
        char            signature[2];
        unsigned int    taille;
        unsigned int    reserve;
        unsigned int    offsetImage;
        BMP_IMAGE_HEAD  imageHead;
    }BMP_FICHIER_HEAD;

typedef
    struct pixel{
        unsigned char bleu, vert, rouge, alpha;
} COULEUR;

#pragma pack(pop)

void testErreur();
void creerImage(char *chemin, char *nomFichier, int largeur, int hauteur);



#endif // BIBLIO_DRAPEAU_H_INCLUDED
