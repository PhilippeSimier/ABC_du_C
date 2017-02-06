#include "biblio_Meteo.h"

void meteoAffichage(char meteo){
    unsigned char tendance, etat;

    tendance = meteo & 0x0F;
    switch (tendance){
    case 0:
        printf("Pression stable \n");
        break;
    case 1:
        printf("Pression en hausse \n");
        break;
    case 2:
        printf("Pression en baisse \n");
        break;
    default:
        printf("Tendance inconnue \n");
        break;
    }

    etat = (meteo >> 4) & 0x0F;
   switch (etat){
    case 0:
        printf("Pluvieux \n");
        break;
    case 1:
        printf("Nuageux \n");
        break;
    case 2:
        printf("Ensoleillé \n");
        break;
    default:
        printf("Etat inconnue \n");
        break;
    }
}

void meteoAffichageOptimisee(char meteo){
    char *tendancePression[3] = { "stable\n", "en hausse\n", "en baisse\n"};
    char *etatCiel[3] = { "pluvieux\n", "nuageux\n", "ensoleillé\n"};
    char tendance = meteo & 0x0F;
    if (tendance <= 2)
         printf("La tendance est %s", tendancePression[tendance]);
    else
        printf ("Erreur tendance\n");

    char etat = (meteo >> 4) & 0x0F;
    if (etat <= 2)
         printf("Le temps est %s", etatCiel[etat]);
    else
        printf ("Erreur etat\n");

}
