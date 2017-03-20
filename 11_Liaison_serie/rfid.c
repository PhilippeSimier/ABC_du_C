/***************************************************************************
*   sujet : application lecteur RFID
*
*
*   compilation : gcc rfid.c -o rfid
*
***************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <errno.h>
#include <termios.h>

int configure(int modele){
    int fd = -1;
    system("clear"); // Efface l'écran et configure la liaison série
    if (modele == 3){
     	system("stty -F /dev/ttyS0 9600 cs8 -parenb -parodd -ixon");
     	fd = open("/dev/ttyS0", O_RDWR | O_NOCTTY);
    }
    else{
     	system("stty -F /dev/ttyAMA0 9600 cs8 -parenb -parodd -ixon");
     	fd = open("/dev/ttyAMA0", O_RDWR | O_NOCTTY);
    }
    if ( fd == -1 ) {
        printf("pb ouverture: %s\n", strerror(errno));
        exit(EXIT_FAILURE);
    }

    return fd;
}

void raw_mode (int fd)
{
    struct termios term;

    tcgetattr(fd, &term);

    /* mode RAW, pas de mode canonique, pas d'echo */
    term.c_iflag = IGNBRK;
    term.c_lflag = 0;
    term.c_oflag = 0;


    /* 1 caractère suffit */
    term.c_cc[VMIN] = 1;

    /* Donnée disponible immédiatement */
    term.c_cc[VTIME] = 0;

    /* Inhibe le controle de flux XON/XOFF */
    term.c_iflag &= ~(IXON|IXOFF|IXANY);

    /* 8 bits de données, pas de parité */
    term.c_cflag &= ~(PARENB | CSIZE);
    term.c_cflag |= CS8;

    tcsetattr(fd, TCSANOW, &term);
}

void reception(int fd){
    char buffer[255];
    int nb_lus;

    memset(buffer, 0, 255);                  // efface le buffer
    do{
      	nb_lus = read(fd, buffer, 255);     // réception des caractères
      	if (nb_lus < 0) {
		printf("Erreur de réception\n");
		exit(EXIT_FAILURE);
      	}
      	write(STDOUT_FILENO, buffer, nb_lus);       // Ecriture des caractères sortie standard
    }
    while (nb_lus != 1);           // tant que pas un seul caratère
    printf("\nFin de reception\n");
}

int main(int argc, char **argv) {
    int retour, fd;
    char message[255];
    int modele = 2; // 3 pour une rasberry pi3 et 2 pour pi2

    fd = configure(modele);
    raw_mode(fd);
    reception(fd);
    close(fd);
}
