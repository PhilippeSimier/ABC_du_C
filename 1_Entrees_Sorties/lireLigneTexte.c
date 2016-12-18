/****************************************************************
* Le %*c dans le scanf indique qu'il faut lire un caractère
* (le retour à la ligne) mais ne le stocker nulle part et
* l'oublier aussitôt. Cela ne "mange" donc que le retour à la
* ligne et pas les espaces qui suivent. Ce comportement
* consistant à lire quelque chose mais à ne pas le stocker est
* du au *
*	 Compilation : gcc -Wall -std=c11 lireLigneTexte.c
*	test avec redirection
*       ./a.out < input > output
******************************************************************/
#include <stdio.h>

int main()
{
   int nb;
   char ligne[1000];

   scanf("%d%*c", &nb);
   for (int i = 0; i < nb; i++){
   	scanf("%[^\n]%*c", ligne);
   	printf("'%s'\n", ligne);
   }
   return 0;
}
