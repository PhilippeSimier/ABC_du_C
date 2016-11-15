#include <stdio.h>
#include <stdlib.h>

void continuer(){
    printf(" Pour continuer appuyez sur touche\n");
    getchar();  // retire le CR
    getchar();  // attend une action sur le clavier
    system("clear");  // efface l'écran
}


/* Fonction pour afficher la liste des boissons et de demander quelle boisson
 le client désire parmi les boissons disponibles.
 Retourne le prix de la boisson demandée. */
int demanderBoisson()
{
    char choixBoisson;
    int prixBoisson;
    char erreur;  // variable pour indiquer une erreur de saisie

    do{
    	system("clear");
        erreur = 0;
    	printf("Choisissez votre boisson :\n");
    	printf("  1 -> Café long  [1.5€]\n");
    	printf("  2 -> Café cours [0.8€]\n\n");
    	printf("Votre choix : ");
    	scanf(" %c", &choixBoisson);  // ne pas oublier le blanc devant %c pour vider le buffer
    	switch (choixBoisson){
    	    case '1':
            	prixBoisson = 150;
            	break;
            case '2':
            	prixBoisson = 80;
            	break;
            default:
	    	erreur = 1;
    	}
    }
    while (erreur == 1);
    return prixBoisson;
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
    for ( i = 0; i < 5; i++){
 	pieceUser[i]= 0;
    }

    printf("Le prix est de %.2f €\n", ((float)(prixBoisson)/100.0));
    printf("Pièces acceptées :\n");
    printf(" 5 -> 2 €\n");
    printf(" 4 -> 1 €\n");
    printf(" 3 -> 0.50 €\n");
    printf(" 2 -> 0.20 €\n");
    printf(" 1 -> 0.10 €\n");

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
        default:
	    erreur = 1;
        }
        if (erreur == 0)
            printf("La somme entrée est de %.1f€\n", ((float)(somme))/100.0 );
        else
 	    printf("Pièce refusée\n");
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
    for(i = 0; i < 5; i++){
	pieceRendu[i] = 0;
    }
    // mise à jours des piéces à rendre, on commence par les plus grandes
    for(i = 0; i < 5; i++){
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
	for(i=0; i < 5; i++){  // je les remet dans la caisse
	    nbPiece[i] = nbPiece[i] + pieceRendu[i];
	}
        return 0;
}

// Ajoute les pièces du client dans la caisse du monayeur
void ajouterPiece( int nbPiece[], int pieceUser[])
{
    int i;
    for(i = 0; i < 5; i++){
         nbPiece[i] = nbPiece[i] + pieceUser[i];
    }
}

// Fonction pour afficher la monnaie à rendre
void afficherMonnaieRendue(int pieceRendu[], int valPiece[])
{
    int i;
    printf("La monnaie à rendre :\n");
    for(i = 0; i < 5; i++){

	if (pieceRendu[i] != 0)
           printf("%d pièce(s) de %.1f€\n",  pieceRendu[i], ((float)(valPiece[i])/100.0));
    }
}

// Fonction pour afficher le contenu de la caisse
// juste pour vérifier que des petits malins ne viennent pas piquer
// dans la caisse !!!
void afficherCaisse(int nbPiece[], int valPiece[])
{
    int i;

    system("clear");
    printf("Le contenu de la caisse est :\n");
    for(i = 0; i < 5; i++){
	printf("  - Pieces de %.2f € : %d\n", ((float)valPiece[i])/100.0 , nbPiece[i]);
    }
    continuer();
}


