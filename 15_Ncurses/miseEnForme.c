/****************************************************************************
*   Un des avantages de Ncurses et que vous pouvez utiliser les mises en
*   formes pour mettre en valeur certaines parties de votre message.
*    Et il est tres simple de mettre tout cela en oeuvre.
*
*    gcc miseEnForme.c -lncurses -o miseEnForme
****************************************************************************/
#include <ncurses.h>

int main(void)
{
    initscr();

    attron(A_NORMAL);
    printw("Texte sans mise en forme\n");

    attron(A_STANDOUT);
    printw("Texte en meilleur surlignement\n");
    attroff(A_STANDOUT);

    attron(A_REVERSE);
    printw("Texte en inversion video\n");
    attroff(A_REVERSE);

    attron(A_DIM);
    printw("Texte a moitie brillant\n");
    attroff(A_DIM);

    attron(A_BOLD);
    printw("Texte en gras\n");
    attroff(A_BOLD);

    attron(A_UNDERLINE);
    printw("Texte en souligne\n");
    attroff(A_UNDERLINE);

    attron(A_INVIS);
    printw("Texte invisible\n");
    attroff(A_INVIS);

    attron(A_UNDERLINE | A_BOLD); // Pour appliquer plusieurs type de mises en forme, on utilise l'opC)rateur unaire |
    printw("Texte en gras souligne\n");

    attron(A_NORMAL);
    refresh();
    getch();
    endwin();

    return 0;
}
