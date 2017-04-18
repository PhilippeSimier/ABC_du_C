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
#include <sys/ioctl.h>

int configure(int modele){
    int fd = -1;
    system("clear"); // Efface l'écran et configure la liaison série
    if (modele == 3){
     	fd = open("/dev/ttyUSB0", O_RDWR | O_NOCTTY);
    }
    else{
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
    /* 9600 bauds */
    term.c_cflag |= B9600;
    tcsetattr(fd, TCSANOW, &term);

    // play with DTR
	int iFlags;

   // turn off DTR
    iFlags = TIOCM_DTR;
    ioctl(fd, TIOCMBIC, &iFlags);
}


void reception(int fd){
    char buffer[255];
    int nb_lus;

    memset(buffer, 0, 255);                  // efface le buffer
    do{
      	nb_lus = read(fd, buffer, 1);     // réception d'un caractère
      	if (nb_lus < 0) {
		printf("Erreur de réception\n");
		exit(EXIT_FAILURE);
      	}
      	write(STDOUT_FILENO, buffer, nb_lus);       // Ecriture des caractères sortie standard
    }
    while (buffer[0] != 10);           // tant que pas un  caratère LF (code 10)
}

int main(int argc, char **argv) {
    int retour, fd, i;
    char message[255];
    int modele = 3; // 3 pour une rasberry pi3 et 2 pour pi2

    fd = configure(modele);
    raw_mode(fd);
    for (i=0; i < 40; i++){
	printf("%d :\n", i); 
	reception(fd);
    }
    close(fd);
}
