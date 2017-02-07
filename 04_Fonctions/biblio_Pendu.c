#include "biblio_Pendu.h"


int motEstTrouve(char *motATtrouver, char *motPropose)
{
    return(strcmp(motATtrouver,motPropose));
}


int verifierLettrePropose(char *lettresProposees, int nbLettreProposee, char lettre)
{
    int lettreTrouve=1;
    int i;
    if((lettre < 'a' && lettre >'z')||(lettre<'A' && lettre >'Z'))
    {
        lettreTrouve=0;
    }
    else
    {
        for(i = 0; i<nbLettreProposee; i++)
        {

            if(lettre == lettresProposees[i])
            {
                lettreTrouve=0;
            }
        }
    }
    return lettreTrouve;

}

//retourne une valeur entière E[0..maxAlea[
unsigned int aleatoire( unsigned int maxAlea )
{
    struct timeb t;
    float a, b ;
    unsigned int nbmilli;
    ftime( &t );
    nbmilli = t.time * 1000 + t.millitm;
    srand( nbmilli );
    a = rand();
    b = ( maxAlea * a ) / RAND_MAX;
    return( ( unsigned int )b );
}

void initialiserMot(char *motCourant,int longueurMot)
{
    int compteur=0;
    for(compteur=0; compteur<=longueurMot; compteur++)
    {
        motCourant[compteur]='-';
    }
    motCourant[longueurMot]='\0'; // pour que le tableau de caractères devienne une chaine de caractères
}

void effacerEcran()
{
    system("clear");
}

int afficherMenu()
{
    char choix;
    int resultat=0;
    do
    {
        printf("Voulez-vous jouer ou quitter ? (j/q) : ");
        scanf(" %c",&choix);  // Ne pas oublier l'espace devant %c
        switch(choix)
        {
        case 'j' :
            resultat = 1;
            break;

        case 'q' :
            resultat = -1;
            break;

        default :
            printf("Je n'est pas bien compris votre choix !\n");
        }
    }while (resultat == 0);
    return resultat;
}

void afficherPendu(int nroErreur)
{
    switch(nroErreur)
    {
    case 0 :
        printf("\n\n\n\n\n\n\n\n---------------");
        break;
    case 1 :
        printf("\n\n\n\n\n\n\n/|\n---------------");
        break;

    case 2 :
        printf("\n\n |\n |\n |\n |\n |\n/|\n---------------");
        break;

    case 3 :
        printf("\n ________\n |\n |\n |\n |\n |\n/|\n---------------");
        break;

    case 4 :
        printf("\n ________\n |     |\n |\n |\n |\n |\n/|\n---------------");
        break;

    case 5 :
        printf("\n ________\n |     |\n |     O\n |\n |\n |\n/|\n---------------");
        break;

    case 6 :
        printf("\n ________\n |     |\n |     O\n |    /|\\\n |\n |\n/|\n---------------");
        break;

    case 7 :
        printf("\n ________\n |     |\n |     O\n |    /|\\\n |    / \\\n |\n |\n/|\n---------------");
        break;

    }
}

void afficherLettre(char *histo, int nbLettre)
{
    int compteur = 0;
    printf("Lettre(s) déjà proposée(s) : ");
    for(compteur=0; compteur<nbLettre; compteur++)
    {
        printf("%c ",histo[compteur]);
    }
    printf("\n");
}

int placerLettre(char *motATrouver, char *motCourant, char lettrePropose)
{
    int compteur=0, resultat=0, correct=0;
    for(compteur=0; compteur<strlen(motATrouver); compteur++)
    {
        if(lettrePropose == motATrouver[compteur])
        {
            motCourant[compteur]=lettrePropose;
            correct=1;
        }
    }
    if(correct==0)
    {
        resultat =1;
    }
    return resultat;
}
