/***************************************************************************
*    correction morse
*    Compilation : gcc morse.c -o morse -Wall
***************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#define LONG 255

int main()
{
    char *morse[36]= {".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..",
                        ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.",
                        "...", "-", "..-", "...-", ".--", "-..-","-.--", "--..", "-----",
			".----", "..---", "...--", "....-", ".....", "-....", "--...", "---..", "----."};

    char buffer[LONG];
    char *s;   // pointeur pour parcourir le tableau

    printf("Saisir une phrase \n");
    fgets(buffer, sizeof(buffer), stdin);
    printf("La phrase en morse est : \n");

    for (s = buffer; *s; s++)
    {
    	if (*s >= 'A' && *s <= 'Z')
	    printf("%s  ", morse[*s - 'A']);
	else if (*s >= 'a' && *s <= 'z')
            printf("%s  ", morse[*s - 'a']);
        else if (*s >= '0' && *s <= '9')
            printf("%s  ", morse[*s - '0' +26]);
 	else printf("   ");
    }
    printf("\n");

    return 0;
}
