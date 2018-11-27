#include "crypteur.h"

void mettreMajuscule(char s[])
{
    int i;
    for(i=0; s[i] != '\0'; i++){
    	if ( s[i] >= 'a' && s[i] <= 'z'){
             s[i] = s[i] - ('a'-'A');
	}
    
    }
}


void saisirPhrase(char phrase[]){
    printf("Entrez une phrase : \n");
    
    while (getchar() != '\n')   // vidage du buffer d'entrée
        continue;
    
    fgets(phrase, LONG, stdin );
    mettreMajuscule(phrase);
}

logique isLettre(char caractere){
    logique retour = NON;
    if (caractere >= 'A' && caractere <='Z'){
       retour = OUI;
    }
    return retour;
}

void crypter(char phrase[], char cle[]){
    int i;
    char temp;
    printf("Phrase dans crypteur : %s", phrase);
    for(i=0; phrase[i]!='\0'; i++){  // pour chaque lettre
        if(isLettre(phrase[i])){
            
            phrase[i]= cle[ phrase[i] -'A' ];
        }
    }
}

void decrypter(char phrase[], char cle[]){
    for(int i=0; phrase[i]!='\0'; i++){  // pour chaque lettre
        if(phrase[i] != ' '){
            // Recherche de la position de la lettre dans le tableau cle
            int j = 0;
            while (cle[j]!='\0' && cle[j] != phrase[i] ){
                j++;
            }
            // Si la lettre est dans la clé j correspond à son rang alphabétique
            if(j < 26){
                phrase[i] = 'A' + j;
                    
            }
        }
    }
}

