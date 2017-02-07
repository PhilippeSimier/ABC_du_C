#include "biblio_q9.h"

void testErreur(){
    if(errno != 0){
        printf("Erreur fichier : erreur n'%d\n", errno);
        exit(0);
    }
}

typePersonne * lirePersonne(FILE *fp){
    int nb;
    typePersonne *id;

    id = (typePersonne *)malloc(sizeof(typePersonne));
    fscanf(fp, "%[^\n]%*c", id->nom);
    fscanf(fp, "%[^\n]%*c", id->prenom);
    nb = fscanf(fp, "%d %f %c%*c", &id->age, &id->poids, &id->sexe);
    if (nb == 3) {
    	return id;
    }
    else{
	return NULL;
        free(id);
    }
}

void afficherPersonne(typePersonne *id){
    printf(" Nom : %s\n",  id->nom);
    printf(" Nom : %s\n",  id->prenom);
    printf(" Age : %d\n",  id->age);
    printf(" Poids : %.2f\n", id->poids);
    if (id->sexe == 'm') printf(" Sexe : Masculin\n");
    if (id->sexe == 'f') printf(" Sexe : Féminin\n");
}
