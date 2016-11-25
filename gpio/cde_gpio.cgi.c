/***************************************************************
*   Subject TP9: commande du GPIO avec redirection vers        *
*                le formulaire HTML  /gpio/gpio.html           *
*   Auteur     : Simier Philippe		               *
*   Date       : Mars 2016				       *
*							       *
*   Compilation:					       *
*   gcc cde_gpio.cgi.c fonctions.c -l wiringPi -o cde_gpio.cgi *
***************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <wiringPi.h>
#include <string.h>
#include "fonctions.h"

int main(void)
{
   char *lenstr;
   char *ch_formulaire;
   int len;
   arg_post POST[25];
   int nb,i,erreur;
   int sortie[8]={17,4,25,24,23,22,27,18};


   wiringPiSetupGpio();

   for (i=0; i<8 ; i++){
   pinMode(sortie[i], OUTPUT);
   }

   lenstr = getenv("CONTENT_LENGTH");
   if (lenstr == NULL || sscanf(lenstr,"%d",&len)!=1) {
	printf("Content-type: text/plain\n\n");
	printf("Erreur de traitement du formulaire");
	}
   else {
      ch_formulaire = (char *)malloc(sizeof(char)*len + 1);
      fgets(ch_formulaire, len+1, stdin);

      nb = decoupe(ch_formulaire, POST);

      if (strcmp(POST[2].valeur, "26be03aa2ed42b318c1e3311df9712f3") == 0){

          erreur = sscanf(POST[0].nom,"GPIO%d",&nb);
          erreur = sscanf(POST[0].valeur,"%d",&i);
          digitalWrite(nb ,i);
          printf("Content-type: text/html; charset=utf-8\n");
          printf("Location: /gpio/gpio.html\n\n");
      }
      else {
          printf("Content-type: text/plain\n\n");
          printf("Access denied");
      }

   }

   return 0;
}


