#include <stdio.h>
#include <stdlib.h>
#include "serie.h"

int main(int argc, char** argv) {

    int fdSerie;
    char message[1000];
    int nb = 0;
    int vitesse = 115200;

    fdSerie = OuvrirPort("/dev/ttyS0");
    configurerSerie(fdSerie, vitesse, ECHO);
    viderBuffer(fdSerie);
    printf("la liaison série ttyS0 est configurée à %d 8N1\n", vitesse);

    // reception de message avec echo des caractères reçus
    do{
        nb = recevoirMessage(fdSerie, message,'\r' );
        printf("%d caractères reçus : %s\n", nb, message);
        envoyerMessage(fdSerie, "\r\nVotre message :");
        envoyerMessage(fdSerie, message);
        envoyerMessage(fdSerie,"\n");
    }
    while(strncmp(message, "bye", 3));
    // tant que le message reçu est différent de bye

    fermerPort(fdSerie);
    printf("la liaison série ttyS0 est fermée\n");
    return (EXIT_SUCCESS);
}

