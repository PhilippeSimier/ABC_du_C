#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <errno.h>

#include "biblio_livre.h"

char cleISBN(char *codeISBN){
    int somme = 0;
    int cle;
    int rang = 1;

    for (; *codeISBN; codeISBN++){
        if(*codeISBN >= '0' && *codeISBN <= '9' && rang <= 9){
            somme += rang * (*codeISBN - '0');
            rang++;
        }
    }
    cle = somme % 11;
    if (cle == 10)
        return 'X';
    else
        return cle + '0';
}

int verificationISBN(char *codeISBN){

    int longueur = strlen(codeISBN);
    if ((longueur == 13) && (cleISBN(codeISBN) == codeISBN[12]))
        return 1;
    else
        return 0;
}

void effacerEcran()
{
    system("clear");  // system("CLS"); pour windows
    printf(" +------------------------------------+\n");
    printf(" |     Base de données Livres         |\n");
    printf(" +------------------------------------+\n");
    printf("\n");
}

void continuer(){
    printf(" \n Pour continuer appuyez sur une touche\n");
    getchar();  // retire le CR
    getchar();  // attend une action sur le clavier
}

//fonction afficherGenre qui prend en paramètre
//un enum GENRE et affiche le genre correspondant.
void afficherGenre(GENRE typ){
    char *listeGenre[6]= {
   	"Roman" , "Policier" , "BD" , "Jeunesse" , "Loisirs" , "Sciences"
    };
    printf(" Genre     : %s\n", listeGenre[typ]);
}

// fonction ayant pour prototype
// void afficherUnLivre(LIVRE *ad) qui affiche
// les informations relatives au livre passé en paramètre.
void afficherUnLivre(LIVRE *liv)
{

    printf(" Titre     : %s\n", liv->titre);
    printf(" Auteur(s) : %s\n", liv->auteurs);
    printf(" Annee     : %d\n", liv->annee);
    afficherGenre(liv->type);
    printf(" Prix      : %.2f €\n", liv->prix);
    printf(" ISBN      : %s\n", liv->identifiant);
    printf(" Quantite: : %d\n", liv->quantite);
}

//fonction ayant pour prototype LIVRE *creerUnLivre() qui va demander les informations relatives à un livre
//et mettre à jour la structure (allouée dynamiquement) correspondante avant de retourner l'adresse de cette dernière.

LIVRE *creerUnLivre()
{
    LIVRE *liv;
    liv=(LIVRE *) malloc(sizeof(LIVRE));
    getchar();
    printf(" Titre   : ");
    scanf("%[^\n]", liv->titre);
    getchar();
    printf(" Auteurs : ");
    scanf("%[^\n]", liv->auteurs);
    getchar();
    printf(" Année   : ");
    scanf("%d", &liv->annee);
    printf(" Genre   : ");
    scanf("%u", &liv->type);
    printf(" Prix    : ");
    scanf("%lf", &liv->prix);
    do{
    	printf(" ISBN   : ");
    	scanf("%13s", liv->identifiant);
    }
    while(verificationISBN(liv->identifiant)==0);
    printf(" Quantite : ");
    scanf("%d", &liv->quantite);
    return liv;
}


int ajouterUnLivre(LIVRE *tab[], int nb) {
    tab[nb]=creerUnLivre();
    //tab[nb]=creerUnLivreRapide();
    nb++;
    return nb;
}

void afficherLivres(LIVRE *liv[], int nb)
{
    int n;
    printf("+-----+----------------------+-------------------+---------------+--------------+-------+\n");
    printf("| Num |                Titre |     Auteur(s)     | ISBN          | Prix         | Qte   |\n");
    printf("+-----+----------------------+-------------------+---------------+--------------+-------+\n");
    for (n=0; n<nb; n++) {
    	printf("| %3d ",n);
        printf("| %20s ", liv[n]->titre);
        printf("| %17s ", liv[n]->auteurs);
        printf("| %13s ", liv[n]->identifiant);
        printf("| %.2lf  €\t", liv[n]->prix);
        printf("| %3d \t|\n", liv[n]->quantite);
    }
    printf("+-----+----------------------+-------------------+---------------+--------------+-------+\n");
}

int supprimerUnLivre(LIVRE *tab[], int indice, int nb)
{

    printf("nb start %d\n", nb);
    int n;
    if (indice>=0) {
    	printf("del %p\n", tab[indice]);
    	free(tab[indice]);
    for (n=indice; n<(nb-1); n++)
    {
      	tab[n]=tab[n+1];
    }
    nb=nb-1;
  }
  printf("nb livres %d\n", nb);
  return nb;
}


//fonction permettant de supprimer toutes les fiches.

int supprimerToutLesLivres(LIVRE *tab[], int nb)
{
  int n;
  for (n=0; n<nb; n++)
  {
    free(tab[n]);
  }
  return 0;
}

//retoune l'indice dans le tableau qui correspond au numero ISBN

int quelLivre(LIVRE *tab[], int nb)
{
  char isbn[14];
  int n,ret;
  printf("quel numero ISBN ? : ");
  scanf("%s", isbn);
  int indiceLivre=-1;
  for (n=0; n<nb; n++)
  {
    ret=strcmp (isbn, tab[n]->identifiant);
    if (ret==0) {
      printf("Livre trouvé %s, %s, %s, quantité %d\n\n",
			tab[n]->identifiant,
			tab[n]->titre,
			tab[n]->auteurs,
			tab[n]->quantite);
      indiceLivre=n;
    }
  }
  if  (indiceLivre<0) printf("Ref inconnue\n\n");
  return indiceLivre;
}


void modifieUnLivre(LIVRE *tab[], int nb)
{
    char s[101];
    int ret;
    getchar();
    printf(" Titre %s : ", tab[nb]->titre);
    ret = scanf("%[^\n]", s);
    if (ret==1) strcpy(tab[nb]->titre,s);
    getchar();
    printf(" Auteurs %s : ", tab[nb]->auteurs);
    ret = scanf("%[^\n]", s);
    if (ret==1) strcpy(tab[nb]->auteurs,s);
    getchar();
    printf(" Annee : ");
    int entier = 0;
    ret = scanf("%d", &entier);
    if (ret==1 && entier!=0) tab[nb]->annee = entier;
    printf(" Genre : ");
    scanf("%u", &tab[nb]->type);
    double prix = 0.0;
    printf(" Prix : ");
    ret = scanf("%lf", &prix);
    if (ret==1 && prix!= 0.0) tab[nb]->prix = prix;
    printf(" Quantité : \n");
    scanf("%d", &entier);
    if (ret==1) tab[nb]->quantite = entier;
}

double prixDuStock(LIVRE *tab[], int nb){

    double somme=0;
    for (int n=0; n<nb; n++){
    	somme += tab[n]->prix * tab[n]->quantite;
    }
    return somme;
}

void calculPrix(double taxe1, double taxe2, double *prix){

    double horstaxe=*prix/(1+(taxe1/100));
    *prix = horstaxe*(1+(taxe2/100));
}

void actualiserLivre(LIVRE *tab[], int nb){
//manque la saisie des taxes si changement (non précisé dans le texte)
    for (int n=0;n<nb;n++){
    calculPrix(5.5, 19.6, &tab[n]->prix);
  }
}


void afficheMenu(LIVRE *tab[], int compteurLivre)
{
  int indice;

  char choixMenu;
  do {
    effacerEcran();
    printf(" Nb de livres %d \n", compteurLivre);
    printf(" A : Ajouter une fiche livre\n");
    if (compteurLivre!=0) {
      printf(" S : Supprimer une fiche livre\n");
      printf(" M : Modifier une fiche livre\n");
      printf(" V : Voir le contenu d'une fiche livre\n");
      printf(" L : tableau des fiches livres\n");
      printf(" P : Actualiser le prix des livres\n");
      printf(" R : Rechercher un livre\n");
      printf(" T : Calculer le prix du stock\n");
    }
    printf(" Q : Quitter\n\n");
    printf(" Votre choix : ");
    scanf(" %c", &choixMenu);
    switch(choixMenu){
    case 'A' :
    case 'a' :
        effacerEcran();
      	compteurLivre=ajouterUnLivre(tab, compteurLivre);
        continuer();
      	break;
    case 'S' :
    case 's' :
        effacerEcran();
      	indice=quelLivre(tab, compteurLivre);
      	if (indice>=0) compteurLivre=supprimerUnLivre(tab, indice, compteurLivre);
      	continuer();
        break;
    case 'M' :
    case 'm' :
	effacerEcran();
      	indice=quelLivre(tab, compteurLivre);
      	if (indice>=0) modifieUnLivre(tab, indice);
      	continuer();
  	break;
    case 'V' :
    case 'v' :
	effacerEcran();
      	indice=quelLivre(tab, compteurLivre);
      	if (indice>=0) afficherUnLivre(tab[indice]);
	continuer();
      	break;
    case 'L' :
    case 'l' :
	effacerEcran();
      	afficherLivres(tab, compteurLivre);
	continuer();
      	break;
    case 'P' :  //actualiser prix
    case 'p' :
	effacerEcran();
      	actualiserLivre(tab, compteurLivre);
      	continuer();
  	break;
    case 'R' :  //rechercher un livre
    case 'r' :
        effacerEcran();
        quelLivre(tab, compteurLivre);
        continuer();
      	break;
    case 'T' :  //prix du stock
    case 't' :
        effacerEcran();
       	printf("le prix du stock est de : %.2f",prixDuStock(tab, compteurLivre));
      	continuer();
 	break;
    case 'Q' :
    case 'q' :
	enregistrerBase(tab, compteurLivre);
      	printf("bye\n");
      	break;
    default :
      	printf("erreur\n");
	continuer();
    }
  }
  while (choixMenu!='Q');
  compteurLivre=supprimerToutLesLivres(tab, compteurLivre);
}
// Enregistrement dans un fichier de la base livre
void enregistrerBase(LIVRE *tab[], int nb)
{

    FILE *pFich = fopen("livres.txt", "w+");
    if(errno != 0){
        printf("Erreur n'%d\n", errno);
        exit(0);
    }
    for(int j = 0; j < nb; j++){
        fprintf(pFich, "%s\n",   tab[j]->titre);
        fprintf(pFich, "%s\n",   tab[j]->auteurs);
        fprintf(pFich, "%d ",    tab[j]->annee);
        fprintf(pFich, "%u ",    tab[j]->type);
        fprintf(pFich, "%.2lf ", tab[j]->prix);
	fprintf(pFich, "%s ",    tab[j]->identifiant);
        fprintf(pFich, "%d\n",   tab[j]->quantite);
    }
    fclose(pFich);
}

int ouvrirBase(LIVRE *tab[], int nb){

    int res;
    LIVRE *liv;

    FILE *pFich = fopen("livres.txt", "r");
    if(errno != 0){
        printf("Erreur n'%d\n", errno);
        exit(0);
    }
    while(!feof(pFich)){
     	liv=(LIVRE *) malloc(sizeof(LIVRE));
	fscanf(pFich,"%[^\n]\n", liv->titre);
	fscanf(pFich,"%[^\n]\n", liv->auteurs);
	res = fscanf(pFich, "%d %u %lf %s %d\n",
			&liv->annee,
			&liv->type,
			&liv->prix,
			liv->identifiant,
		        &liv->quantite);
        if (res == 5){
        	tab[nb] = liv;
		nb++;
        }
        else
	   free(liv);
    }
    fclose(pFich);
    printf("nb enregistrements lu : %d\n", nb);
    return nb;
}
