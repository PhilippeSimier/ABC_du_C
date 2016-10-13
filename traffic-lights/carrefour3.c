/***********************************************************
*     Subject : TP10  Implémentation d'un automate         *
*                     à états finis                        *
*                     système feux de signalisation        *
*     Version : Troisième Complète                         *
*     Auteur  : SIMIER Philippe                            *
*     Date    : 25 Mars 2016                               *
* Compilation : gcc carrefour3.c -l wiringPi -o carrefour3 *
************************************************************/
#define RED    "\033[1;31m"
#define YELLOW "\033[1;33m"
#define GREEN  "\033[1;32m"
#define RESET  "\033[1;0m"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <wiringPi.h>
#include <termios.h>

enum mode  {NORMAL,CLIGNOTANT};
enum etat  {RECOUVREMENT,VERT,ORANGE,ROUGE};
enum blink {HAUT, BAS};

static struct termios configuration_initiale;
static struct termios configuration_brute;

static void initialisation_configuration_clavier();

typedef struct {

    enum etat etat_courant; // etat courant
    char identifiant[20];   // identifiant du feux
    char debut;             // info synchro début
    char fdc;               // info fin de cycle
    int timer;              // timer
    char GPIOrouge;         // num broche GPIO lampe Rouge
    char GPIOorange;        // num broche GPIO Lampe Orange
    char GPIOvert;          // num broche GPIO lampe Verte
    int  timeRouge;	    // temps d'attente à l'état recouvrement rouge
    int  timeOrange;        // temps d'attente à l'état orange
    int  timeVert;	    // temps d'attente à l'état vert
}feux;

/* fonction pour lire le clavier à la volée */
int press()
{
  int c;
  /* on bascule en mode brut*/
  initialisation_configuration_clavier();
  tcsetattr(STDIN_FILENO, TCSANOW, &configuration_brute);

  c = getchar();
  /* retour au mode normal */
  tcsetattr(STDIN_FILENO, TCSANOW, &configuration_initiale);
  return c;
}


/* Gestion du clavier en mode brut */
static void initialisation_configuration_clavier()
{
  static char is_init=0;
  if(!is_init)
	{
	  is_init = 1;
	  tcgetattr(STDIN_FILENO, &configuration_initiale);
	  configuration_brute = configuration_initiale;

	  cfmakeraw(&configuration_brute);
	  configuration_brute.c_cc[VMIN]  = 0;
	  configuration_brute.c_cc[VTIME] = 0;
	}
}




int clignoter(feux *pfeux){
    switch(pfeux->etat_courant){
	case BAS:
	if (pfeux->timer>2){
	    pfeux->etat_courant = HAUT;
            pfeux->timer = 0;
        }
        else{
	 /* actions do */
            pfeux->timer++;
            digitalWrite(pfeux->GPIOrouge,0);
            digitalWrite(pfeux->GPIOorange,0);
            digitalWrite(pfeux->GPIOvert,0);
        }
        break;

        case HAUT:
        if (pfeux->timer>2){
            pfeux->etat_courant = BAS;
            pfeux->timer = 0;
        }
        else{
         /* actions do */
            pfeux->timer++;
            digitalWrite(pfeux->GPIOrouge,0);
            digitalWrite(pfeux->GPIOorange,1);
            digitalWrite(pfeux->GPIOvert,0);
        }
        break;
   }
   return 0;
}

int avancerEtat(feux *pfeux){

    switch(pfeux->etat_courant){
    case RECOUVREMENT:
        /* Changement d'état & exit */
        if (pfeux->debut == 1){
            pfeux->etat_courant = VERT;
            pfeux->fdc = 0;
        }
	else
	{
        /* actions do */
	    digitalWrite(pfeux->GPIOrouge,1);
            digitalWrite(pfeux->GPIOorange,0);
            digitalWrite(pfeux->GPIOvert,0);
        }
        printf(RED);
        printf("%s rouge %d \t timer : %d \n", pfeux->identifiant, pfeux->GPIOrouge, pfeux->timer);
        break;

    case VERT:
        /* Changement d'état */
        if (pfeux->timer > pfeux->timeVert){
            pfeux->etat_courant = ORANGE;
            pfeux->timer = 0;
            /* action exit */

        }
        else{
        /* action do */
            pfeux->timer++;
            digitalWrite(pfeux->GPIOrouge,0);
            digitalWrite(pfeux->GPIOorange,0);
            digitalWrite(pfeux->GPIOvert,1);
           }
        printf(GREEN);
        printf("%s vert %d \t timer : %d  \n", pfeux->identifiant, pfeux->GPIOvert, pfeux->timer);
        break;

    case ORANGE:
        /* Changement d'état */
        if (pfeux->timer > pfeux->timeOrange){
            pfeux->etat_courant = ROUGE;
            pfeux->timer = 0;
        }
        else{
        /* action do */
            pfeux->timer++;
            digitalWrite(pfeux->GPIOrouge,0);
            digitalWrite(pfeux->GPIOorange,1);
            digitalWrite(pfeux->GPIOvert,0);
        }
	printf(YELLOW);
        printf("%s orange %d \t timer : %d \n", pfeux->identifiant, pfeux->GPIOorange, pfeux->timer);
        break;

     case ROUGE:
        /* Changement d'état */
        if (pfeux->timer > pfeux->timeRouge){
            pfeux->etat_courant = RECOUVREMENT;
            /* action exit */
            pfeux->fdc = 1;
            pfeux->timer = 0;
        }
	else{
        /* action do */
            pfeux->timer++;
            digitalWrite(pfeux->GPIOrouge,1);
            digitalWrite(pfeux->GPIOorange,0);
            digitalWrite(pfeux->GPIOvert,0);
        }
        printf(RED);
        printf("%s rouge %d \t timer : %d \n", pfeux->identifiant, pfeux->GPIOrouge, pfeux->timer);
        break;
    }
    return 0;
}

void initGPIO(){
    int i;
    wiringPiSetup();
    for(i=0; i<8; i++)
    {
	pinMode(i,OUTPUT);
    }
}

void carrefour_normal(feux *pfeux1,feux *pfeux2){
	pfeux1->debut = pfeux2->fdc;
        avancerEtat(pfeux1);
        pfeux2->debut = pfeux1->fdc;
        avancerEtat(pfeux2);
}

void carrefour_clignotant(feux *pfeux1, feux *pfeux2){
        clignoter(pfeux1);
        clignoter(pfeux2);
}

int main()
{
    feux feux1 = {RECOUVREMENT, "voieA", 0, 0, 0, 1, 2, 3, 10, 10, 50};
    feux feux2 = {RECOUVREMENT, "VoieB", 0, 1, 0, 4, 5, 6, 15, 25, 70};
    enum  mode mode_courant;
    char c;

    /* Init GPIO */
    initGPIO();


    /* boucle principale */
    while(1){
        system("clear");
        c = press();

        switch(mode_courant){
		case NORMAL:
                    if (c == 'c'){
			mode_courant = CLIGNOTANT;
			feux1.etat_courant = BAS;
                        feux2.etat_courant = BAS;
			feux1.timer = 0;
			feux2.timer = 0;
			}
		    carrefour_normal(&feux1, &feux2);
		    break;
        	case CLIGNOTANT:
		     if (c == 'n'){
                        mode_courant = NORMAL;
			feux1.etat_courant = RECOUVREMENT;
			feux2.etat_courant = RECOUVREMENT;
			feux1.timer = 0;
			feux2.timer = 0;
			}
		    carrefour_clignotant(&feux1, &feux2);
                    break;
        }
        usleep(200000);
    }
    return 0;
}

