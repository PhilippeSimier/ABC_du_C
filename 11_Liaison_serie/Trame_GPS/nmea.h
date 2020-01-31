#ifndef NMEA
#define NMEA

#include <ctype.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#define LONG 255
#define MAX  20

int decouper(char phrase[], char *tableau[]);

#endif /* NMEA */
