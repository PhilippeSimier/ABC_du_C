
#include "serie.h"

int OuvrirPort(const char *device){
    int fd = -1;
    fd = open(device, O_RDWR | O_NOCTTY );
    if ( fd == -1 ) {
        printf("pb ouverture: %s\n", strerror(errno));
        exit(EXIT_FAILURE);
    }
    return fd;
}


/* Dans la norme POSIX, tous les paramètres d'une liaison sont regroupés
   dans une structure appelée termios et définie dans le fichier <termios.h>
   qu'il nous faut donc inclure. */

void configurerSerie (int fd, const int baud,  typeEcho echo ){

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


    // La fonction tcgetattr permet d'obtenir les paramètres actuels d'une liaison.
    tcgetattr(fd, &term);

    /* c_iflag : les modes d'entrée
       Ils définissent un traitement à appliquer sur les caractères en provenance
       de la liaison série */
    term.c_iflag = IGNBRK; // IGNBRK les caractères BREAK sont ignorés.
    /* Inhibe le controle de flux XON/XOFF */
    term.c_iflag &= ~(IXON|IXOFF|IXANY);

    /* c_lflag : les modes locaux
       Il définit le mode (canonique ou non) et la gestion de l'écho.
       En mode canonique, les caractères reçus sont stockés dans un tampon
       et ils ne sont disponibles qu'à la réception d'un caractère eol code ASCII décimal 10.
       En mode non canaonique les caractères sont disponibles immédiatement à la lecture*/
    term.c_lflag = 0;  // 0 mode non canonique
    if(echo == ECHO){
        term.c_lflag = ECHO; //  un écho des caractères reçus est effectué.
    }
    /* c_oflag : les modes de sortie
       Ils définissent un traitement à appliquer sur les caractères envoyés sur la liaison série.*/
    term.c_oflag = 0;


    /* VMIN : en mode non-canonique, spécifie le nombre de caractéres
              que doit contenir le tampon pour être accessible à la lecture.
              En général, on fixe cette valeur à 1. */
    term.c_cc[VMIN] = 1;
    /* VTIME : en mode non-canonique, spécifie, en dixièmes de seconde,
               le temps au bout duquel un caractère devient accessible,
               même si le tampon ne contient pas c_cc[VMIN] caractères.
               Une valeur de 0 représente un temps infini. la lecture est donc bloquante*/
    term.c_cc[VTIME] = 0;

    /* c_cflag : Les modes de contrôle
       Ce champ est important, car c'est ici que l'on définit le débit,
       la parité utilisée, les bits de donnée et de stop,
       8 bits de données, pas de parité */
    term.c_cflag &= ~(PARENB | CSIZE);
    term.c_cflag |= CS8;

    /* vitesse de la transmission
       Vitesse de communication (version simple, utilisant les
       constantes  prédéfinies ) */
    if(cfsetispeed(&term, myBaud) < 0 || cfsetospeed(&term, myBaud) < 0) {
       printf("Erreur configuration\n");
    }

    /* Une fois que Les champs ont été modifiés,
       il faut enregistrer Les modifications au moyen
       de la fonction tcsetattr */
    tcsetattr(fd, TCSANOW, &term);

    // play with DTR
    int iFlags;

    // turn off DTR
    iFlags = TIOCM_DTR;
    ioctl(fd, TIOCMBIC, &iFlags);
}



int recevoirMessage(int fd, char *message, char fin ){
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

/* Pour éliminer tous les caractères reçus par le noyau
   mais non encore lus par read(), */
void viderBuffer (const int fd){
  tcflush (fd, TCIOFLUSH) ;
}

void fermerPort(const int fd){
    close(fd);
}

int octetDisponible(const int fd){
  int result ;

  if (ioctl (fd, FIONREAD, &result) == -1)
    result = -1 ;

  return result ;
}
