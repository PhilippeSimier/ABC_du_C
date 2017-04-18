#ifndef _SERIE_H_
#define _SERIE_H_

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <errno.h>
#include <termios.h>
#include <sys/ioctl.h>

int  ouvrirSerie(const char *device);
void configurerSerie (int fd, const int baud);
void recevoirChaine(int fd, char *message, char fin);
void flush (const int fd);
void envoyerUnCaratere (const int fd, const unsigned char c);
void envoyerChaine (const int fd, const char *s);

#endif
