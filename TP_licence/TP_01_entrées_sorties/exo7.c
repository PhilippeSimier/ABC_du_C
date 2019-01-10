/* Time-stamp: <exo7.c  16 Oct 2000 19:58:30> */

/* Affichage du code ASCII d'un caract�re et de sa cat�gorie */

#include <stdio.h>

int main(void)
{
  char c;			/* Caract�re saisi */
  char tmp;			/* Saisie du Retour Chariot */

  do {
    /* Saisie du caract�re */
    printf("Entrer un caract�re : ");
    scanf("%c", &c);
    scanf("%c", &tmp);		/* Suppression du Retour Chariot du buffer */
    
    /* Affichage du code et de la cat�gorie */
    if (c != '\e') {
      printf("%c = %d", c, c);
      if ('0' <= c && c <= '9')
	printf(" : chiffre");
      else if ('A' <= c && c <= 'Z')
	printf(" : majuscule");
      else if ('a' <= c && c <= 'z')
	printf(" : minuscule");
      printf("\n");
    }
  } while (c != '\e');
  return 0;
}
