#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#define true 1
#define false 0
#define LONG 255

int isVoyelle(char lettre){
   char voyelles[14] = "aeiouyAEIOUY";
   int i;
   int retour = false;
   
   for(i=0; i < 14; i++){
       if (lettre == voyelles[i]){
           retour = true;
       }
   }
   return retour;
}   

int isPremierGroupe(char verbe[]){
    int longueur;
    int retour = false;
    
    longueur = strlen(verbe);
    if (verbe[longueur -1] == 'r' 
        && verbe[longueur -2] == 'e' 
        && strncmp(verbe, "aller", 5)){
        
            retour = true;
        
    }
    return retour;
}

void conjuguerPresent(char verbe[]){
   char prefix[LONG];
   
   strncpy( prefix, verbe, strlen(verbe) -2 );
   if(isVoyelle(verbe[0]))
        printf("j'\t%se\n", prefix);
   else
        printf("je\t%se\n", prefix);
   printf("tu\t%ses\n", prefix);
   printf("il/elle\t%se\n", prefix);
   
   if(verbe[strlen(verbe) -3] != 'g')
        printf("nous\t%sons\n", prefix);
   else
        printf("nous\t%seons\n", prefix);
   printf("vous\t%sez\n", prefix);
   printf("ils/elles\t%sent\n", prefix);
   
 }


