# Les pointeurs en langage C

## 1 Introduction
La mémoire centrale d’un ordinateur est composée d’un grand nombre d’octets.  Chaque octet est repéré par un numéro appelé adresse de l’octet. Chaque variable ou objet occupe dans la mémoire des octets contigus, par exemple un float occupe 4 octets.

Un **pointeur** est une variable  qui **stocke l' adresse mémoire** d'une autre variable située dans la mémoire de l'ordinateur . Un pointeur référence une position en mémoire.  Par analogie, un numéro de page dans l'index d'un livre peut être considéré comme un pointeur sur la page correspondante.  

## 2 Obtenir l'adresse d'une variable

L'opérateur & permet d'obtenir l'adresse d'une variable.
```c
 int a = 10 ;
 &a // représente l’adresse de la variable A (5c26)
```
## 3 Déclaration d'une variable de type pointeur
La syntaxe de base pour définir un pointeur est la suivante:
```c
	int *ptr = NULL;
```
l'étoile devant ptr sert juste à indiquer qu'on veut créer un pointeur . 
ptr est un pointeur qui pointe vers un objet de type int. Il convient  de veiller à ce que l'adresse sur laquelle les pointeurs pointent soit valides; c'est pourquoi il faut initialiser explicitement un pointeur sur la valeur de pointeur nulle (NULL).
 
## 4 Affectation de l'adresse d'une variable à un pointeur
```c
int a = 10;
int *ptr = &a;
```
L’adresse de la variable **a** est transférée dans le pointeur **ptr**. Si un pointeur
**ptr** contient l'adresse d'une variable **a**, on dit que ptr pointe sur a. 

## 5 lire et écrire une variable pointée
Déférencer un pointeur consiste à obtenir la valeur de la variable pointée. Pour déréférencer le pointeur, une étoile est utilisée à nouveau:

```c
int b ;
b = *ptr ; // b contient la valeur de A soit 10
```
Il est également possible d'affecter une nouvelle valeur à la variable pointée par ptr.
```c
*ptr = 8;
```
la variable **a** qui est pointée par ptr contient maintenant 8

## Changelog

 **24/12/2018 :** Ajout du README . 
 
 
> **Notes :**


> - Licence : **licence publique générale** ![enter image description here](https://img.shields.io/badge/licence-GPL-green.svg)
> - Auteur **Philippe SIMIER Lycée Touchard Le Mans**
>  ![enter image description here](https://img.shields.io/badge/built-passing-green.svg)
<!-- TOOLBOX 

Génération des badges : https://shields.io/
Génération de ce fichier : https://stackedit.io/editor#




