// Time-stamp: <liste.c   4 Dec 2000 11:50:58> 

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Type des cellules pour les listes chaînées
struct Cellule {
  char* str;			// Pointeur sur la chaîne
  int nbr;			// Nombre d'occurrences
  Cellule *next;                // Pointeur sur la cellule suivante
};
typedef Cellule* Liste;

// Allocation d'une cellule                         
Cellule* cellAlloc(char* str)
{
  // Allocation de la cellule proprement dite
  Cellule* c = (Cellule*) malloc(sizeof(Cellule));
  if (c == 0) {
    fprintf(stderr, "Plus de mémoire\n");
    exit(1);
  }
  // Allocation de la mémoire pour stocker la chaîne
  // Il faut allouer 1 octet de plus pour le '\0' de fin de chaîne.
  c->str = (char *) malloc(strlen(str) + 1);
  if (c->str == 0) {
    fprintf(stderr, "Plus de mémoire\n");
    exit(1);
  }
  // Copie de la  chaîne dans la mémoire allouée
  strcpy(c->str, str);
  // Initialisation du nombre d'occurrences
  c->nbr = 0;

  return c;
}

// Ajout d'une cellule en tête de liste
void listeCons(Liste& l, Cellule* c)
{
  c->next = l;
  l = c;
}

// Recherche d'une chaîne dans une liste
Cellule* listeSearch(Liste l, char* str)
{
  for (; l != 0; l = l->next)
    if (strcmp(l->str, str) == 0)
      return l;
  return 0;
}

// Incrémente le nombre d'occurences d'une chaîne dans une liste
// si la chaîne n'est pas présente dans la liste, la chaîne est
// ajoutée à la liste
void incrOccur(Liste& l, char* str)
{
  Cellule* c = listeSearch(l, str);
  
  if (c == 0) {
    // On ajoute la chaîne à la liste
    c = cellAlloc(str);
    listeCons(l, c);
  }
  // Incrémentation proprement dite
  c->nbr++;
}

// Lecture d'un fichier 
void scanStream(Liste& l, FILE* filein)
{
  const int buffersize = 4096;	// Taille du buffer
  char buffer[buffersize];	// Buffer pour la ligne
  while (fgets(buffer, buffersize, filein) != 0) 
    incrOccur(l, buffer);
}

// Programme principal
int main(int argc, char* argv[])
{
  Liste l = 0;			// Liste vide

  if (argc <= 1) {
    // Pas de nom de fichier sur la ligne de commande 
    scanStream(l, stdin);
  } else {
    // Présence de noms de fichier sur la ligne de commande
    FILE* filein;
    // Parcours de chacun des noms sur la ligne de commande
    for (int i = 1; i < argc; i++) {
      if ((filein = fopen(argv[i], "r")) == 0) {
	fprintf(stderr, "Problème d'ouverture : %s\n", argv[i]);
	exit(1);
      }
      scanStream(l, filein);
      fclose(filein);
    }
  }  
  // Affichage de la liste
  for (Liste p = l; p != 0; p = p->next) 
    printf("%d : %s", p->nbr, p->str);

}
