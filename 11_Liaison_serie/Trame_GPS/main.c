/* Programme de test de la liaison série GPS trame NMEA
   Vitesse de transmission 4800 bauds
   Ce programme renvoie les informations contenues dans
   la trame GGA

   gcc main.c serie.c nmea.c -o main
*/
#include <stdio.h>
#include <stdlib.h>
#include "serie.h"
#include "nmea.h"

int main(int argc, char** argv) {

    int fdSerie;
    char trame[1000];
    int nb = 0;
    int vitesse = 4800;
    char device[]="/dev/ttyUSB0";
    char *champ[20];

    fdSerie = ouvrirPort(device);
    configurerSerie(fdSerie, vitesse, ECHO);
    viderBuffer(fdSerie);
    printf("%s Vitesse : %s\n", device, obtenirVitesse(fdSerie));

    // pour chaque trame NMEA reçu
    do{
        recevoirMessage(fdSerie, trame,'\r' );
        nb = decouper(trame, champ);
        if (!strcmp(champ[0],"$GPGGA") && nb == 15){
	    system("clear");
	    printf("Trame GPGGA  \n");
            printf("Time UTC  : %s\n", champ[1]);  // Affichage du temps UTC
	    printf("Latitude  : %f °\n", convertirDegreDeci(champ[2], champ[3]));
	    printf("Longitude : %f °\n", convertirDegreDeci(champ[4], champ[5]));
	    printf("Nb satellite : %s\n", champ[7]);
            printf("Altitude     : %s %s\n", champ[9],champ[10]);

	}
    }
    while(1);
    // tant que le message reçu est différent de bye
    fermerPort(fdSerie);
    return (EXIT_SUCCESS);
}
