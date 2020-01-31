/*
 * File:   serie.h
 * Author: psimier
 *
 * Created on 10 décembre 2018, 08:57
 */

#ifndef SERIE_H
#define SERIE_H

typedef enum {NOECHO,ECHO}typeEcho;
typedef enum {FALSE, TRUE}typeBool;


#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>  //read write open
#include <string.h>  // strlen
#include <fcntl.h>
#include <errno.h>   // erreur syteme
#include <termios.h>   // structure pour configuration serie
#include <sys/ioctl.h>   // fonctions pour accéder au driver
#include <sys/file.h>    // flock (fonction pour vérouiller l'accès)
#include <stdarg.h>      // macro va_start & va_end


int  ouvrirPort       (const char *device);
void configurerSerie  (const int fd, const int baud,  typeEcho echo  );
int  recevoirMessage  (const int fd, char *message, const char fin );
char* lireTout        (const int fd);
void envoyerCaractere (const int fd, const unsigned char c);
int  envoyerMessage   (const int fd, const char *s);
void envoyerPrintf    (const int fd, const char *message, ...);
void viderBuffer      (const int fd);
void fermerPort       (const int fd);

int  octetDisponible  (const int fd);
char *obtenirVitesse  (const int fd);
int  obtenirDTR       (const int fd);
void fixerDTR         (const int fd, typeBool level);


#endif /* SERIE_H */
