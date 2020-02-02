#ifndef NMEA
#define NMEA

#include <ctype.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#define LONG 255
#define MAX  20

int decouper(char phrase[], char *tableau[]);
char *substr(const char *s, unsigned int debut, unsigned int fin);
float convertirDegreDeci(char *champ, char *indicateur);


#endif /* NMEA */
