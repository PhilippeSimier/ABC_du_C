#ifndef NMEA_H
#define NMEA_H

#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include <stddef.h>


    int   decouper(char trame[], char *tableau[], int size);
    char  *substr(const char *s, unsigned int debut, unsigned int fin);
    float convertirDegreDeci(char *champ, char *indicateur);
    void  calculerCRC(char trame[], char retour[]);




#endif /* NMEA_H */

