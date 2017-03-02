/***************************************************************************
*   sujet : application chat (dialoque entre deux PC à travers 
*   la liaison série
*
*   compilation : gcc chat.c -o chat
*
***************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <errno.h>

void configure(int modele){
  system("clear"); // Efface l'écran et configure la liaison série
  if (modele == 3){
     system("stty -F /dev/ttyS0 9600 cs8 -parenb -parodd -ixon");
  }
  else{
     system("stty -F /dev/ttyAMA0 9600 cs8 -parenb -parodd -ixon");
  }
}

void reception(int fd){
  char recu[255];
  int n=0;
  memset(recu, 0, 255);    // efface le buffer
  do{
      n=read(fd, recu, 1); // reception d'un caratère
      if (n==1){
        printf("%c", recu[0]);   // affichage du caratère reçu
        }
  }
  while (recu[0]!='\n');
}

void emission(int fd, char message[]){
    int n=0;
    int nb = 0;
    nb = strlen(message);
    n = write(fd, message, nb);
    if (n != nb){
        printf("erreur lors de l'émission");
    }

}





int main(int argc, char **argv) {
  int retour, fd;
  char message[255];
  int modele = 3; // pour une rasberry pi3

  configure(modele);
  if (modele == 3){
      fd = open("/dev/ttyS0", O_RDWR | O_NOCTTY);
  }
  else{
      fd = open("dev/ttyAMA0", O_RDWR | O_NOCTTY);
  }

  if ( fd == -1 ) {
    printf("pb ouverture: %s\n", strerror(errno));
    return (errno);
  }
  emission(fd, "Bienvenue sur le chat !!!\n");
  while (1){
    printf("votre message :");
    scanf("%s",message);
    emission(fd,message);
    reception(fd);
  }
  retour = close(fd);

  if ( retour == -1 ) {
    printf("pb fermeture: %s\n", strerror(errno));
    return (errno);
  }
  return 0;
}
