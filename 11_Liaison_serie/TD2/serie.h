/* 
 * File:   serie.h
 * Author: psimier
 *
 * Created on 10 décembre 2018, 08:57
 */

#ifndef SERIE_H
#define SERIE_H

typedef enum {NOECHO,ECHO}typeEcho;

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>  //read write open
#include <string.h>  // strlen 
#include <fcntl.h>
#include <errno.h>   // erreur syteme
#include <termios.h>   // structure pour configuration serie
#include <sys/ioctl.h>   // fonctions pour accéder au driver


int  OuvrirPort(const char *device);
void configurerSerie (int fd, const int baud);
int recevoirMessage(int fd, char *message, char fin, typeEcho echo);
void envoyerCaractere (const int fd, const unsigned char c);
int  envoyerMessage (const int fd, const char *s);
void viderBuffer (const int fd);

#endif /* SERIE_H */

