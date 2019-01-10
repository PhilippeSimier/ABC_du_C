// Time-stamp: <liste.c   4 Dec 2000 11:50:58> 

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Type des cellules pour les listes cha�n�es
struct Cellule {
  char* str;			// Pointeur sur la cha�ne
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
    fprintf(stderr, "Plus de m�moire\n");
    exit(1);
  }
  // Allocation de la m�moire pour stocker la cha�ne
  // Il faut allouer 1 octet de plus pour le '\0' de fin de cha�ne.
  c->str = (char *) malloc(strlen(str) + 1);
  if (c->str == 0) {
    fprintf(stderr, "Plus de m�moire\n");
    exit(1);
  }
  // Copie de la  cha�ne dans la m�moire allou�e
  strcpy(c->str, str);
  // Initialisation du nombre d'occurrences
  c->nbr = 0;

  return c;
}

// Ajout d'une cellule en t�te de liste
void listeCons(Liste& l, Cellule* c)
{
  c->next = l;
  l = c;
}

// Recherche d'une cha�ne dans une liste
Cellule* listeSearch(Liste l, char* str)
{
  for (; l != 0; l = l->next)
    if (strcmp(l->str, str) == 0)
      return l;
  return 0;
}

// Incr�mente le nombre d'occurences d'une cha�ne dans une liste
// si la cha�ne n'est pas pr�sente dans la liste, la cha�ne est
// ajout�e � la liste
void incrOccur(Liste& l, char* str)
{
  Cellule* c = listeSearch(l, str);
  
  if (c == 0) {
    // On ajoute la cha�ne � la liste
    c = cellAlloc(str);
    listeCons(l, c);
  }
  // Incr�mentation proprement dite
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
    // Pr�sence de noms de fichier sur la ligne de commande
    FILE* filein;
    // Parcours de chacun des noms sur la ligne de commande
    for (int i = 1; i < argc; i++) {
      if ((filein = fopen(argv[i], "r")) == 0) {
	fprintf(stderr, "Probl�me d'ouverture : %s\n", argv[i]);
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
