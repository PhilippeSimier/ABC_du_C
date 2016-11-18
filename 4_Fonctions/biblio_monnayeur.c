#include <stdio.h>
#include <stdlib.h>
#include "biblio_monnayeur.h"

void continuer(){
    printf(" Pour continuer appuyez sur une touche\n");
    getchar();  // retire le CR
    getchar();  // attend une action sur le clavier
    system("clear");  // efface l'écran
}
// fonction pour convertir les centimes  en €
float conv(int centime){
    return ((float)(centime/100.0));
}

/* Fonction pour afficher la liste des boissons et demander quelle boisson
 le client désire parmi les boissons disponibles.
 Retourne le prix de la boisson demandée en centime d'Euros. */
int demanderBoisson()
{   // le tableau des désignations
    char *designation[NBP]={"Evian", "Coca cola", "Oasis Tropical", "Ice Tea Pêche", "Orangina", "Red Bull",
                          "Schweppes Agrum", "Kinder Bueno", "Lay'S Sel", "Happy Life", "Duo Twix"};
    // Le tableau des prix correspondants
    int  prix[NBP]   	={ 180, 200, 200, 200, 150 ,250 ,
                           200, 180, 100, 200, 150 };
    int choixBoisson;
    int  i;

    do{
    	system("clear");
    	printf("Boissons ou snacks:\n\n");
        for (i = 0; i<11 ; i++){
    		printf("  %2d -> %15s\t[%.2f €]\n", i, designation[i], conv(prix[i]) );
    	}
        printf("\nVotre choix : ");
    	scanf(" %d", &choixBoisson);  // Attention à ne pas oublier le blanc devant %d pour vider le buffer
	i = choixBoisson; //- '0';
    }
    while (i<0 || i> (NBP-1));  // Attention pour un tableau de taille 10 les indices vont de 0 à 9
    printf("Vous avez choisi : %s le prix est %.2f €\n\n", designation[i], conv(prix[i]) );
    return prix[i];  // retourne le prix en centime d'euros
}

/* Fonction chargée d'attendre que le client place dans le monnayeur
   suffisamment de pièces selon la boisson choisie.
   Selon le prix de la boisson, demande au client d'ajouter de la monnaie
   jusqu'à atteindre ou dépasser le prix de la boisson.
   Retourne la somme que le monnayeur doit rendre et
   le tableau des pièces que le client a entrées.  */

int attendrePiece(int prixBoisson, int pieceUser[])
{
    char piece;
    double somme = 0;
    char erreur;  // Variable pour mémoriser une erreur 
    int i;
    // remise à zéro du nb de  pièces remise par le client
    for ( i = 0; i < NB; i++){
 	pieceUser[i]= 0;
    }

    printf("Pièces acceptées :\n");
    printf(" 5 -> 2 €\n");
    printf(" 4 -> 1 €\n");
    printf(" 3 -> 0.50 €\n");
    printf(" 2 -> 0.20 €\n");
    printf(" 1 -> 0.10 €\n");
    printf(" 0 -> 0.05 €\n");

    do{
        erreur = 0;
        printf("Votre Pièce : ");
        scanf(" %c", &piece);  // Attention  ne pas oublier le blanc devant %c
        switch (piece){
        case '5':
            somme = somme + 200;
            pieceUser[0]++;
            break;
        case '4':
            somme = somme + 100;
            pieceUser[1]++;
            break;
        case '3':
            somme = somme + 50;
            pieceUser[2]++;
            break;
        case '2':
            somme = somme + 20;
            pieceUser[3]++;
            break;
        case '1':
            somme = somme + 10;
            pieceUser[4]++;
            break;
        case '0':
            somme = somme + 5;
            pieceUser[5]++;
            break;

        default:
	    erreur = 1;
        }
        if (erreur == 0)
            printf("La somme entrée est de %.2f€\n", conv(somme) );
        else
 	    printf("Pièce refusée !!\n");
    }
    while(prixBoisson > somme);
    // retourne la somme à rendre
    return somme - prixBoisson;
}

/* Fonction pour rendre la monnaie
   Renvoie 1 si possible ou 0 si pas assez de monnaie disponible 
   dans la caisse du monayeur*/
int rendrePiece(int rendrePrix, int valPiece[], int nbPiece[], int pieceRendu[])
{
    int i;
    // remise à zéro du tableau des pièces à rendre.
    for(i = 0; i < NB; i++){
	pieceRendu[i] = 0;
    }
    // mise à jours des piéces à rendre, on commence par les plus grandes
    for(i = 0; i < NB; i++){
        // je peux rendre des pieces de la valeur courante
        if(valPiece[i] <= rendrePrix){
            // tant que je peux rendre des pieces de la valeur courante, je le fais
            while((rendrePrix >= valPiece[i]) && (nbPiece[i] != 0)){
                rendrePrix = rendrePrix - valPiece[i];
                pieceRendu[i]++;
                nbPiece[i]--;
            }
        }
    }
    if (rendrePrix == 0)
	return 1;
    else // pas assez de pièces en caisse pour rendre la monnaie
	for(i=0; i < NB; i++){  // je les remet dans la caisse
	    nbPiece[i] = nbPiece[i] + pieceRendu[i];
	}
        return 0;
}

// Ajoute les pièces du client dans la caisse du monayeur
void ajouterPiece( int nbPiece[], int pieceUser[])
{
    int i;
    for(i = 0; i < NB; i++){
         nbPiece[i] = nbPiece[i] + pieceUser[i];
    }
}

// Fonction pour afficher la monnaie à rendre
void afficherMonnaieRendue(int pieceRendu[], int valPiece[])
{
    int i;
    printf("Votre monnaie à rendre :\n");
    for(i = 0; i < NB; i++){

	if (pieceRendu[i] != 0)
           printf("%d pièce(s) de %.2f€\n",  pieceRendu[i], conv(valPiece[i]) );
    }
}

// Fonction pour afficher le contenu de la caisse
// juste pour vérifier que des petits malins ne viennent pas piquer
// dans la caisse !!!
void afficherCaisse(int nbPiece[], int valPiece[])
{
    int i;
    int somme = 0;

    system("clear");
    printf("Le contenu de la caisse est :\n\n");
    for(i = 0; i < NB; i++){
	somme = somme + nbPiece[i] * valPiece[i];
        printf("\t%d\tPiece(s) de %.2f €\n", nbPiece[i], conv(valPiece[i]) );
    }
    printf("\n");
    printf("Le total de la caisse est : %.2f €\n\n", conv(somme) );
    continuer();
}


