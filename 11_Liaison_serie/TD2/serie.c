/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "serie.h"

int OuvrirPort(const char *device){
    int fd = -1;
    fd = open(device, O_RDWR | O_NOCTTY);
    if ( fd == -1 ) {
        printf("pb ouverture: %s\n", strerror(errno));
        exit(EXIT_FAILURE);
    }
    return fd;
}


void configurerSerie (int fd, const int baud){
    
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

    /* mode RAW, pas de mode canonique, pas d'écho */
    term.c_iflag = IGNBRK;
    term.c_lflag = 0;
    term.c_oflag = 0;


    /* 1 seul caractère suffit */
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



int recevoirMessage(int fd, char *message, char fin, typeEcho echo){
    int erreur = 0;
    char charactere_recu;
    int nb = 0;
    do{
       erreur = read(fd,message,1);
       
       if (erreur == -1){
           printf("pb recevoirMessage: %s\n", strerror(errno));
           nb = -1;
       }
       charactere_recu = *message;
       if (echo == ECHO){
           envoyerCaractere(fd,*message);
       }
       message++; // On passe au caractère suivant
       nb++;
    }
    while(charactere_recu != fin && erreur != -1);
    *message = '\0';   // fin de chaine de caractère
    return nb;
}

void envoyerCaractere (const int fd, const unsigned char c){
    write(fd,&c,1);
}

int envoyerMessage (const int fd, const char *s){
    int longueur = 0;
    int nb = 0;
    longueur = strlen(s);
    nb = write(fd, s, longueur );
    if ( nb == -1 ) {
        printf("pb avec write: %s\n", strerror(errno));
        exit(EXIT_FAILURE);
    }
    return nb;
}

void viderBuffer (const int fd){
  tcflush (fd, TCIOFLUSH) ;
}
