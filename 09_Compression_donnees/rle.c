/*********************************************************************
 *                                                                   *
 * Auteur   :   Touchard JP PS                                       *
 * Date     :   21/12/2015                                           *
 * Version  :   2.0                                                  *
 * SUJET    :   Correction du TD sur la compression RLE              *
 *              programme principal pour compresser                  *
 *              ou decompresser des images au format BMP             *
 * Remarque :   Ce programme fonctionne uniquement pour des          *
 *              images dont la largeur est un multiple de 4          *
 * Compilation :  gcc -Wall rle.c biblio_rle.c -o rle		     *
 *********************************************************************/


#include "biblio_rle.h"

int main(int argc, char *argv[])
{
    char choix;
    int erreur =0;

    printf("Compression RLE\n\n");

    if (argc!=4){
        printf("Usage  : rle option fichier_source fichier_destination\n");
        printf("Option : c pour compression\n");
        printf("       : d pour décompression\n");
    }
    else{
        printf(" argc vaut : %d \n", argc);
        printf(" Premier argument   :  %s\n",  argv[0]);
        printf(" Deuxieme argument  :  %s\n",  argv[1]);
        printf(" Troisieme argument :  %s\n",  argv[2]);
        printf(" Quatrieme argument :  %s\n\n",argv[3]);
        sscanf(argv[1]," %c",&choix);

        switch(choix){
        case 'c':
            erreur = RLEcompresse(argv[2],argv[3]);
            if (erreur==0)
                printf(" Compression reussie !\n\n");
            else
                printf(" erreur %d!\n\n", erreur);
            break;

        case 'd' :
            erreur = RLEdecompresse (argv[2], argv[3]);
            if (erreur==0)
                printf(" Decompression reussie !\n\n");
            else
                printf(" erreur %d!\n\n", erreur);
            break;

        default  :
            printf(" Premier argument non valide : d ou c\n");
            exit(-1);
        }
    }
    return 0;
}
