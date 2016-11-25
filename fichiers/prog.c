/******************************************************************
*	programme test pour étudier les descripteurs de fichiers
*   	Compilation gcc prog.c -o prog -Wall
*       execution ./prog &
*                   ps
*       	    lsof -p XXXX   (XXXX est le PID de prog)
******************************************************************/


#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>

int main(){
    void *buf = malloc(1);
    int fd_read, fd_write;

    fd_read = open ("fichier_de_test.test", O_RDONLY);
    fd_write = open ("fichier_de_test.test",  O_WRONLY | O_APPEND);
    dup2(fd_write, 1);
    printf("ceci est un message du PID : %d\n", getpid());

    read (0, buf, 1);
    return 0;

}
