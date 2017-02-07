#ifndef BIBLIO_H_INCLUDED
#define BIBLIO_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>


#define NBMAXCAR 50

typedef struct personne{
	char nom[NBMAXCAR];
	char prenom[NBMAXCAR];
	int age;
	float poids;
	char sexe ; // 'f' ou 'm'
}typePersonne;

void testErreur();
typePersonne * lirePersonne(FILE *fp);
void afficherPersonne(typePersonne *id);

#endif // BIBLIO_H_INCLUDED
