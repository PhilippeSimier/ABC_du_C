/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#define true 1
#define false 0

int comptage(char phrase[], char lettre){
    int x= 0;
    int i;
    for (i=0; phrase[i] != '\0'; i++){
        if (phrase[i]== lettre){
           x++; 
        }
    }
    
    return x;
}

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

int comptageVoyelle(char phrase[]){
    int x= 0;
    int i;
    for (i=0; phrase[i] != '\0'; i++){
        if (isVoyelle(phrase[i])){
           x++; 
        }
    }
    
    return x;
}

int isLettre(char lettre){
  return (lettre >= 'a' && lettre <= 'z' || lettre >='A' && lettre <= 'Z');
    
}

int comptageConsonne(char phrase[]){
    int x= 0;
    int i;
    for (i=0; phrase[i] != '\0'; i++){
        if (!isVoyelle(phrase[i]) && isLettre(phrase[i])){
           x++; 
        }
    }
    
    return x;
}

int isEspaceBlanc(char lettre){
   char espaceBlancs[3] = " \n\t";
   int i;
   int retour = false;
   
   for(i=0; i < 3; i++){
       if (lettre == espaceBlancs[i]){
           retour = true;
       }
   }
    
   return retour;
}

int comptageMots(char phrase[]){
    int x= 0;
    if (isLettre(phrase[0])){
        x++;
    }
    int i;
    for (i=0; phrase[i] != '\0'; i++){
        if (isEspaceBlanc(phrase[i]) && isLettre(phrase[i+1])){
           x++; 
        }
    }
    
    return x;
}

void Inverser(char phrase[],char phraseInverse[]){
    int longueur;
    int i;
    longueur = strlen(phrase);
    for(i=0; i<longueur; i++){
        phraseInverse[i] = phrase[longueur - i -1];
    }
    phraseInverse[i] = '\0';
}







