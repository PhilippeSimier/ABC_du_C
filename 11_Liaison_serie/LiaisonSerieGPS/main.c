#include <stdio.h>
#include <stdlib.h>

#include <string.h>
#include "serie.h"
#include "nmea.h"

int main(int argc, char** argv) {

    char trame[1500];
    int nb;
    char *champ[20];
    char crc[4];

    int serial = ouvrirPort("/dev/ttyUSB0");
    configurerSerie(serial, 4800);
    // Envoyer le caratère n pour obtenir des trames GPS simulées
    envoyerCaractere(serial, 'n');
    
    do {
        nb = recevoirMessage(serial, trame, '\n', sizeof (trame)); //les trames reçues se terminent par LF     
        calculerCRC(trame, crc);
        
        nb = decouper(trame, champ, 20);
        
        // si la trame commence par $GPGGA et possède 15 champs et crc calculé == crc reçu
        if (!strcmp(champ[0],"$GPGGA") && nb == 15 && !strncmp(crc, champ[14], 3)) {
            system("clear");
            
            printf("Trame         : %s\n", champ[0]);
            printf("Nb de champs  : %d\n", nb);
            printf("CRC calculé   : %s\n", crc);
            printf("Heure UTC     : ");
            afficherHeure(champ[1]);  // Affichage du temps UTC
	    printf("Latitude DM   : %s %s \n", champ[2], champ[3]);
            printf("Latitude D    : %f °\n", convertirDegreDeci(champ[2], champ[3]));
	    printf("Longitude DM  : %s %s \n", champ[4], champ[5]);
            printf("Longitude D   : %f °\n", convertirDegreDeci(champ[4], champ[5]));
	    printf("Nb satellites : %s\n", champ[7]);
            printf("Altitude      : %s %s\n", champ[9],champ[10]);
            
        }
        
        
        

	
        
        
        
    } while (1);

    fermerPort(serial);
    printf("\nfin du programme\n");


    return (EXIT_SUCCESS);
}

