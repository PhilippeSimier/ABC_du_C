#include <stdio.h>
#include <stdlib.h>
#include "sensehat.h"

int main()
{
    InitialiserLeds();
    InitialiserJoystick();

    printf("Test sensehat !\n");

    Allumer(-1,0,ROUGE);
    while(ScannerJoystick()!=KEY_ENTER);
    Allumer(0,0,VERT);

    return 0;
}

