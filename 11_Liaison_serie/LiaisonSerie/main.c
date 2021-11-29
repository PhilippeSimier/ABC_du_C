#include <stdio.h>
#include <stdlib.h>
#include "serie.h"

int main(int argc, char** argv) {

    char message[2500];
    int nb;
    char caractere;

    int serial = ouvrirPort("/dev/ttyUSB0");
    configurerSerie(serial, 9600);

    do {


        printf("\nEntrer une  lettre : ");
        scanf(" %c", &caractere);
        envoyerCaractere(serial, caractere);

        nb = recevoirMessage(serial, message, 0x04, sizeof (message)); //le message reçu se termine par EOT
        usleep(100000);
    } while (caractere != 'z');

    fermerPort(serial);
    printf("\nfin du programme\n");


    return (EXIT_SUCCESS);
}

