#include<stdio.h>
#include<stdlib.h>
#include<wiringPi.h>

int main(void)
{

   int i;
   int sortie[8]={4,17,18,22,23,24,25,27};
   char valeur;

   wiringPiSetupGpio();
   printf("Content-type: application/json\n\n");
   printf("{\"gpio\":[\n");

   for(i=0; i<8; i++){
      valeur = digitalRead(sortie[i]);
      printf("\t{\"broche\":\"%d\",\"value\":\"%d\"}",sortie[i],valeur);
      if (i<7) 
         printf(",\n"); 
      else
         printf("\n");
   }
   printf("]}\n");
}


