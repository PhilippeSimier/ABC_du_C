/* Programme de test de la liaison série via un adaptateur USB série
   Vitesse de transmission 115200 bauds avec ECHO
   Ce programme renvoie le nb de caractères reçus et le message
   tant que le message reçu est différent de bye

    gcc main.c serie.c -o main

*/

#include <stdio.h>
#include <stdlib.h>
#include "serie.h"

int main(int argc, char** argv) {

    int fdSerie;
    char message[1000];
    int nb = 0;
    int vitesse = 115200;
    char device[]="/dev/ttyUSB0";

    fdSerie = ouvrirPort(device);
    configurerSerie(fdSerie, vitesse, ECHO);
    viderBuffer(fdSerie);
    printf("%s Vitesse : %s\n", device, obtenirVitesse(fdSerie));

    // reception de message avec echo des caractères reçus
    do{
        nb = recevoirMessage(fdSerie, message,'\r' );
        envoyerPrintf(fdSerie, "%d caractères reçus : %s\n", nb, message);
    }
    while(strncmp(message, "bye", 3));
    // tant que le message reçu est différent de bye

    envoyerPrintf(fdSerie, "la liaison série %s est fermée\r\n", device);
    fermerPort(fdSerie);
    printf("la liaison série %s est fermée\n", device);
    return (EXIT_SUCCESS);
}
