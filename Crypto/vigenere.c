/*******************************************************************************
*    Sujet ce programme crypte ou décrypte le contenu d'un fichier à l'aide
*    d'une clée.
*
*    Compilation : gcc vigenere.c -o vigenere -Wall
*
*    Execution  pour crypter :
*                  ./vigenere test.txt petit-secret-bien-garde C
*    Execution pour décrypter :
*                  ./vigenere test.txt petit-secret-bien-garde D
********************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>

void crypte(char *buffer, const char *clef, int size, char opt){
    int i;
    int lg;  // longueur de la clé

    lg = strlen(clef);
    printf("clef : %s longueur : %d\n", clef, lg);
    printf(" opt : %c\n", opt);
    for ( i = 0; i< size; i++){
        if (opt != 'D'){
	    buffer[i] = buffer[i] + (clef[i%lg]-65);
	}
	else{
	    buffer[i] = buffer[i] - (clef[i%lg]-65);
  	}
    }
}

int main(int argc, const char** argv)
{
    int src,dst;          /* identificateurs de fichiers */
    char buf[4096];       /* buffer de copie*/
    int size;

    if (argc!=4) {
    	printf("%s: src clef C|D\n", argv[0]);
    	exit(1);
    }

    /* ouverture de src */
    src= open( argv[1], O_RDONLY, 0);
    if (src<0) {
        fprintf(stderr,"echec d'ouverture de %s (%s)\n", argv[1], strerror(errno));
        exit(1);
    }

    dst= open("tmp", O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (dst<0) {
        fprintf(stderr,"echec d'ouverture de %s (%s)\n", argv[2], strerror(errno));
        exit(1);
    }

    while ((size = read( src, buf, sizeof(buf))) > 0) {
    	crypte(buf, argv[2], size, argv[3][0]);
  	write(dst, buf, size);
    }

    /* fermeture */
    close(src);
    close(dst);

    src= open("tmp", O_RDONLY, 0);
    if (src<0) {
        fprintf(stderr,"echec d'ouverture de %s (%s)\n", argv[1], strerror(errno));
        exit(1);
    }

    dst= open(argv[1], O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (dst<0) {
        fprintf(stderr,"echec d'ouverture de %s (%s)\n", argv[2], strerror(errno));
        exit(1);
    }

    while ((size = read( src, buf, sizeof(buf))) > 0) {
        write(dst, buf, size);
    }

    /* fermeture */
    close(src);
    close(dst);

    printf("Success ... cryptage terminé\n");
  return 0;
}
