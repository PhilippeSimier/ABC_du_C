/*****************************************************************
*    3. Nuage de points
*
*    Compilation : gcc TP1_tableaux.c -o TP1_tableaux
*
******************************************************************/
#include <stdio.h>
#include <stdlib.h>

#define NB_ACQUIS 5

void afficherTableau(float tableau[], int tailleTableau){
    int i;
    for ( i=0; i<tailleTableau; i++){
        printf("T[%d]\t : %.2f\n",i,tableau[i]);
    }
}

void saisirTableau(float tableau[], int tailleTableau){
    int i;
    for ( i=0; i<tailleTableau; i++){
        printf("T[%d]\t : ", i);
        scanf("%f", &tableau[i]);
    }
}

// fonction pour retourner l'indice du plus grand élément
int max(float tableau[], int tailleTableau){
    int i = 0;
    int indice_max = 0;
    while(i < tailleTableau)
    {
        if(tableau[i] > tableau[indice_max])
            indice_max = i;
        i++;
    }
    return indice_max;
}

// fonction pour échanger deux éléments d'un tableau
void echanger(float tableau[], int x, int y){
    float tmp;

    tmp = tableau[x];
    tableau[x] = tableau[y];
    tableau[y] = tmp;
}

// fonction pour trier le tableau
void trierTableau(float tableau[], int taille)
{
    int id_plus_grand;

    for(; taille > 1 ; taille--) // tant qu'il reste des éléments non triés
    {
        id_plus_grand = max(tableau, taille);
        echanger(tableau, taille-1, id_plus_grand); // on échange le dernier élément avec le plus grand
    }
}

float calculerMoyenne(float tableau[], int tailleTableau){
    float somme = 0;
    float moyenne = 0;
    int i;

    for (i=1; i<tailleTableau - 1; i++){  // Calcul de la somme sans le mini et le maxi
        somme += tableau[i];
    }
    moyenne = somme/(tailleTableau - 2);
    return moyenne;
}

main(){
    float valeursBrutes[NB_ACQUIS];
    float valeursMoyennes[NB_ACQUIS - 2];
    float moyenne;

    printf("Saisir les valeurs du tableau\n");
    saisirTableau(valeursBrutes, NB_ACQUIS);

    trierTableau(valeursBrutes, NB_ACQUIS);
    printf("\nAffichage des valeurs triées\n");
    afficherTableau(valeursBrutes, NB_ACQUIS);

    moyenne = calculerMoyenne(valeursBrutes, NB_ACQUIS);
    printf("\nMoyenne : %.2f\n", moyenne);
}
