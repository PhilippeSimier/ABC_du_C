#ifndef FONCTIONS_H_INCLUDED
#define FONCTIONS_H_INCLUDED

typedef
    struct arg_post
    {
        char *nom;
        char *valeur;
    }arg_post;

/* Cette fonction découpe la chaîne de caratères transmise
   et place chaque variable dans un tableau _post
   chaque élément du tableau contient le nom de la variable et sa valeur
   le dernier élément du tableau est un pointeur NULL
   */
int decoupe(char *s, arg_post  _post[] );

/* fonction pour créer le début et la fin de la page html */
void debut_page(char *titre, char *css);
void fin_page();

/* Cette fonction affiche le tableau des variable d'environnement */
void environnement();

/* fonction pour surligner en jaune un passage */
char *surligne(char *text);

/* fonction pour afficher un bouton retour page précédente */
void bouton_retour();

#endif // FONCTIONS_H_INCLUDED

