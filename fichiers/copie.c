/********************************************************************************
*    Correction du Tp copie de fichiers
*    Sujet :  Écrivez un programme C qui copie un fichier grâce aux fonctions
*             bas-niveau read(2) et write(2). Le programme prendra deux
*             arguments sur sa ligne de commande: le nom d'un fichier source
*             existant et un nom du fichier destination.
*             On prendra en particulier soin à:
*             copier par morceaux ni trop gros (pour ne pas saturer la mémoire)
*             ni trop petits (pour minimiser le nombre d'appels systèmes):
*             64 Ko semble un bon compromis,
*             gérer les erreurs fatales (fichier introuvable,
*             erreur disque, etc.) qu'il faut rapporter à l'utilisateur
*             (errno(3), strerror(3)),
*    Compilation : gcc copie.c -o copie -Wall
*    Execution   : ./copie copie.c toto.c
********************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>


int main(int argc, const char** argv)
{
    int src,dst;          /* identificateurs de fichiers */
    char buf[4096];       /* buffer de copie*/
    int size;

    if (argc!=3) {
    	printf("%s: src dst\n", argv[0]);
    	exit(1);
    }

    /* ouverture de src */
    src= open( argv[1], O_RDONLY, 0);
    if (src<0) {
        fprintf(stderr,"echec d'ouverture de %s (%s)\n", argv[1], strerror(errno));
        exit(1);
    }
    /* création de dst */
    /* O_TRUNC indique qu'un fichier existant sera écrasé */
    /* échoue si
       - argv[2] est un nom de répertoire existant
       - le chemin de argv[2] contient un nom de répertoire inexistant
       - l'utilisateur n'a pas les droits pour créer / écraser argv[2]
    */
    dst= open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (dst<0) {
        fprintf(stderr,"echec d'ouverture de %s (%s)\n", argv[2], strerror(errno));
        exit(1);
    }

    /* boucle de copie */
    while ((size = read( src, buf, sizeof(buf))) > 0) {
    	write(dst, buf, size);
    }

    /* fermeture */
    close(src);
    close(dst);

  return 0;
}

