/******************************************************************************
    TP 2 - Jeu de pendu
           Corrigé
    Compilation : gcc pendu.c biblio_Pendu.c -o pendu -Wall
    Exécution   : ./pendu
*******************************************************************************/
#include "biblio_Pendu.h"

int main(int argc, char *argv[])
{
	char *listeMots[NBMOTS]={"bonjour", "maison", "noyau", "temps", "blond", "clown", "kayak"};
	int cptErreur=0;
	char *motATrouver;
	char *motCourant;
	int choix;
	char lettre;
	char histo[NB_MAX_LETTRES_POSSIBLE];
	int cptProposition=0;
	int pasTrouve,perdu;

	do{
		choix=afficherMenu();

		// l'utilisateur veut jouer
		if (choix>0){
                    effacerEcran();
                    perdu=0;

		    // init des compteurs
		    cptErreur=0;
		    cptProposition=0;

		    // tirage aléatoire d'un mot
		    motATrouver=listeMots[aleatoire(NBMOTS-1)];

		    /* réservation de mémoire pour le motCourant */
		    motCourant=(char *)malloc( strlen(motATrouver)+1);
		    initialiserMot( motCourant,strlen(motATrouver));

		   // boucle de jeu
		   afficherPendu(0);
		   do{
			printf("\n  %s\n\n",motCourant);
			afficherLettre(histo,cptProposition);

			/* demander/redémander une lettre tant que
			// le caractère saisi n'est pas une lettre
			// ou a déja été proposé */
			    do{
				printf("donnez une lettre : ");
				scanf(" %c",&lettre);
				}while( !verifierLettrePropose(histo,cptProposition,lettre));

				// mise à jour du tableau des lettres proposées
				histo[cptProposition]=lettre;
				cptProposition++;

				// mise à jour du compteur d'erreur
				cptErreur+=placerLettre(motATrouver,motCourant,lettre);

				effacerEcran();
				afficherPendu(cptErreur);
				pasTrouve=motEstTrouve(motATrouver,motCourant);
				if(cptErreur==7)
                		{
                    		    perdu=1;  // perdu devient VRAI
                		}
			}while(pasTrouve && !perdu);
			// liberation de la mémoire du mot courant
			free(motCourant);
			// affichage des messages de fin de jeu
			//effacerEcran();
			if (pasTrouve)
			{
				printf("\n   Perdu le mot était %s\n\n",motATrouver);
			}
			else
			{
				printf("\n   Bravo !\n\n");
			}
		}	// fin boucle de jeu

	}while (choix!=-1);


  return EXIT_SUCCESS;
}
