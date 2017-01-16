/************************************************************
*   TD3 Modification d'un fichier image
*
*   Compilation : gcc -Wall main.c biblio_TD3.c -o rouge
*   Exécution   : rouge plasma.bmp ./ plasmaRouge.bmp
*************************************************************/

#include "biblio_TD3.h"


int main( int argc, char *argv[])
{
    printf("Exo sur les fichiers BMP\n\n");
    if (argc !=4){
        printf(" Usage : executable chemin fichier source fichier destination\n");
        return 0;
    }
    else{
        afficheEnTeteFichierBmp(argv[2], argv[1]);
        afficheEnTeteImageBMP(argv[2], argv[1]);
        changePaletteBMP(argv[2], argv[1], argv[3]);

    }
    return 0;
}
