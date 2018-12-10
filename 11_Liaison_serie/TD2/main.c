#include <stdio.h>
#include <stdlib.h>
#include "serie.h"

int main(int argc, char** argv) {
   
    int fdSerie;
    char message[1000];
    int nb = 0;
    
    fdSerie = OuvrirPort("/dev/ttyS0");
    configurerSerie(fdSerie,9600);
    viderBuffer(fdSerie);
    printf("la liaison série ttyS0 est configurée à 9600 8N1\n");
    
    // reception de message avec echo des caractères reçus
    do{
        nb = recevoirMessage(fdSerie, message,'\r', ECHO); 
        printf("%d caractères reçus : %s\n", nb, message); 
        envoyerMessage(fdSerie, "\r\nBien recu\r\n");
    }
    while(strncmp(message, "bye", 3)); 
    // tant que le message reçu est différent de bye
    
    return (EXIT_SUCCESS);
}

