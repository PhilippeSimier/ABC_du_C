/****************************************************************************
*     Programme demonstration pour la bibliothèque externe Ncurses
*
*     installation :
*	   sudo apt-get install libncurses5-dev
*     compilation :
*          gcc hello.c -lncurses -o hello
****************************************************************************/
#include <ncurses.h>

int main(void)
{
    initscr();              // Initialise la structure WINDOW et autres paramètres
    printw("Hello World");  // Écrit Hello World à l'endroit où le curseur logique est positionné
    refresh();              // Rafraîchit la fenêtre courante afin de voir le message apparaître
    getch();                // On attend que l'utilisateur appui sur une touche pour quitter
    endwin();               // Restaure les paramètres par défaut du terminal

    return 0;
}
