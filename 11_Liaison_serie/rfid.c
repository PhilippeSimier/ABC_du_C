/* Programme de test de la liaison série via un adaptateur USB série
   test la réception des identifiants sur badges RFID
   Vitesse de transmission 9600 bauds sans ECHO
   Ce programme renvoie le nb de caractères reçus et le message
   tant que le message reçu est différent de bye

*/

#include <stdio.h>
#include <stdlib.h>
#include "serie.h"

int main(int argc, char** argv) {

    int fdSerie;
    char *message;
    int nb = 0;
    int vitesse = 9600;
    char device[]="/dev/ttyUSB0";

    fdSerie = ouvrirPort(device);
    configurerSerie(fdSerie, vitesse, NOECHO);
    viderBuffer(fdSerie);
    fixerDTR(fdSerie, FALSE);

    printf("%s Vitesse : %s\n", device, obtenirVitesse(fdSerie));

    // reception de message sans echo des caractères reçus
    // jusqu'au caractère code 3
    do{
        //nb = recevoirMessage(fdSerie, message,3);
        message = lireTout(fdSerie);
        printf("%s", message);
        free(message);

    }
    while(1);
    // tant que vrai

    fermerPort(fdSerie);
    printf("la liaison série %s est fermée\n", device);
    return (EXIT_SUCCESS);
}

