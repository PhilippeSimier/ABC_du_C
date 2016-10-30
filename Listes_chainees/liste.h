#ifndef LISTES_H_INCLUDED
#define LISTES_H_INCLUDED

typedef struct Cellule
{
    float donnee;
    struct Cellule *next;  // pointeur sur la valeure suivante
}Cellule;

void init(Cellule **L);

void push(Cellule **oldL, float donnee);

int pull(Cellule **L, float *donnee);

void tail(Cellule **L, float donnee);

void afficher (Cellule *L);

int len(Cellule *L);

void detruire(Cellule **L);

float somme(Cellule *L);

#endif // LISTES_H_INCLUDED
