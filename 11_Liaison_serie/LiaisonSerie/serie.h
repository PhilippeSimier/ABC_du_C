#ifndef SERIE_H
#define SERIE_H

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <bits/fcntl-linux.h>
#include <errno.h>
#include <termios.h>   // structure pour configuration serie
#include <string.h> 
#include <unistd.h>

#ifdef __cplusplus
extern "C" {
#endif

    /* fonction pour ouvrir le port série
     * Renvoie un file descriptor un entier
     */
    int ouvrirPort(char *device);
    void fermerPort(const int fd);
    
    void configurerSerie  (const int fd, const int baud);
    int  recevoirMessage  (const int fd, char *message, const char fin );
    int envoyerMessage(int fd, char *message);
    void envoyerCaractere (const int fd, const unsigned char c);
    


#ifdef __cplusplus
}
#endif

#endif /* SERIE_H */

