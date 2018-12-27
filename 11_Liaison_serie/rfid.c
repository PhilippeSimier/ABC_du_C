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
    char message[1000];
    int nb = 0;
    int vitesse = 9600;
    char device[]="/dev/ttyUSB0";

    fdSerie = OuvrirPort(device);
    configurerSerie(fdSerie, vitesse, NOECHO);
    viderBuffer(fdSerie);
    fixerDTR(fdSerie, FALSE);

    printf("%s Vitesse : %s\n", device, obtenirVitesse(fdSerie));

    // reception de message avec echo des caractères reçus
    do{
        nb = recevoirMessage(fdSerie, message,'\n' );
        printf("%d caractères reçus : %s", nb, message);

    }
    while(1);
    // tant que vrai

    fermerPort(fdSerie);
    printf("la liaison série %s est fermée\n", device);
    return (EXIT_SUCCESS);
}

