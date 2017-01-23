/***************************************************************
*   Programme pour créer une image BMP représentant
*   le drapeau Francais
*
*   Compilation: gcc drapeau.c biblio_drapeau.c -o drapeau
*   Utilisation: ./drapeau
****************************************************************/

#include "biblio_drapeau.h"

int main()
{
    int largeur, hauteur;
    char nom[255];

    printf("Création d'un drapeau français au format BMP\n");
    printf(" Nom du fichier : ");
    scanf("%s", nom);
    printf(" Largeur de l'image : ");
    scanf("%d", &largeur);


    printf(" Hauteur de l'image : ");
    scanf("%d", &hauteur);
    creerImage("./", nom, largeur, hauteur);
    return 0;
}
