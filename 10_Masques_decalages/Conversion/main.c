#include <stdio.h>
#include <stdlib.h>

void affiche_binaire(unsigned char n){
     
    unsigned char masque = 0x00U;
    masque = ~masque;
    masque = masque >> 1;
    masque = ~masque;
    unsigned char compteur = 0;
    
    while (masque > 0){        
        if ( compteur % 4 == 0 && compteur != 0){
            printf(" ");
        }
        compteur++;    
        if (n & masque){
            printf("1");
        }else{
            printf("0");
        }
        masque = masque >> 1;
        
    }
    
    
}

int main(int argc, char** argv) {
    unsigned char adresseIp[4] = {192,168,1,1};
    unsigned char reseau[4]    = {255,255,255,0};
    
    for (int i=0; i < 4; i++){
        affiche_binaire(adresseIp[i]);
        if (i < 3) printf(".");
    }
    printf("\n");
    
    for (int i=0; i < 4; i++){
        affiche_binaire(reseau[i]);
        if (i < 3) printf(".");
    }
    
    return (EXIT_SUCCESS);
}

