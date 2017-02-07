#include <stdio.h>
#include <stdlib.h>

int main()
{
    unsigned char IP[4]={0};
    unsigned char Masque[4]={0};
    unsigned char adresseR[4];
    unsigned char adresseD[4];

    printf(" Adressage IPv4 \n");
    printf("Entrer une adresse IPv4         : ");
    scanf("%d.%d.%d.%d", &IP[0], &IP[1], &IP[2], &IP[3] );


    printf("Entrer le masque de sous réseau : ");
    scanf("%d.%d.%d.%d", &Masque[0], &Masque[1], &Masque[2], &Masque[3] );

    /** adresse Réseau  **/
    for (int i=0; i<4; i++){
        adresseR[i]= IP[i] & Masque[i];
    }

    printf("\n Adresse résau        : %u.%u.%u.%u", adresseR[0], adresseR[1], adresseR[2], adresseR[3]);
    printf("\n Première adresse     : %u.%u.%u.%u", adresseR[0], adresseR[1], adresseR[2], adresseR[3]+1);
    /** adresse de diffusion tous les bits à 0 de la partie host sont à 1**/

    for (int i=0; i<4; i++){
        Masque[i]=  adresseR[i] | (~Masque[i]);
    }
    printf("\n Dernière adresse     : %u.%u.%u.%u", Masque[0], Masque[1], Masque[2], Masque[3]-1);
    printf("\n Adresse de diffusion : %u.%u.%u.%u\n", Masque[0], Masque[1], Masque[2], Masque[3]);

    return 0;
}
