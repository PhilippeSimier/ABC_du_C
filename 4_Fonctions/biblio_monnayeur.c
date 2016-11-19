#include <stdio.h>
#include <stdlib.h>
#include "biblio_monnayeur.h"

/* la valeur des pièces en centimes d'euros,
   C'est une variable globale              */
const int valPiece[NB] = VALPIECE;

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
    char *designation[NBP] = DESIGNATION_PRODUITS;
    // Le tableau des prix correspondants
    int  prix[NBP] = PRIX_PRODUITS;
    char choix;
    int i;
    do{
    	system("clear");
        choix = -1;  // -1 correspond à aucune boisson de sélectionnée
    	printf("Boissons ou Snacks:\n\n");
        for (i = 0; i<11 ; i++){
    		printf("  %c -> %15s\t[%.2f €]\n", 'A'+i, designation[i], conv(prix[i]) ); // Affichage des produits ditribués
    	}
        printf("\nVotre choix : ");
    	scanf(" %c", &choix);  // attention de ne pas oublier le blanc devant %c
        i = (int)(choix - 'A');
    }
    while (i <0 || i > (NBP-1));  // Attention pour un tableau de taille 10 les indices vont de 0 à 9
    system("clear");
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
    int piece;
    char choix;
    double somme = 0;
    int i;

    // remise à zéro du nb de  pièces remise par le client
    for ( i = 0; i < NB; i++){
 	pieceUser[i]= 0;
    }
    // Affichage du tableau des valeurs piéces acceptées (tableau globale)
    printf("Pièces ou billets acceptés :\n");
    for (i=NB-1 ; i >= 0; i--){   // attention les indices du tableau vont de 0 à NB-1
       printf(" %c -> %.2f  €\n", i+'A' , conv(valPiece[i]) );
    }

    do{
        printf("Votre Pièce ou billet : ");
        piece = -1; // correspond à l'absence de piece
        scanf(" %c", &choix);
        piece = choix - 'A';
        if (piece < NB && piece >=0){
           somme += valPiece[piece];
           pieceUser[piece]++;  // actualisation du tableau des piéces remises
	   printf("La somme entrée est de %.2f €\n", conv(somme) );
        }
        else{
 	    printf("Pièce ou billet refusé !!\n");
        }
    }
    while(prixBoisson > somme);
    printf("Somme à rendre : %.1f €\n", conv(somme - prixBoisson));
    // retourne la somme à rendre
    return somme - prixBoisson;
}

/* Fonction pour rendre la monnaie
   Renvoie 1 si possible ou 0 si pas assez de monnaie disponible 
   dans la caisse du monayeur*/
int rendrePiece(int rendrePrix, int pieceCaisse[], int pieceRendu[])
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
            while((rendrePrix >= valPiece[i]) && (pieceCaisse[i] != 0)){
                rendrePrix = rendrePrix - valPiece[i];
                pieceRendu[i]++;
                pieceCaisse[i]--;
            }
        }
    }
    if (rendrePrix == 0)
	return 1;
    else // pas assez de pièces en caisse pour rendre la monnaie
	for(i=0; i < NB; i++){  // je les remet dans la caisse
	    pieceCaisse[i] = pieceCaisse[i] + pieceRendu[i];
	}
        return 0;
}

// Ajoute les pièces du client dans la caisse du monayeur
void ajouterPiece( int pieceCaisse[], int pieceUser[])
{
    int i;
    for(i = 0; i < NB; i++){
         pieceCaisse[i] = pieceCaisse[i] + pieceUser[i];
    }
}

// Fonction pour afficher la monnaie à rendre
void afficherMonnaieRendue(int pieceRendu[])
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
void afficherCaisse(int pieceCaisse[])
{
    int i;
    int somme = 0;

    system("clear");
    printf("Le contenu de la caisse est :\n\n");
    for(i = 0; i < NB; i++){
	somme = somme + pieceCaisse[i] * valPiece[i];
        if(valPiece[i]>200)
	    printf("\t%d\tBillet(s) de %.2f €\n", pieceCaisse[i], conv(valPiece[i]) );
        else
            printf("\t%d\tPiece(s)  de %.2f €\n", pieceCaisse[i], conv(valPiece[i]) );
    }
    printf("\n");
    printf("Le total de la caisse est : %.2f €\n\n", conv(somme) );
    continuer();
}


