#include<stdio.h>
#include<stdlib.h>
#include<wiringPi.h>

int main(void)
{
    int broche = 0;
    int erreur;
    char *lenstr;
    char *ch_formulaire;

      wiringPiSetupGpio();

      printf("Content-type: text/html\n\n");
      ch_formulaire = getenv("QUERY_STRING");

      erreur = sscanf(ch_formulaire,"broche=%d",&broche);

      if (digitalRead(broche)==0)
      {
          printf("<button type=\"submit\" name=\"GPIO%d\" value=\"1\" class=\"btn btn-success\">&nbspON&nbsp</button><span class=\"bg-danger\"> &nbsp&nbsp état OFF</span>",broche);

      }
      else
      {
           printf("<button type=\"submit\" name=\"GPIO%d\" value=\"0\" class=\"btn btn-danger\">OFF</button><span class=\"bg-success\"> &nbsp&nbsp état ON</span>",broche);
      }

    return 0;
}

