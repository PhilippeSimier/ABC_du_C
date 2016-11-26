/************************************************************************
*   AIDEZ LE CENTRE DE TRI POSTAL !
*
*	Nous voulons gérer des colis arrivants dans un centre de tri
*       de colis. Nous pouvons recevoir trois types de colis:
*	léger, standard et lourd.
*	Les colis ont une vignette avec un code qui diffère en fonction
*	du type: pour les colis légers:
*	le chiffre 1, un espace, 4 lettres, un espace puis un identifiant
*			(un nombre entier).
*	Les colis standards:
*	le chiffre 2, un espace, leur poids (un nombre à virgule),
*			un espace, un identifiant (un nombre entier),
*			un espace puis 5 lettres.
*	Les colis lourds:
*	le chiffre 3, un espace, un identifiant (un nombre entier),
*		      un espace puis leur poids (un nombre a virgule).
*
*	On souhaite réaliser un programme qui affiche les colis a trier
*       avec une certaine uniformité pour plus de lisibilité.
*       Dans l'entrée du programme nous avons d'abord le nombre de colis
*       total à traiter. Vient ensuite pour chaque colis son code
*       sur une ligne. Votre programme doit afficher de manière uniforme
*       l'ensemble des colis à traiter, un par ligne, de cette manière:
*       d'abord l'identifiant, un espace puis le poids avec 1 chiffre
*       après la virgule. Pour les colis légers, on considère que le poids
*       vaut 1.0.
*
*	compilation : gcc -std=c11 colis_postaux.c -o colis_postaux
*       test	    : ./colis_postaux < input
***************************************************************************/
#include"stdio.h"
int main(){

    int nbColis;
    int type;
    char string[6];
    int identifiant;
    double poids;

    scanf("%d", &nbColis);
    for (int i=0; i<nbColis; i++){
        scanf("%d", &type);
        switch (type){
            case 1:
                scanf("%s %d", string, &identifiant);
                poids = 1.0;
                break;
            case 2:
                scanf("%lf %d %s", &poids, &identifiant, string);
                break;
            case 3:
                scanf("%d %lf", &identifiant, &poids);
                break;
        }
        printf("%d %.1lf\n", identifiant, poids);
    }
}
