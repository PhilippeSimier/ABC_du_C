#ifndef NMEA_H
#define NMEA_H

#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include <stddef.h>


    int   decouper(char trame[], char *tableau[],const int size);
    char *substr(char *src, const int offset, const int length);
    
    double convertirDegreDeci(char *champ, char *indicateur);
    void  calculerCRC(const char trame[], char retour[]);




#endif /* NMEA_H */

