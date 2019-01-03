/* Programme de test de la liaison série via bluetooth sur raspberry pi
   Vitesse de transmission 9600 bauds avec ECHO
   Ce programme se connecte sur rfcomm0
   et renvoie le nb de caractères reçus et le message
   tant que le message reçu est différent de bye

   gcc bluetooth.c serie.c sensehat.c -o bluetooth
*/

#include <stdio.h>
#include <stdlib.h>
#include "serie.h"
#include "sensehat.h"

int main(int argc, char** argv) {

    int fdSerie;
    char message[1000];
    int nb = 0;
    int vitesse = 9600;
    char device[]="/dev/rfcomm0";
    int x = 0;
    int y = 0;

    InitialiserLeds();

    fdSerie = OuvrirPort(device);
    configurerSerie(fdSerie, vitesse, ECHO);
    viderBuffer(fdSerie);
    printf("%s Vitesse : %s\n", device, obtenirVitesse(fdSerie));

    for (int i=0; i<10; i++){
	Allumer(x, y, VERT);
	usleep(100000);
	Allumer(x, y, NOIR);
	usleep(100000);
    }
    Allumer(x, y, VERT);
    do{
        nb = recevoirMessage(fdSerie, message,' ' );
        if (!strncmp(message, "avant", 5)){
	    Allumer(x, y++, NOIR);
            Allumer(x, y, VERT);
        }
	if (!strncmp(message, "arriere", 7)){
            Allumer(x, y--, NOIR);
            Allumer(x, y, VERT);
        }
        if (!strncmp(message, "gauche", 6)){
            Allumer(x--, y, NOIR);
            Allumer(x, y, VERT);
        }
        if (!strncmp(message, "droite", 6)){
            Allumer(x++, y, NOIR);
            Allumer(x, y, VERT);
        }
    }
    while(strncmp(message, "bye", 3));
    // tant que le message reçu est différent de bye

    fermerPort(fdSerie);
    printf("la liaison série %s est fermée\n", device);
    Allumer(x, y, NOIR);
    return (EXIT_SUCCESS);
}

