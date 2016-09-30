/***************************************************
*  10. Écrivez un programme demandant		   *
*  une chaine de caractères à l'utilisateur        *
*  et qui affiche cette dernière.                  *
*  UTILISEZ TOUJOURS fgets() A LA PLACE DE gets(). *
*						   *
****************************************************/

#include <stdio.h>
#include <stdlib.h>
#define LONG 20

int main()
{

    char buffer[LONG];
    printf("Saisir une phrase \n");
    fgets(buffer, sizeof(buffer), stdin);
    printf("%s\n", buffer);

}
