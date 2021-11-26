#include <stdio.h>
#include <stdlib.h>
#include "serie.h"

int main(int argc, char** argv) {

    char message[10000];
    int nb;
    char caractere, cr;

    int serial = ouvrirPort("/dev/ttyUSB0");
    configurerSerie(serial, 9600);

    do {
        printf("\nEntrer une lettre : \n");
        caractere = getchar();
        cr = getchar();
        if (caractere != '\n'){
            //printf("%c\n", caractere);
            
            envoyerCaractere(serial, caractere);
        }
        nb = recevoirMessage(serial, message, 0x04); //le message reçu se termine par EOT

    } while (caractere != 'z');

    fermerPort(serial);
    printf("\nfin du programme\n");


    return (EXIT_SUCCESS);
}

