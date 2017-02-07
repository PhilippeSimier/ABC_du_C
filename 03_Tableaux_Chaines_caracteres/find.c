/*************************************************************
*    Recherche de la position d'un mot dans une phrase
*    gcc find.c -o find -Wall
*************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LONG 255

// fonction pour rechercher un motif dans une chaine de caratères
// renvoie la position trouvée ou
// -1 si le motif n'est pas présent.

int find(char *source, char *search){
    char *pt = NULL;
    pt = strstr(source, search);
    if (pt != NULL)
    	return (pt - source);
    else
	return -1;
}

int main()
{
    char buffer[LONG];
    char mot[26];
    int position;

    printf("Saisir une phrase \n");
    fgets(buffer, sizeof(buffer), stdin);
    printf("La phrase est :%s\n", buffer);
    printf("Donner un mot\n");
    scanf("%s",mot);

    position = find(buffer, mot);
    printf("%s\n", buffer+position );
    return 0;
}
