/****************************************************************************
*   sujet : application lecteur RFID tag 125khz
*
*
*   compilation : gcc rfid.c biblio_serie.c -o rfid -Wall
*
***************************************************************************/


#include "biblio_serie.h"


int main(int argc, char **argv) {
    int  fd, i;
    char message[255];

    system("clear");
    fd = ouvrirSerie("/dev/ttyUSB0");
    configurerSerie(fd, 9600);
    for (i=0; i < 40; i++){
	reception(fd, message, 10);
	printf("%d : %s", i, message);
    }
    close(fd);
    return 0;
}
