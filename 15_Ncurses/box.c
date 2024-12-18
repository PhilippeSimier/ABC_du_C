/********************************************************************
*   creation d'une fenetre avec une bordure
*
*   compilation : gcc box.c -lncurses -o box
*********************************************************************/
#include <ncurses.h>
#include <stdlib.h>

int main(void) {
    WINDOW *boite1;
    WINDOW *boite2;
    char c;

    initscr();
    do{
        clear();
        mvprintw(LINES -1, 1,"q pour quitter");
    	boite1= subwin(stdscr, 10, 20, LINES /4 , COLS /4);
	boite2= subwin(stdscr, 5, 10, LINES /2 , COLS /2);
    	wborder(boite1, '|', '|', '-', '-', '+', '+', '+', '+');
        wborder(boite2, '|', '|', '-', '-', '+', '+', '+', '+');

    	wrefresh(boite1);
        wrefresh(boite2);
        c = getch();
        if (c == 'q')
		break;
    }
    while(1);
    endwin();

    return 0;
}
