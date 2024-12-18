/*
 * File:   main.c
 * Author: philippe Simier
 *
 * Created on 16 décembre 2024, 11:08
 *
 * Configure le terminal pour afficher correctement les caractères Unicode.
    Passe en mode ncurses.
    Affiche le texte "une flamme 🔥" à la position (1, 1) du terminal.
    Attend une interaction de l'utilisateur avant de quitter.
    Restaure le terminal à son état normal.
 *
 * compilation avec gcc flamme.c -l ncursesw -o flamme
 */

#include <ncurses.h>
#include <wchar.h>
#include <locale.h>


int main(int argc, char** argv) {

    setlocale(LC_ALL, ""); // mettre la console en compatibilité d'affichage unicode sous linux
    initscr(); // Initialise la structure WINDOW et autres paramètres 
    cbreak();  // Mise en mémoire tampon de ligne désactivée.  

    mvprintw(1, 1,"une flamme %lc", 0x1F525);  // on affiche l'element en x,y dans la boite
    mvprintw(23,0,"Tapez q pour quitter");
    
    char c;
    do{
        
        c = getch();
        
        
    }while(c !='q');
    
    endwin();   // remettre le terminal dans son état initial
    
    return (0);
}
