#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include "biblio_complexeSportif.h"

void effacerEcran()
{
    system("clear");
    afficher_couleur(MAGENTA,NOIR," +------------------------------------+ ");
    afficher_couleur(MAGENTA,NOIR," |  Base de données COMPLEXE SPORTIF  | ");
    afficher_couleur(MAGENTA,NOIR," +------------------------------------+ ");
    printf("\n");
}

void continuer(){
    printf(" Pour continuer appuyez sur une touche\n");
    getchar();  // retire le CR
    getchar();  // attend une action sur le clavier
    effacerEcran();
}

void afficher_couleur(int couleur, int couleur_f, char *chaine)
{
     printf("\033[%d;%dm%s\033[1;0m", 30+couleur, 40+couleur_f, chaine);
     printf("\n");
}

// Fonction pour vider le buffer d'entrée
// lit le buffer d'entrée jusqu'au  retour charriot ou fin de fichier
void vide(void){
    int c;
    do {
        c = getchar();
    } while (c != '\n'  && c != EOF);
}

// fonction pour transformer les minuscules en majuscules
void majuscule(char *s)
{
    for(; *s; s++){
    	if ( *s >= 'a' && *s <= 'z'){
             *s = *s - 32;
	}
    }
}

void testerOuvertureFichier()
{
    if(errno != 0)
    {
        printf("Erreur fichier : erreur n'%d\n", errno);
        exit(0);
    }
}

void afficherMenu(int compteurAdherent)
{
    printf("Que voulez-vous faire ?\n");

    if(compteurAdherent == 0)
    {
        printf(" a -> Ajouter une fiche adhérent\n");
	printf(" c -> Importer une liste d'adhérents\n");
        printf(" q -> Quitter\n\n");
    }
    else
    {
        printf(" a -> Ajouter une fiche adhérent\n");
        printf(" s -> Supprimer une fiche\n");
        printf(" m -> Modifier une fiche\n");
        printf(" v -> Voir le contenu d'une fiche\n");
        printf(" l -> Voir le contenu de l'ensemble des fiches\n");
        printf(" e -> Supprimer toutes les fiches\n");
        printf(" x -> Exporter adhérents\n");
        printf(" c -> Importer une liste d'adhérents\n");
        printf(" q -> Quitter\n\n");
    }
    printf("Votre choix : ");
}

void afficherDate(date dateAfficher)
{
    printf("%d/%d/%d", dateAfficher.jour, dateAfficher.mois, dateAfficher.annee);
}

void afficherActivite(sport listSport)
{
    switch (listSport)
    {
    case NATATION:
        printf("Natation ");
        break;
    case BASKETBALL:
        printf("Basketball ");
        break;
    case HANDBALL:
        printf("Handball ");
        break;
    case SQUASH:
        printf("Squash ");
        break;
    case TENNIS:
        printf("Tennis ");
        break;
    }
}

typeAdherent *creerUnAdherent()
{
    typeAdherent *adherent;
    int i, numSport;

    adherent = (typeAdherent*) malloc(sizeof(typeAdherent));
    printf("Nom : ");
    scanf("%15s", adherent->nom);
    majuscule(adherent->nom);
    vide(); //vide le buffer d'entrée des caractères résiduels
    printf("Prenom : ");
    scanf("%15s", adherent->prenom);
    vide(); //vide le buffer d'entrée des caractères résiduels
    printf("Date de naissance : ");
    printf("\n\tJour : ");
    scanf("%d", &adherent->dateDeNaissance.jour);
    printf("\tMois : ");
    scanf("%d", &adherent->dateDeNaissance.mois);
    printf("\tAnnée : ");
    scanf("%d", &adherent->dateDeNaissance.annee);
    printf("Numéro d'adhérent : ");
    scanf("%d", &adherent->numCarte);
    printf("Nombre d'activite : ");
    scanf("%d", &adherent->nbActivite);
    printf(" Quel sport voulez-vous faire ?\n");
    printf("  1 -> Natation\n");
    printf("  2 -> Basket\n");
    printf("  3 -> Hand\n");
    printf("  4 -> Squash\n");
    printf("  5 -> Tennis\n");

    for(i = 0; i < adherent->nbActivite; i++)
    {
        printf(" Sport n° %d ?\n",i+1);
        printf(" Votre choix : ");
        scanf("%d", &numSport);

        switch (numSport)
        {
        case 1:
            adherent->activite[i] = NATATION;
            break;
        case 2:
            adherent->activite[i] = BASKETBALL;
            break;
        case 3:
            adherent->activite[i] = HANDBALL;
            break;
        case 4:
            adherent->activite[i] = SQUASH;
            break;
        case 5:
            adherent->activite[i] = TENNIS;
            break;
        }
    }
    return adherent;
}

void afficherUnAdherent(typeAdherent *adherent[], int numeroCarte, int nb)
{
    int i, j;
    for(j = 0; j < nb; j++)
    {
        if(numeroCarte == adherent[j]->numCarte)
        {
	    afficher_couleur(NOIR,BLANC,"+------------Fiche Adhérent-------------+");
      	    printf("| Nom               : %15s\t|\n", adherent[j]->nom);
            printf("| Prénom            : %15s\t|\n", adherent[j]->prenom);
            printf("| Date de naissance : %d/%d/%d\t\t|\n", adherent[j]->dateDeNaissance.jour, adherent[j]->dateDeNaissance.mois, adherent[j]->dateDeNaissance.annee);
            printf("| Nb d'activité(s)  : %d\t\t\t|\n", adherent[j]->nbActivite);
            printf("| Activité          :");
	    for(i = 0; i < adherent[j]->nbActivite; i++)
            {
                afficherActivite(adherent[j]->activite[i]);
            }
            printf("\n");
            afficher_couleur(NOIR,BLANC,"+---------------------------------------+");
        }
    }
}

void afficherAdherents(typeAdherent *ad[], int nb)
{

    int i, j;
    afficher_couleur(BLANC,NOIR,"+-----+---------------+---------------+------------+-----------------------------------+");
    afficher_couleur(MAGENTA,NOIR,"| Num |           Nom |       Prenom  | Naissance  | Activités                         |");
    afficher_couleur(BLANC,NOIR,"+-----+---------------+---------------+------------+-----------------------------------+");
    for(j = 0; j < nb; j++)
    {
        printf("| %3d ",ad[j]->numCarte);
        printf("|%15s", ad[j]->nom);
        printf("|%15s", ad[j]->prenom);
        printf("| %2d/%2d/%2d |", ad[j]->dateDeNaissance.jour, ad[j]->dateDeNaissance.mois, ad[j]->dateDeNaissance.annee);
        for(i = 0; i < ad[j]->nbActivite; i++)
        {
            switch (ad[j]->activite[i])
            {
            case NATATION:
                printf("Natation ");
                break;
            case BASKETBALL:
                printf("Basket ");
                break;
            case HANDBALL:
                printf("Hand ");
                break;
            case SQUASH:
                printf("Squash ");
                break;
            case TENNIS:
                printf("Tennis ");
                break;
            }
        }
        printf("\033[86D");  // Moves the cursor backward by 80 columns;
        printf("\033[87C");  // Moves the cursor forward by 81 columns
        printf("|\n");
        afficher_couleur(MAGENTA,NOIR,"+-----+---------------+---------------+------------+-----------------------------------+");
    }
}

int ajouterUnAdherent(typeAdherent *tab[], int nb)
{
    tab[nb] = creerUnAdherent();
    nb++;
    return nb;
}

int supprimerUnAdherent(typeAdherent *tab[], int nro, int nb)
{
    int i, j;

    for(i = 0; i < nb; i++)
    {
        if(tab[i]->numCarte == nro)
        {
            free(tab[i]);
            for(j = i; j < nb; j++)
            {
                tab[j] = tab[j+1];
            }
	    nb--;
        }
    }
    return nb;
}

int supprimerAdherents(typeAdherent *tab[], int nb)
{
    int i;

    for(i = 0; i < nb; i++)
    {
        free(tab[i]);
    }
    return 0;
}

void modifierFiche(typeAdherent *tab[], int nro, int nb)
{
    int i;
    int choix;

    for(i = 0; i < nb; i++)
    {
        if(tab[i]->numCarte == nro)
        {
            do
            {
                printf("Quel paramètre voulez-vous modifier ?\n");
                printf("1- Nom\n");
                printf("2- Prénom\n");
                printf("3- Date de naissance\n");
                printf("4- Nombre d'activité\n");
                printf("5- Quitter\n");
                printf("Votre choix :");
                scanf("%d", &choix);

                switch (choix)
                {
                case 1:
                    printf("Nouveau nom :");
                    scanf("%s", tab[i]->nom);
                    break;
                case 2:
                    printf("Nouveau prénom :");
                    scanf("%s", tab[i]->prenom);
                    break;
                case 3:
                    printf("Nouveau jour de naissance :");
                    scanf("%d", &tab[i]->dateDeNaissance.jour);
                    printf("Nouveau mois de naissance :");
                    scanf("%d", &tab[i]->dateDeNaissance.mois);
                    printf("Nouvelle année de naissance :");
                    scanf("%d", &tab[i]->dateDeNaissance.annee);
                    break;
                case 4:
                    printf("Nouveau nombre d'activités :");
                    scanf("%d", &tab[i]->nbActivite);
                    break;
                }
            }
            while(choix != 5);
        }
    }
}

void sauvegardeAdherents(typeAdherent *ad[], int nb)
{
    char nomFichier[TAILLEMAX];

    printf("Nom du fichier de sauvegarde :");
    scanf("%s", nomFichier);
    strcat(nomFichier, ".txt");

    FILE *pFich = fopen(nomFichier, "w+");
    testerOuvertureFichier();
    int i, j;
    for(j = 0; j < nb; j++)
    {
        fprintf(pFich, "%d ", ad[j]->numCarte);
        fprintf(pFich, "%s ", ad[j]->nom);
        fprintf(pFich, "%s ", ad[j]->prenom);
        fprintf(pFich, "%d %d %d ", ad[j]->dateDeNaissance.jour, ad[j]->dateDeNaissance.mois, ad[j]->dateDeNaissance.annee);
        fprintf(pFich, "%d ", ad[j]->nbActivite);
        for(i = 0; i < ad[j]->nbActivite; i++)
        {
            switch (ad[j]->activite[i])
            {
            case NATATION:
                fprintf(pFich, "NATATION ");
                break;
            case BASKETBALL:
                fprintf(pFich, "BASKETBALL ");
                break;
            case HANDBALL:
                fprintf(pFich, "HANDBALL ");
                break;
            case SQUASH:
                fprintf(pFich, "SQUASH ");
                break;
            case TENNIS:
                fprintf(pFich, "TENNIS ");
                break;
            }
        }
        fprintf(pFich, "\n");
    }
    fclose(pFich);
}

int chargerAdherents(typeAdherent *tab[], int nb)
{
    int i, res;
    char activite[50];
    char nomFichier[TAILLEMAX];
    typeAdherent *adherent;
    printf("nb : %d\n",nb);
    printf("Nom du fichier txt à ouvrir : ");
    scanf("%s", nomFichier);

    strcat(nomFichier, ".txt");

    printf(" fichier : %s\n\n", nomFichier);
    FILE *pFich = fopen(nomFichier, "r");
    testerOuvertureFichier();
    printf("Fichier ouvert\n");

    while(!feof(pFich))
    {

        adherent = (typeAdherent *)malloc(sizeof(typeAdherent));
        memset(adherent, 0, sizeof(typeAdherent));

        res = fscanf(pFich, "%d %s %s %d %d %d %d", &adherent->numCarte,
					       adherent->nom,
                                               adherent->prenom,
                                              &adherent->dateDeNaissance.jour,
                                              &adherent->dateDeNaissance.mois,
                                              &adherent->dateDeNaissance.annee,
					      &adherent->nbActivite );
	if (res == 7){     // si le fscanf a réussi
	    for (i = 0; i < adherent->nbActivite; i++){
           	fscanf(pFich, "%s", activite);
	   	if(strcmp(activite, "NATATION")==0)  adherent->activite[i] = NATATION;
	   	if(strcmp(activite, "BASKETBALL")==0) adherent->activite[i] = BASKETBALL;
	   	if(strcmp(activite, "HANDBALL")==0)  adherent->activite[i] = HANDBALL;
	   	if(strcmp(activite, "SQUASH")==0)    adherent->activite[i] = SQUASH;
	   	if(strcmp(activite, "TENNIS")==0)    adherent->activite[i] = TENNIS;
            }
	   // fgetc(pFich);
	   // fgetc(pFich);
            tab[nb] = adherent;
	    nb++;
	}
    }
    fclose(pFich);
    printf("nb enregistrements : %d\n", nb);
    return nb;
}
