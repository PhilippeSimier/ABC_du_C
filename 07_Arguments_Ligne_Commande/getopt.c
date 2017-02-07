/************************************************************
*   Programme demo pour le passage d'options en ligne de	
*   commande. Ici deux options seront nécessaires -p -r		
*   les caratères sont suivits par deux points,				
*   les options s'attendent donc  à avoir un argument,		
*
*   Compilation : gcc -Wall getopt.c -o getopt 
*
*   
*   test1        : $./getopt -p 50000 -r /home/
*   test2        : $./getopt
*   test3	    : $./getopt -r /home/pi
*
*   premier test avec deux options p et r
*   deuxième test sans option
*   troisième test avec une seul option r
*************************************************************/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <unistd.h>  // pour getopt

int main(int argc, char* argv[])
{
    char *racine;
    int  port = 8888;
    int c = 0;

    // valeur par défaut pour les arguments: racine = "~" et port 8888
    racine = getenv("PWD");

    // Analyse des arguments r et p de la ligne de commande
    while ((c = getopt (argc, argv, "r:p:")) != -1)
        switch (c)
        {
            case 'r':
                racine = malloc(strlen(optarg));
                strcpy( racine ,optarg);
                break;
            case 'p':
                port   = atoi(optarg);  // conversion en entier
                break;
            default:
		printf("usage: getopt [-r chemin] [-p port] \n");
                exit(1);
        }

    printf("Serveur démarré sur le port no. %s%d%s avec répertoire racine as %s%s%s\n", "\033[92m", port, "\033[0m","\033[92m", racine, "\033[0m");
    return 0;
}
