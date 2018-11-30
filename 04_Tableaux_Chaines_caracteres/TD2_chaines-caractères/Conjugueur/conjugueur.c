#include "conjugueur.h"

void MettreEnMinuscule(char s[]){
    int i;
    for (i=0; s[i]!='\0'; i++){
        if(s[i] >= 'A' && s[i] <= 'Z'){
            s[i] +=32;
        }
   } 
}

logique deroger(char initial){
    char lettre[12]="aeiouhAEIOUH";
    logique retour = NON;
    for (int i=0; i<12; i++){
        if (initial == lettre[i]){
            retour = OUI;
        }
    }
    return retour;
    
}

void conjuguerAuPresent(char verbe[]){
   // Tableau des pronoms
   char *pronom[6] = { "je\t\t", "tu\t\t", "il/elle\t\t", 
                       "nous\t\t" , "vous\t\t", "ils/elles\t"};
   
   // terminaisons pour les verbes du premier groupe cas général
   char *terminaison0[6] = { "e" , "es" ,"e", "ons" , "ez", "ent"};
   // terminaisons pour les verbes en eter cas général (jeter) 
   char *terminaison1[6] = { "te" , "tes" , "te" , "ons" , "ez" , "tent"};
   // terminaisons pour les verbes en eler cas général  (appeler)
   char *terminaison2[6] = { "le" , "les" , "le" , "ons" , "ez" , "lent"};
   // terminaisons pour les verbes eler exceptions (geler)
   char *terminaison3[6] = { "èle" , "èles" , "èle" , "elons" , "elez" , "èlent"}; 
   // Terminaisons pour les verbe en eter exceptions (acheter)
   char *terminaison4[6] = { "ète" , "ètes" , "ète" , "etons" , "etez" , "ètent"};
   char **terminaison;
   char radical[255];
   int type, i;
   
   
   type = obtenirRadical(radical , verbe);
   printf("type : %d Radical : %s\n", type, radical);
   if (radical[strlen(radical)-1] == 'g'){   //manger donne mangeons
       terminaison0[3] = "eons";
   }
   if (deroger(radical[0])){   // verbe commençant par a e i o u h aimer hypnotiser 
       pronom[0] = "j'\t\t";
   }
   // Sélection du tableau de terminaison en fonction du type
   switch(type){
       case 0: 
            terminaison = terminaison0;
            break;
       case 1:
            terminaison = terminaison1;
            break;
       case 2:
            terminaison = terminaison2;
            break;
       case 3:
            terminaison = terminaison3;
            break;
       case 4:
            terminaison = terminaison4;
            break;
            
   }
   for ( i=0; i<6; i++){
            printf("%s%s%s\n", pronom[i], radical, terminaison[i]);
   }
 }

logique isPremierGroupe(char verbe[]){
    logique retour = NON;
    if (verbe[strlen(verbe)-1] == 'r' 
        && verbe[strlen(verbe)-2] == 'e'
        && strncmp(verbe, "aller", 5)){
        retour = OUI;
    } 
    return retour;      
}

int obtenirRadical(char radical[], char verbe[]){
    int i, retour = 0;
    
    MettreEnMinuscule(verbe);
    
    // Cas général verbe en er
    strncpy(radical, verbe, strlen(verbe) - 2);
    retour = 0;
    
    if (verbe[strlen(verbe)-1] == 'r'   // Verbe en eter général
        && verbe[strlen(verbe)-2] == 'e'
        && verbe[strlen(verbe) -3] == 't' 
        && verbe[strlen(verbe) -4] == 'e'  ){
        strncpy(radical, verbe, strlen(verbe) - 2);
        radical[strlen(verbe) - 2] = '\0';
        retour = 1;  
    }
    
    if (verbe[strlen(verbe)-1] == 'r'   // Verbe en eler général
        && verbe[strlen(verbe)-2] == 'e'
        && verbe[strlen(verbe) -3] == 'l' 
        && verbe[strlen(verbe) -4] == 'e'  ){
        strncpy(radical, verbe, strlen(verbe) - 2);
        radical[strlen(verbe) - 2] = '\0';
        retour = 2;  
    }
    
       
    char *verbeEler[14] = { "celer", "déceler", "receler", "ciseler",
                            "démanteler", "écarteler", "encasteler", "geler",
                           "dégeler", "congeler", "surgeler", 
                            "marteler", "modeler", "peler"};
    for (i=0; i<14; i++){
        if (! strcmp(verbe,verbeEler[i])){
            strncpy(radical, verbe, strlen(verbe) - 4);
            radical[strlen(verbe) - 4] = '\0';
            retour = 3;
        }    
    }
   
    char *verbeEter[8] = { "acheter", "racheter", "bégueter", "corseter", 
                          "crocheter", "fileter", "fureter", "haleter"};
    for (i=0; i<8; i++){
        if (! strcmp(verbe,verbeEter[i])){
            strncpy(radical, verbe, strlen(verbe) - 4);
            radical[strlen(verbe) - 4] = '\0';
            retour = 4;
        }    
    }  
    
    return retour;
}

