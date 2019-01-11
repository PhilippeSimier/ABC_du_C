#include "adherent.h"

// Fonction pour afficher le menu
void afficheMenu(int nbAdherent){
    printf("Que voulez-vous faire ?\n");

    if(nbAdherent == 0)
    {
        printf(" A -> Ajouter une fiche adhérent\n");
        printf(" Q -> Quitter\n\n");
    }
    else
    {
        printf(" A -> Ajouter une fiche adhérent\n");
        printf(" S -> Supprimer une fiche\n");
        printf(" M -> Modifier une fiche\n");
        printf(" V -> Voir le contenu d'une fiche\n");
        printf(" L -> Voir le contenu de l'ensemble des fiches\n");
        printf(" E -> Supprimer toutes les fiches\n");
        printf(" W -> Enregistrer toutes les fiches\n");
        
        printf(" Q -> Quitter\n\n");
    }
printf("Votre choix : "); 
}


typeAdherent *creerUnAdherent(){
    typeAdherent *unAdherent;
     // réservation de la mémoire
    unAdherent = (typeAdherent *)malloc(1* sizeof(typeAdherent));
    printf("Donnez le nom : \n");
    scanf("%s", unAdherent->nom );
    printf("Donnez le prénom : \n");
    scanf("%s", unAdherent->prenom );
    printf("Donnez le n° de liçence : \n");
    scanf("%d", &unAdherent->noLicence ); 
    printf("Donnez l'activité : \n");
    printf(" Natation   : 0\n");
    printf(" Basketball : 1\n");
    printf(" Aviron     : 2\n");
    printf(" Athlétisme : 3\n");
    printf(" Tennis     : 4\n");
    scanf("%u", &unAdherent->discipline[0] );
    
    printf("Donnez le jour de naissance : \n");
    scanf("%d", &unAdherent->naissance.jour );
    printf("Donnez le mois de naissance : \n");
    scanf("%d", &unAdherent->naissance.mois ); 
    printf("Donnez l'année de naissance : \n");
    scanf("%d", &unAdherent->naissance.annee );    
    
    printf("\nVous êtes incrit.\n\n");
    
    return unAdherent;
}

void afficherAdherent(typeAdherent *unAdherent){
    if (unAdherent != NULL){
    printf("%s\t%s\t%d\t", 
            unAdherent->nom,
            unAdherent->prenom,
            unAdherent->noLicence
            );
    afficherDate(unAdherent->naissance);
    printf("\t");
    afficherActivite(unAdherent->discipline[0]);
    printf("\n");
    }
}


void continuer(){
    
    printf(" Pour continuer appuyez sur une touche\n");
    getchar();
    getchar();
}

void afficherDate(typeDate uneDate){
    printf("%d/%d/%d",uneDate.jour, uneDate.mois, uneDate.annee );
}

void afficherActivite(activite uneActivite){
    switch(uneActivite){
        case NATATION:
            printf("Natation");
            break;
        case BASKETBALL:
            printf("Basketball");
            break; 
        case ATHLETISME:
            printf("Athlétisme");
            break; 
        case AVIRON:
            printf("Aviron");
            break;
        case TENNIS:
            printf("Tennis");
            break;
        default:
            printf("Inconnu");
            
    }
}

// Question 11
void afficherAdherents(typeAdherent *tab[],int nb){
    int i;
    for (i=0; i < nb; i++){
        
        afficherAdherent(tab[i]);
    } 
}

// Question 12
int supprimerUnAdherent(typeAdherent *tab[], int nro, int nb){
    free(tab[nro]);
    tab[nro] = NULL;
    // Décaler tous les adhérents
    
    for (int i=nro ; i<nb-1 ; i++){
        tab[i] = tab[i+1];
    }
    return nb-1;
}

// Question 13
void supprimerAdherents(typeAdherent *tab[], int nb){
    for (int i=0; i< nb; i++){
        free(tab[i]);
        tab[i] = NULL; 
    }
}

// Question 3.1
int sauvegarderAdherents(typeAdherent *tab[], int nb){
 
    FILE *fp;
    char nomFichier[255];
    printf("Nom du fichier  :\n");
    scanf("%s", nomFichier);
    //Ouverture du fichier en mode écriture
    fp = fopen(nomFichier, "w");
    if(fp == NULL){
        printf("Erreur : Permission refusée\n");
        return 0;
    }
    // Ecriture dans le fichier
    // Ecriture de nb
    if( fwrite(&nb, sizeof(int), 1, fp ) != 1 ){
        printf("Erreur d'écriture dans le fichier");
    }  
    // Ecriture des fiches adherents
    for(int i=0; i<nb; i++){
        if( fwrite(tab[i], sizeof(typeAdherent), 1, fp ) != 1 ){
        printf("Erreur d'écriture dans le fichier");
    }
    }
    
    // Fermeture du fichier
    fclose(fp);
    return nb;
}

int  chargerAdherents(typeAdherent *tab[ ]){
    
    char nomFichier[125];
    int nb;
    typeAdherent *unAdherent;
    
    printf("Nom du fichier à ouvrir :\n");
    scanf("%s", nomFichier);
    
    FILE *fp;
    //Ouverture du fichier en mode lecture 
    fp = fopen(nomFichier, "r");
    if(fp == NULL){
        printf("Erreur : Permission refusée\n");
        return 0;
    }
    // lecture de nb dans le fichier  
    if( fread(&nb, sizeof(int), 1, fp ) != 1 ){
        printf("Erreur de lecture dans le fichier");
    }
    printf("nb = %d\n", nb);
    // Lecture des fiches adhérents
    for (int i=0; i < nb; i++){
        // réservation de la mémoire pour un adherent
       unAdherent = (typeAdherent *)malloc(1 * sizeof(typeAdherent));
       if( fread(unAdherent, sizeof(typeAdherent), 1, fp ) != 1 ){
           printf("Erreur de lecture dans le fichier");
           return -1;
       }
       tab[i] = unAdherent;     
    }    
    // Fermeture du fichier
    fclose(fp);
    return nb;    
}

