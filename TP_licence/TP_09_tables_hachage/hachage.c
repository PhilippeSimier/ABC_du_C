// Time-stamp: <hachage.c  11 Dec 2000 13:53:59> 

#include <stdlib.h>
#include <stdio.h>

// Type des cellules pour les listes chaînées
struct Cellule {
  char* str;			// Pointeur sur la chaîne
  int nbr;			// Nombre d'occurrences
  Cellule *next;                // Pointeur sur la cellule suivante
};

// Type des listes chaînées
typedef Cellule* Liste;

// Type pour les tables de hachage
struct HashTable {
  int mod;                      // Nombre d'éléments de la table
  Liste *table;			// Pointeur sur la table allouée
};

// Modulo par défaut pour les tables de hachage
const int MOD = 701;

// Fonction de hachage pour une chaîne de caractères
// Calcul d'un entier compris entre 0 et mod-1 inclus
int hash(char* str, int mod)
{ 
  int h = 0;			// Valeur calculée
  int i;			// Indice de parcours de la chaîne

  for (i = 0; str[i] != '\0'; i++) {
    h = h*256 + (unsigned int) str[i];
    if (h >= mod) 
      h %= mod;
  }
  return h;
}

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
  if ((c->str = (char *) malloc(strlen(str) + 1)) == 0) {
    fprintf(stderr, "Plus de mémoire\n");
    exit(1);
  }
  // Copie de la  chaîne dans la mémoire allouée
  strcpy(c->str, str);
  // Initialisation du nombre d'occurrences
  c->nbr = 0;

  return c;
}

// Insertion d'une cellule dans une liste
// L'insertion est faite en tête de liste
void listeInsert(Liste& l, Cellule* c)
{
  c->next = l;
  l = c;
}

// Affichage d'une liste
void listePrint(Liste l)
{
  while (l != 0) {
    printf("%d : %s", l->nbr, l->str);
    l = l->next;
  }
}

// Allocation et initialisation d'une table de hachage
void hashTableInit(HashTable& ht, int mod) 
{
  // Nombre d'éléments de la table
  ht.mod = mod;
  
  // Allocation de la table
  if ((ht.table = (Liste*) malloc(mod * sizeof(Liste))) == 0) {
    fprintf(stderr, "Plus de mémoire\n");
    exit(1);
  }    

  // Initialisation de la table
  // Au début toutes les listes sont vides
  for (int i = 0; i < mod; i++)
    ht.table[i] = 0;		// Liste vide
}

// Redimensionnement d'une table de hachage
void hashTableResize(HashTable& ht, int newmod)
{
  // Allocation de la nouvelle table
  Liste* newtable;
  if ((newtable = (Liste*) malloc(newmod * sizeof(Liste))) == 0) {
    fprintf(stderr, "Plus de mémoire\n");
    exit(1);
  }    
  
  // Parcours de toutes les cellules
  for (int i = 0; i < ht.mod; i++) {
    Liste p;			// Variable pour le parcours
    Liste next;		
    for (p = ht.table[i]; p != 0; p = next) {
      next = p->next;		// sauvegarde la cellule suivante
      // Mise en place de la cellule dans la nouvelle table
      listeInsert(newtable[hash(p->str, newmod)], p);
    }
  }

  // Libération de l'ancienne table
  free(ht.table);
  
  // Mise en place de la nouvelle table
  ht.mod = newmod;
  ht.table = newtable;
}

    
// Affichage complet d'une table de hachage
void hashTablePrint(HashTable& ht)
{
  for (int i = 0; i < ht.mod; i++)
    if (ht.table[i] != 0) {
      printf("Entrée %d\n", i);
      listePrint(ht.table[i]);
    }
}

// Recherche et insertion d'une chaîne dans une table
// Recherche une chaîne dans une table.  Si la chaîne
// est déjà présente dans la table, cette fonction
// retourne le pointeur qui la contient.  Sinon, la
// chaîne est mise dans la table et la fonction retourne
// le pointeur sur la cellule qui a été crée.  
// Dans les deux cas, la fonction retourne un pointeur
// sur la cellule qui contient la chaîne.
Cellule* hashTableFind(HashTable& ht, char* str)
{
  // Liste où doit se trouver la chaîne
  Liste& l = ht.table[hash(str, ht.mod)];

  // Parcours de la liste
  for (Liste p = l; p != 0; p = p->next)
    if (strcmp(p->str, str) == 0)
      return p;			// Bingo
  // La chaine n'a pas été trouvée.  On crée une nouvelle
  // Cellule pour l'insérer
  Cellule* c = cellAlloc(str);
  listeInsert(l, c);
  return c;
}

// Insertion d'un identificateur dans une table
void hashTableIncr(HashTable& ht, char* str)
{
  Cellule* c = hashTableFind(ht, str);
  c->nbr++;
}

// Lecture d'un fichier 
void scanStream(HashTable& ht, FILE* filein)
{
  const int buffersize = 4096;	// Taille du buffer
  char buffer[buffersize];	// Buffer pour la ligne
  while (fgets(buffer, buffersize, filein) != 0) 
    hashTableIncr(ht, buffer);
}

// Programme principal
int main(int argc, char* argv[])
{
  HashTable ht;

  // Initialisation de la table
  hashTableInit(ht, MOD);

  if (argc <= 1) {
    // Pas de nom de fichier sur la ligne de commande 
    scanStream(ht, stdin);
  } else {
    // Présence de noms de fichier sur la ligne de commande
    FILE* filein;
    // Parcours de chacun des noms sur la ligne de commande
    for (int i = 1; i < argc; i++) {
      if ((filein = fopen(argv[i], "r")) == 0) {
	fprintf(stderr, "Problème d'ouverture : %s\n", argv[i]);
	exit(1);
      }
      scanStream(ht, filein);
      fclose(filein);
    }
  }  
  // Affichage de la liste
  hashTablePrint(ht);

}
