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
#define MAX 1000
int main(int argc, char** argv) {

    int fdSerie;
    char message[MAX];
    int nb = 0;
    int vitesse = 9600;
    char device[]="/dev/rfcomm0";
    unsigned int x = 4;
    unsigned int y = 4;

    InitialiserLeds();

    fdSerie = ouvrirPort(device);
    configurerSerie(fdSerie, vitesse, NOECHO);
    viderBuffer(fdSerie);
    envoyerPrintf(fdSerie, "%s -> vitesse : %s\n", device, obtenirVitesse(fdSerie));

    // Blink d'une led sur senseHat
    for (int i=0; i<10; i++){
	Allumer(x, y, NOIR);
	usleep(100000);
	Allumer(x, y, VERT);
	usleep(100000);
    }


    do{
        nb = recevoirMessage(fdSerie, message, ' ');
        viderBuffer(fdSerie);
        if (!strncmp(message, "avant", 5)){
	    Allumer(x, y++, NOIR);
            Allumer(x, y, VERT);
            envoyerPrintf(fdSerie, "x=%d y=%d\r\n", x, y);
        }
	if (!strncmp(message, "arriere", 7)){
            Allumer(x, y--, NOIR);
            Allumer(x, y, VERT);
	    envoyerPrintf(fdSerie, "x=%d y=%d\r\n", x, y);
        }
        if (!strncmp(message, "gauche", 6)){
            Allumer(x--, y, NOIR);
            Allumer(x, y, VERT);
            envoyerPrintf(fdSerie, "x=%d y=%d\r\n", x, y);
        }
        if (!strncmp(message, "droite", 6)){
            Allumer(x++, y, NOIR);
            Allumer(x, y, VERT);
            envoyerPrintf(fdSerie, "x=%d y=%d\r\n", x, y);
        }
    }
    while(strncmp(message, "bye", 3));
    // tant que le message reçu est différent de bye

    fermerPort(fdSerie);
    printf("la liaison série %s est fermée\n", device);
    Allumer(x, y, NOIR);
    return (EXIT_SUCCESS);
}

