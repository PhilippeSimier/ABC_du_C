#include <stdio.h>
#include <string.h>

#include <termios.h>
#include <unistd.h>


static struct termios configuration_initiale;
static struct termios configuration_brute;

static void initialisation_configuration_clavier();

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



int main (){
  char c;
  while(1){
    c = press();
    if (c == 'q'){
        printf("touche q appuyée bye\n");
        return 0;
	}
    if (c != 255)
       printf("\t touche %d\n",c);
    sleep(1);
  }


}

