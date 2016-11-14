#include "biblio_Pendu.h"

int main(int argc, char *argv[])
{
	char *listeMots[NBMOTS]={"bonjour","maison","noyau","temps","blond","clown","kayak"};
	int cptErreur=0;
	char *motATrouver;
	char *motCourant;
	int choix;
	char lettre;
	char histo[NB_MAX_LETTRES_POSSIBLE];
	int cptProposition=0;
	int trouve,perdu=1;
	do{
		choix=afficherMenu();

		// l'utilisateur veut jouer
		if (choix>0){
                effacerEcran();
                perdu=1;

			// init des compteurs
			cptErreur=0;
			cptProposition=0;

			// tirage aleatooire du mot
			motATrouver=listeMots[aleatoire(NBMOTS-1)];

			/* réservation de mémoire pour le motCourant */
			motCourant=(char *)malloc( strlen(motATrouver)+1);
			initialiserMot( motCourant,strlen(motATrouver));

			// boucle de jeu
			afficherPendu(0);
			do{
				printf("\n  %s\n\n",motCourant);
				afficherLettre(histo,cptProposition);

				/* demander/redemander une lettre tant que
				// le caractere saisi n'est pas une lettre
				// ou a deja ete propose */
				do{
					printf("donnez une lettre : ");
					scanf(" %c",&lettre);
					effacerEcran();
				}while(verifierLettrePropose(histo,cptProposition,lettre)==0);

				// mise a jour du tableau des lettres proposees
				histo[cptProposition]=lettre;
				cptProposition++;

				// mise a jour du compteur d'erreur
				cptErreur+=placerLettre(motATrouver,motCourant,lettre);

				afficherPendu(cptErreur);
				trouve=motEstTrouve(motATrouver,motCourant);
				if(cptErreur==7)
                {
                    perdu=0;
                }
			}while(trouve!=0 && perdu != 0);
			// liberation de la memoire du mot courant
			free(motCourant);
			// affichage des messages de fin de jeu
			if (trouve==0)
			{
			    effacerEcran();
				printf("   Bravo !\n");
			}
			else
			{
				printf("\nPerdu le mot était %s\n\n",motATrouver);
			}
		}	// fin boucle de jeu

	}while (choix!=-1);


  return EXIT_SUCCESS;
}