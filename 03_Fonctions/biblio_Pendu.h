
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <errno.h>
#include <sys/timeb.h>


#ifndef _PENDU_H_
#define _PENDU_H_


#define NB_MAX_ERREUR 7
#define NB_MAX_LETTRES_POSSIBLE 26
#define NBMOTS 8
// affiche un menu proposant de jouer ou de quitter
// recupère la réponse du joueur et retourne une valeur
// positive s'il veut jouer et négative sinon
int afficherMenu();

// affiche le pendu en fonction du nombre d'erreurs
// passée en paramètre
void afficherPendu(int nroErreur);

// Affiche les lettres déjà proposées
// qui se trouve dans le tableau de lettre "histo"
// le nombre de lettres étant donné par nbLettre
void afficherLettre(char *histo, int nbLettre);

// retourne 0 et le mot est trouvé
int motEstTrouve(char *motATtrouver, char *motPropose);

// remplace les - par la lettre proposé dans le tableau mot courant
// si la lettre fait partie du mot à trouver
// retourne 1 si aucune lettre ne correspond, et 0 sinon
int placerLettre(char *motATrouver,char *motCourant,char lettrePropose);

// retourne 0 si la lettre a déjà été proposé ou si ce n'est pas une lettre
int verifierLettrePropose(char *lettresProposees, int nbLettreProposee, char lettre);

// retourne un entier compris entre 0 et maxAlea
unsigned int aleatoire( unsigned int maxAlea );

// met des - dans chaque case du tableau motCourant
void initialiserMot(char *motCourant,int longueurMot);

void effacerEcran();

#endif
