/****************************************************************************
*   sujet : application ecrivain lecteur sur la liaison série
*
*
*   compilation : gcc dialogue.c biblio_serie.c -o dialogue -Wall
*
***************************************************************************/


#include "biblio_serie.h"


int main(int argc, char **argv) {
    int  fd, i;
    char message[255];

    system("clear");
    fd = ouvrirSerie("/dev/ttyUSB0");
    configurerSerie(fd, 9600 );  // Baudrate à 9600
    flush(fd);   // nettoyage des tampons
    envoyerChaine(fd, "Bienvenue sur dialogue!\n");
    envoyerUnCaratere(fd, 03);  // envoye d'un caratère ETX
 
    for (i=0; i < 40; i++){
	recevoirChaine(fd, message, 10);
	printf("%d : %s", i, message);
	envoyerChaine(fd, "Votre message : ");
	envoyerChaine(fd, message);
    }
    close(fd);
    return 0;
}
