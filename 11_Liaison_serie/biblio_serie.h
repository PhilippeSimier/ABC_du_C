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
void reception(int fd, char *message, char fin);

#endif
