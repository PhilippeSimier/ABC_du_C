/***********************************************************************
*  Programme pour connaître le status d'un fichier avant de l'ouvrir   *
*  la fonction stat permet d'obtenir le status d'un fichier.	       *
*								       *
*  Compilation : gcc status_fichier.c -o status_fichier -Wall	       *
*  Exécution   : ./status_fichier ..				       *
************************************************************************/

#include <sys/types.h>
#include <sys/stat.h>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    struct stat sb;
    char   heure[20];

    if (argc != 2) {
	fprintf(stderr, "Usage: %s <pathname>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    if (stat(argv[1], &sb) == -1) {
        perror("stat");
        exit(EXIT_FAILURE);
    }
    if (sb.st_mode & 0100000) printf("%s est un fichier régulier\n" , argv[1]);
    if (sb.st_mode & 0040000) printf("%s est un répertoire\n" , argv[1]);

    printf("Taille          : %lu Octets\n", sb.st_size);
    printf("Protection      : %o\n"        , sb.st_mode & 0777);
    printf("ID propriétaire : %d\n"	   , sb.st_uid);
    printf("ID groupe       : %d\n"        , sb.st_gid);
    strftime(heure, sizeof(heure), "%F %T"    , localtime(&sb.st_ctime));
    printf("Heure modif..   : %s\n"	   , heure);

    exit(EXIT_SUCCESS);
}
