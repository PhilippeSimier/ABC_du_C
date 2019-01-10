/* Time-stamp: <strsort.c  29 Nov 2001 09:24:06> */

/* tri par ordre alphabétique des caractères d'une chaîne */
/* Utilisation du tri par insertion */

#include <stdio.h>

// Version avec des indices 
void strsort(char s[])
{
  int i;			// Indice du caractère à insérer 
  int j;			// Indice de la position d'insertion 
  char save;			// Sauvegarde du caractère à insérer
  
  for (i = 1; s[i] != '\0'; i++) {
    // Sauvegarde du caractère
    save = s[i];
    // Recherche de la position d'insertion
    for (j = i-1; j >= 0 && s[j] > save; j--)
      s[j+1] = s[j];
    // Insertion proprement dite
    s[j+1] = save;
  }
}

// Version avec des pointeurs
void strsortp(char* s)
{
  char* t;			// Indice du caractère à insérer 
  char* r;			// Indice de la position d'insertion 
  char save;			// Sauvegarde du caractère à insérer
  
  for (t = s+1; *t != '\0'; t++) {
    // Sauvegarde du caractère
    save = *t;
    // Recherche de la position d'insertion
    for (r = t-1; r >= s && *r > save; r--)
      *(r+1) = *r;		// r[1] = r[0]
    // Insertion proprement dite
    *(r+1) = save;		// r[1] = save
  }
}

int main(int argc, char* argv[])
{
  if (argc > 1) {
    // strsort(argv[1]);
    strsortp(argv[1]);
    printf("%s\n", argv[1]);
  } else {
    printf("strsort <chaine>\n");
  }
    
  return 0;


  return 0;
}
