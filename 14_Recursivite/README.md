# Fonctions récursives

## 1 Introduction

Les fonctions en langages C peuvent être utilisées de manière récursive, c'est à dire qu'une fonction peut s'appeler elle-même. Cette utilisation est ce que l'on appelle la récursivité.
L' exemple traditionnel est l'écriture d'un nombre sous la forme d'une chaîne de caractères.

```c
void afficherNombre(int n){
    int i = 0;
    if (n < 0){
	putchar('-');
	n = -n;
    }
    if((i = n/10) != 0){
	afficherNombre(i);
    }
    putchar(n%10 + '0');
}
```
## Changelog

 **24/01/2019 :** Ajout du README . 
 
 
> **Notes :**


> - Licence : **licence publique générale** ![enter image description here](https://img.shields.io/badge/licence-GPL-green.svg)
> - Auteur **Philippe SIMIER Lycée Touchard Le Mans**
>  ![enter image description here](https://img.shields.io/badge/built-passing-green.svg)
<!-- TOOLBOX 

Génération des badges : https://shields.io/
Génération de ce fichier : https://stackedit.io/editor#



