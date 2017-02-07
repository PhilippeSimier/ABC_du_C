/*******************************************************
*   4. Ecrivez un programme qui va créer 5 personnes
*   et sauvegarder les données dans un fichier.
*         En mode haut niveau avec fprintf.
*         En mode haut niveau avec fwrite.
*
*   Compilation : gcc -std=c11 q4.c biblio_q4.c -o q4
********************************************************/
#include "biblio_q4.h"



int main()
{
    FILE * fpText;
    FILE * fpBinaire;
    int nb = 5;
    typePersonne *liste[5];

    fpText    = fopen("fichierNom","w");
    fpBinaire = fopen("fichierBinaire","w");

    testErreur();

    for(int i=0; i < nb; i++){
        liste[i] = CreerPersonne();
        sauvegarderTexte(liste[i], fpText);
        sauvegarderBinaire(liste[i], fpBinaire);
    }
    fclose(fpText);
    fclose(fpBinaire);
    return 0;
}
