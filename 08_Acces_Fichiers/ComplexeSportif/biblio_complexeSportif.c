#include "biblio_complexeSportif.h"

effacerEcran(){
    system("clear");
}

continuer(){
    printf("Appuyer sur une touche pour continuer\n");
    getchar();
    getchar();
}

void afficherMenu(int nbAdherent){
    
    printf("Que voulez-vous faire ?\n\n");
    if (nbAdherent == 0){
        printf("A : Ajouter une fiche adhérent\n");
        printf("Q : Quitter\n");
    }
    else{
        printf("A : Ajouter une fiche adhérent\n");
        printf("S : Supprimer une fiche\n");
        printf("M : Modifier une fiche\n");
        printf("V : Voir le contenu d'une fiche\n");
        printf("L : Voir le contenu de l'ensemble des fiches\n");
        printf("E : Supprimer toutes les fiches\n");
        printf("F : Sauvegarder toutes les fiches\n");
        printf("Q : Quitter\n");
    }    
}

void afficherDate(date date){
    printf("%.2u/%.2u/%u", date.jour, date.mois, date.annee);
}

void afficherActivite(sport activite){
    switch (activite){
        case NATATION :
           printf("Natation");
           break;
        case BASKETBALL :
           printf("Basketball");
           break;
        case HANDBALL :
           printf("Handball");
           break;
        case SQUASH :
           printf("Squash");
           break;
        case TENNIS :
           printf("Tennis");
           break; 
        default:
            printf("Inconnue");
           
    }
    
}

void afficherUnAdherent(typeAdherent *ad){
    printf("%15s%15s\t", ad->nom, ad->prenom);
    afficherDate(ad->dateDeNaissance);
    printf("\tNb d'activités : %u ", ad->nbActivite);
    printf("\tN° carte : %u\t", ad->numCarte);
    for (int i=0; i<ad->nbActivite; i++){
        if (i != 0) printf( " - ");
        afficherActivite(ad->activite[i]);
        
    }
    
    printf("\n");
}

void voirUneFiche(typeAdherent *tab[], int nb){
    unsigned int numero;
    int trouve = 0;
    printf("Donner le numéro de la carte ?\n");
    scanf("%u", &numero);
    for(int i=0; i<nb; i++){
        if(tab[i]->numCarte == numero){
            afficherUnAdherent(tab[i]);
            trouve = 1;
        }
    }
    if (!trouve){
        printf("pas d'adherent avec une carte n° %u\n", numero);
    }
}

typeAdherent *creerUnAdherent(){
    typeAdherent * unAdherent;
    // Réservation de mémoire pour un adhérent
    unAdherent = (typeAdherent *)malloc(sizeof(typeAdherent));
    printf("Nom de l'adherent :");
    scanf("%50s", unAdherent->nom);
    printf("Prénom de l'adherent :");
    scanf("%50s", unAdherent->prenom);
    printf("Jour de naissance :");
    scanf("%d", &unAdherent->dateDeNaissance.jour);
    printf("Mois de naissance :");
    scanf("%d", &unAdherent->dateDeNaissance.mois);
    printf("Annee de naissance :");
    scanf("%d", &unAdherent->dateDeNaissance.annee);
    printf("Nb d'activites :");
    scanf("%d", &unAdherent->nbActivite);
    for (int i=0; i < unAdherent->nbActivite; i++){
        printf("Activite %d : ", i);
        scanf("%d", &unAdherent->activite[i]);
        
    }
    printf("N° Carte :");
    scanf("%u", &unAdherent->numCarte);
    
    return unAdherent;
}

// Question 11
void afficherLesAdherents(typeAdherent *tab[],int nb){
    for (int i=0; i < nb; i++){
        afficherUnAdherent(tab[i]);
    }
}

int sauvegarderAdherents(typeAdherent *tab[], int nb){
    FILE *fd;
    char nomFichier[255];
    printf("Nom du fichier ?\n");
    scanf("%s", nomFichier);
    
    // Ouverture du fichier en écriture
    fd = fopen(nomFichier, "w");
    if (fd == NULL){
        printf("Erreur d'ouverture du fichier\n");
        return -1;
    }
    // Ecriture du nombre d'adherents nb
    if (fwrite(&nb, sizeof(int), 1, fd) != 1){
        printf("Erreur d'écriture de nb");
        return -1;
    }
    // Ecriture des adhérents
    int i;
    for (i = 0; i< nb; i++){
       if (fwrite(tab[i], sizeof(typeAdherent), 1, fd) != 1){
            printf("Erreur d'écriture d'adherent");
            return -1;
        } 
    }
  
    // Fermeture du fichier
    fclose(fd);
    return i;
}

int chargerAdherents(typeAdherent *tab[]){
    
    FILE *fd;
    char nomFichier[255];
    printf("Nom du fichier ?\n");
    scanf("%s", nomFichier);
    
    // Ouverture du fichier en lecture
    fd = fopen(nomFichier, "r");
    if (fd == NULL) {
        printf("Erreur d'ouverture du fichier\n");
        return -1;
    }
    
    //lecture du nb d'adhétents
    int nb = 0;
    if(fread(&nb, sizeof(int), 1, fd) != 1){
        printf("Erreur de lecture pour nb");
        return -1;
    }
    // Lecture des adhérents
    typeAdherent *unAdherent;
    for(int i=0; i < nb; i++){
        // Reservation de la mémoire pour un adhérent
        unAdherent = (typeAdherent*)malloc(1 * sizeof(typeAdherent));
        if (fread(unAdherent, sizeof(typeAdherent), 1, fd) != 1){
            printf("Erreur de lecture pour adherent");
            return -1;
        }
        tab[i] = unAdherent;
    }
    
    // Fermeture du fichier
    fclose(fd);
    return nb;
    
}

int supprimerAdherent(typeAdherent *tab[], int nro, int nb){
    // Recherche de l'adherent dans le tableau
    for(int i=0; i < nb; i++){
        if(tab[i]->numCarte == nro){
            free(tab[i]);
            tab[i] = tab[nb-1];
            nb--;
            tab[nb] = NULL;
        }
    }
    return nb;
}

void modifierAdherent(typeAdherent *tab[], int nro, int nb){
    
}

int supprimerTousLesAdherents(typeAdherent *tab[], int nb){
    for(int i =0; i<nb; i++){
        free(tab[i]);
        tab[i] = NULL;
    }
    return 0;
}

