/************************************************************************
*	Programme test pour étudier les descripteurs de fichiers
*   	Compilation gcc prog.c -o prog -Wall
*       Exécution en arrière plan ./prog &
*       Affichage des processus   ps
*       Affichage des descripteurs de fichiers XXXX est le PID de prog
*       	    lsof -p XXXX
************************************************************************/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>

int main(){
    void *buf = malloc(1);
    int fd_read, fd_write;

    // ouverture en mode lecture seul du fichier_test
    fd_read = open ("fichier_test", O_RDONLY);
    // ouverture en mode écriture seul avec ajout du fichier_test
    fd_write = open ("fichier_test",  O_WRONLY | O_APPEND);
    // redirection de la sortie standard vers fichier_test
    dup2(fd_write, 1);
    // ecriture d'un message vers la sortie redirigée
    printf("Ceci est un message du PID : %d\n", getpid());
    // attente d'un caractère sur l'entrée standard (le clavier)
    read (0, buf, 1);
    return 0;
}
