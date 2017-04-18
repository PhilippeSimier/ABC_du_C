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

int ouvrirSerie(const char *device){
    int fd = -1;

    fd = open(device, O_RDWR | O_NOCTTY);

    if ( fd == -1 ) {
        printf("pb ouverture: %s\n", strerror(errno));
        exit(EXIT_FAILURE);
    }
    return fd;
}

void configurerSerie (int fd, const int baud)
{
    struct termios term;
    speed_t myBaud;

    switch (baud){
    	case     50:        myBaud =     B50 ; break ;
    	case     75:        myBaud =     B75 ; break ;
    	case    110:        myBaud =    B110 ; break ;
    	case    134:        myBaud =    B134 ; break ;
    	case    150:        myBaud =    B150 ; break ;
    	case    200:        myBaud =    B200 ; break ;
    	case    300:        myBaud =    B300 ; break ;
    	case    600:        myBaud =    B600 ; break ;
    	case   1200:        myBaud =   B1200 ; break ;
    	case   1800:        myBaud =   B1800 ; break ;
    	case   2400:        myBaud =   B2400 ; break ;
    	case   4800:        myBaud =   B4800 ; break ;
    	case   9600:        myBaud =   B9600 ; break ;
    	case  19200:        myBaud =  B19200 ; break ;
    	case  38400:        myBaud =  B38400 ; break ;
    	case  57600:        myBaud =  B57600 ; break ;
    	case 115200:        myBaud = B115200 ; break ;
    	case 230400:        myBaud = B230400 ; break ;

    	default:
      	    myBaud =   B9600;
    }

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
    /* vitesse de la transmission */
    term.c_cflag |= myBaud;
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

    system("clear");
    fd = ouvrirSerie("/dev/ttyUSB0");
    configurerSerie(fd, 9600);
    for (i=0; i < 40; i++){
	printf("%d :\n", i); 
	reception(fd);
    }
    close(fd);
}
