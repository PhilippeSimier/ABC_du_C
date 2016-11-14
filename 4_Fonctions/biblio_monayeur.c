#include <stdio.h>
#include <stdlib.h>
#define DELTA 0.001

int demanderBoisson()
{
    int choixBoisson;
    int prixBoisson;
    system("clear");
    printf("Choisissez votre boisson :\n");
    printf("1 -> Café long  [1.5€]\n");
    printf("2 -> Café cours [0.8€]\n\n");
    printf("Votre choix : ");
    scanf("%d", &choixBoisson);
    switch (choixBoisson){
    case 1:
        prixBoisson = 150;
        break;
    case 2:
        prixBoisson = 80;
        break;
    }
    return prixBoisson;
}

int attendrePiece(int prixBoisson, int pieceUser[])
{
    int piece;
    double somme = 0;

    printf("Le prix est de %.2f €\n", ((float)(prixBoisson)/100.0));
    printf("Monnaie :\n");
    printf(" 5 -> 2 €\n");
    printf(" 4 -> 1 €\n");
    printf(" 3 -> 0.50 €\n");
    printf(" 2 -> 0.20 €\n");
    printf(" 1 -> 0.10 €\n");

    do{
        printf("Pièce à entrer :");
        scanf("%d", &piece);
        switch (piece){
        case 5:
            somme = somme + 200;
            pieceUser[4]++;
            break;
        case 4:
            somme = somme + 100;
            pieceUser[3]++;
            break;
        case 3:
            somme = somme + 50;
            pieceUser[2]++;
            break;
        case 2:
            somme = somme + 20;
            pieceUser[1]++;
            break;
        case 1:
            somme = somme + 10;
            pieceUser[0]++;
            break;
        }
        printf("La somme que vous avez entrée est de %.1f€\n", ((float)(somme))/100.0 );
    }
    while(prixBoisson > somme);
    // retourne la somme à rendre
    return somme - prixBoisson;
}

void rendrePiece(int rendrePrix, int valPiece[], int nbPiece[], int pieceRendu[])
{
    int i;
    // remise à zéro du tableau des pièces à rendre.
    for(i = 0; i < 5; i++){
	pieceRendu[i] = 0;
    }
    // mise à jours des piéces à rendre on commence par les plus grandes
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
}

// Ajoute les pièces du client dans la caisse du monayeur
void ajouterPiece( int nbPiece[], int pieceUser[])
{
    int i;

    for(i = 0; i < 5; i++){
                nbPiece[i] = nbPiece[i] + pieceUser[i];
    }
}
