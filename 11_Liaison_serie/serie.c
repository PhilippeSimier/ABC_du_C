#include "serie.h"

int ouvrirPort(const char *device){
    int fd = -1;
    // Ouverture du fichier
    fd = open(device, O_RDWR | O_NOCTTY);
    if ( fd == -1 ) {
        printf("pb ouverture: %s\n", strerror(errno));
        exit(EXIT_FAILURE);
    }

    /* Place un verrou exclusif.
      Un seul processus peut détenir un verrou exclusif sur un fichier
      donné à un moment donné. */
    if ( flock( fd , LOCK_EX | LOCK_NB) == 0 ) {
    	printf ("Verrouillage effectué  \n");
        return fd;
    }
    else{
        printf("Pb verrou: %s\n", strerror(errno));
        exit(EXIT_FAILURE);
    }
}


/* Dans la norme POSIX, tous les paramètres d'une liaison sont regroupés
   dans une structure appelée termios et définie dans le fichier <termios.h>
   qu'il nous faut donc inclure. */

void configurerSerie (const int fd, const int baud,  typeEcho echo ){

    struct termios term;

    // La fonction tcgetattr permet d'obtenir les paramètres actuels d'une liaison.
    tcgetattr(fd, &term);

    /* c_iflag : les modes d'entrée
       Ils définissent un traitement à appliquer sur les caractères en provenance
       de la liaison série */
    term.c_iflag = IGNBRK | IGNPAR; // IGNBRK les signaux BREAK (ctrl Z) sont ignorés.
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
    term.c_oflag = 0x00;  // Pas de mode particulier

    /* c_cc : control characters
       VMIN : en mode non-canonique, spécifie le nombre de caractéres
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
    term.c_cflag &= ~(PARENB | CSIZE);  // pas de parité
    term.c_cflag |= CS8;   // 8 bits par caractère
    term.c_cflag |= CREAD; //ignore les signaux de contrôle modem

    /* vitesse de la transmission
       Vitesse de communication (version simple, utilisant les
       constantes  prédéfinies ) */

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

    if(cfsetispeed(&term, myBaud) < 0 || cfsetospeed(&term, myBaud) < 0) {
       printf("Erreur configuration\n");
    }

    /* Une fois que Les champs ont été modifiés,
       il faut enregistrer Les modifications au moyen
       de la fonction tcsetattr */
    tcsetattr(fd, TCSANOW, &term);
}



int recevoirMessage(const int fd, char *message, const char fin ){
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

/* fonction pour lire toutes les données restantes du périphérique
   elle les renvoie sous forme de tableau d'octets.
*/

char* lireTout(const int fd){
    char *message;
    int nb = octetDisponible(fd);

    message = (char*)malloc(nb+1 * sizeof(char));
    if (message == NULL) // Si l'allocation a échoué
    {
        exit(0); // On arrête immédiatement le programme
    }

    int erreur = read(fd,message,nb);
    if (erreur == -1){
           printf("pb lireTout : %s\n", strerror(errno));
           nb = -1;
    }
    message[nb] = '\0';
    return message;
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

/* Fonction pour éliminer tous les caractères reçus par le noyau
   mais non encore lus par read(), */
void viderBuffer (const int fd){
  tcflush (fd, TCIOFLUSH) ;
}

/* Fonction pour fermer le port série*/
void fermerPort(const int fd){

    // Supprime le verrou  détenu par ce processus.
    if ( flock (fd , LOCK_UN) == - 1 ) {
         exit(EXIT_FAILURE);
    }
    close(fd);
}

/* Fonction pour obtenir le nombre d’octets
   immédiatement disponibles pour la lecture. */
int octetDisponible(const int fd){
  int result ;

  if (ioctl (fd, FIONREAD, &result) == -1)
    result = -1 ;

  return result ;
}


/* Fonction pour obtenir la vitesse
   de transmission */
char *obtenirVitesse(const int fd) {
    static char   SPEED[20];
    speed_t speed;
    struct termios term;

    if (tcgetattr(fd, &term) != 0)
        perror("tcgetattr() error");
    else {
        speed = cfgetispeed(&term);

    switch (speed) {
       	case B0:       strcpy(SPEED, "0");         break;
    	case B50:      strcpy(SPEED, "50");        break;
    	case B75:      strcpy(SPEED, "75");        break;
    	case B110:     strcpy(SPEED, "110");       break;
    	case B134:     strcpy(SPEED, "134");       break;
    	case B150:     strcpy(SPEED, "150");       break;
    	case B200:     strcpy(SPEED, "200");       break;
    	case B300:     strcpy(SPEED, "300");       break;
    	case B600:     strcpy(SPEED, "600");       break;
    	case B1200:    strcpy(SPEED, "1200");      break;
    	case B1800:    strcpy(SPEED, "1800");      break;
    	case B2400:    strcpy(SPEED, "2400");      break;
    	case B4800:    strcpy(SPEED, "4800");      break;
    	case B9600:    strcpy(SPEED, "9600");      break;
    	case B19200:   strcpy(SPEED, "19200");     break;
    	case B38400:   strcpy(SPEED, "38400");     break;
    	case B57600:   strcpy(SPEED, "57600");     break ;
    	case B115200:  strcpy(SPEED, "115200");    break ;
    	case B230400:  strcpy(SPEED, "230400");    break ;

    	default:       sprintf(SPEED, "unknown (%d)", (int) speed);
        }
    }
    return SPEED;
}

/* Fonction pour obtenir le niveau
   de DTR broche 4 */
int obtenirDTR(const int fd) {

    int dtr, serial;
    ioctl(fd, TIOCMGET, &serial);  // Obtenir le statut des bits du modem.
    if (serial & TIOCM_DTR)
        dtr = 1;
    else
        dtr = 0;
    return dtr;
}

/* Fonction pour définir le niveau de DTR
   Data terminal ready broche 4         */
void fixerDTR(const int fd, typeBool level) {

    int command = TIOCM_DTR;

    if (level){
        if( -1 == ioctl(fd, TIOCMBIS, &command)){
            printf("fixerDTR failed on a call ioctl");
        }
    }
    else{
        if( -1 == ioctl(fd, TIOCMBIC, &command)){
            printf("fixerDTR failed on a call ioctl");
        }
    }
}

void envoyerPrintf (const int fd, const char *message, ...)
{
  va_list argp ;
  char buffer [1024] ;
  int nb;
  va_start (argp, message) ;
    vsnprintf (buffer, 1023, message, argp) ;
  va_end (argp) ;

  nb = envoyerMessage (fd, buffer) ;
}
