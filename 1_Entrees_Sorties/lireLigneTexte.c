/****************************************************************
* Le %*c dans le scanf indique qu'il faut lire un caractère
* (le retour à la ligne) mais ne le stocker nulle part et
* l'oublier aussitôt. Cela ne "mange" donc que le retour à la
* ligne et pas les espaces qui suivent. Ce comportement
* consistant à lire quelque chose mais à ne pas le stocker est
* du au *
*
******************************************************************/
#include <stdio.h>

int main()
{
   char ligne[100];
   scanf("%[^\n]%*c", ligne);
   printf("'%s'\n", ligne);
   scanf("%[^\n]%*c", ligne);
   printf("'%s'\n", ligne);
}
