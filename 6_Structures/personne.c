/********************************************************
*    Corrigé TD6 les structures
*    gcc personne.c biblio_personne.c -o personne -Wall
*********************************************************/

#include <stdio.h>
#include <stdlib.h>
#include "biblio_personne.h"

int main()
{
    affichePersonnePtr(creePersonnePtr());
    return 0;
}
