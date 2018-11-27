#include <stdio.h>
#include <stdlib.h>
#define LONG 255

typedef enum {NON, OUI}logique;





int main(int argc, char** argv) {
    
    char cle[27] = "@8[03{6#1}:7WZ*?O%$-V^M+/N";
    int choix = 0;
    char phrase [LONG];
    
    printf("Que voulez-vous faire ?\n");
    
    printf("1 - Crypter\n");
    printf("2 - Décrypter\n");
    printf("Votre choix : ");
    scanf("%d", &choix);
    
    switch (choix){
        case 1:
            saisirPhrase(phrase);
            crypter(phrase, cle);
            printf("%s", phrase);
            break;
        case 2:
            saisirPhrase(phrase);
            decrypter(phrase, cle);
            printf("%s", phrase);
            break;
            
        default:
            break;
    }
    
    

    return (EXIT_SUCCESS);
}

