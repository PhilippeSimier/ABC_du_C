/**********************************************************************
*   Programme démo affichage en couleur
*
*   Compilation : gcc -Wall affichageCouleur.c -o affichageCouleur
**********************************************************************/

#include <stdio.h>
#include <stdlib.h>
#define NOIR 0
#define ROUGE 1
#define VERT 2
#define JAUNE 3
#define BLEU 4
#define MAGENTA 5
#define CYAN 6
#define BLANC 7
#define ESC x1B
#define RESET  "\033[1;0m"
// Cette fonction permet d'afficher une chaine de caratères  en couleur
// sur le terminal en utilisant ANSI escape code (\x1B)
// https://en.wikipedia.org/wiki/ANSI_escape_code#Colors

void afficher_couleur(int couleur, int couleur_f, char *chaine)
{
     printf("\033[%d;%dm%s\033[1;0m", 30+couleur, 40+couleur_f, chaine);
     printf("\n");
}

int main()
{
        afficher_couleur(VERT,ROUGE," Vert sur Fond rouge ");
	afficher_couleur(JAUNE,MAGENTA," Jaune sur fond magenta ");
	afficher_couleur(MAGENTA,NOIR," Violet sur fond noir ");
	afficher_couleur(NOIR,BLANC," Noir sur fond blanc ");
	return 0;
}
