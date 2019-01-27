# Exécution conditionnelle



## 1 Introduction
Un programme informatique est capable de faire des choix selon la situation dans laquelle il se trouve et selon les données qui lui sont données en entrée. Vous allez découvrir comment faire prendre des décisions à un programme afin qu'il agisse en fonction de la situation.
L'exécution conditionnelle permet de faire deux choses différentes selon le cas qui se produit. Un bloc d'instructions sera exécutée que sous certaines conditions. Plus précisément, le programme teste une condition, si la condition est satisfaite le programme exécute un bloc d'instructions.

## 2 Condition si - alors

Exemple
```c
choix = getchar();
if(choix == 'y'){   // affiche Vous avez choisi OUI
	puts("Vous avez choisi");
	puts("OUI");
}	
```
Les instructions au conditionnel forme un bloc qui peut  être formé de plusieurs instructions entre accolades { } ou d'une seule instructions sans accolade.

## 3 Condition si - alors - sinon
Il arrive que l'on ait besoin de tester une condition puis son contraire. si le nombre d'œufs est plut petit que 12 alors afficher « Une boîte suffit », et sinon afficher « Plusieurs boîtes nécessaires » :
```c
int nbOeufs;
scanf("%d", &nbOeufs);
if (nbOeufs <= 12)
{
   printf("Une boîte suffit\n");
}
else
{
   printf("Plusieurs boîtes sont nécessaires\n");
}
```

## 4 Les conditions booléennes
Les conditions que l'on peut mettre dans une instruction if sont des conditions booléennes. Un exemple de condition booléenne est un test de comparaison entre deux expressions par les opérateurs de comparaison.
 
 |  Symbole | Signification                           |
|----------|-----------------------------------------|
|  `x == y` | est vérifier si x est égale à y |
| `x > y`   | est vérifier si x est supérieur à y |
| `x < y`   | est vérifier si x est inférieur à y|
| `x >= y`  | est vérifier si x supérieur ou égal y |
| `x <= y`  | est vérifier si x inférieur ou égal y |
|  `x != y`  | est vérifier si x est différent de y |

Il faut faire bien attention à ne pas confondre l'opérateur **==** avec le simple **=**, car les deux ont des rôles très différents :

*= sert à affecter une valeur à une variable ;*
*== sert à tester l'égalité de deux valeurs.*

## 5 Déclarer des variables booléennes

`<stdbool.h>` est l'en-tête de la bibliothèque standard C consacré aux booléens. Il a été introduit avec la norme C99.

```c
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main(int argc, char** argv) {
    bool a = true;
    bool b = false;
    
    if (a && b){
        printf("A et B est vrai");
    }
    else
        printf("A et B est faux");
    
    return (EXIT_SUCCESS);
}
```
## 6 Opérations booléennes

La **conjonction** de deux expressions booléennes s'exprime par l'opérateur **&&**. Elle est vérifiée lorsque les deux expressions sont vérifiées.

La **Disjonction** de deux expressions booléennes s'exprime par l'opérateur **||**. elle est vérifiées lorsqu'au moins une des deux expressions est vérifiée.  

La négation d'une expression booléenne s'exprime par l’opérateur **!** 

## 7 Le switch

**Switch** évalue l'expression qui lui est donnée et aiguille le programme vers le cas correspondant à la valeur effective de cette expression. Les cas sont indiqués par l'instruction case. Lorsque le programme est aiguillé, il entre dans le bloc du switch et n'en sort que lorsqu'un **break** est rencontré. Si la valeur de l'expression donnée ne correspond à aucun des cas, le programme est aiguillé vers l'instruction default qui doit apparaître après tous les case.

```c
    char x;
	x = getchar();

	switch(x) 
	{
	case 'a': printf(" cas où x = a\n"); break;
	case 'b': printf(" cas où x = b\n"); break;
	case 'c': printf(" cas où x = c\n"); break;
	case 'd': printf(" cas où x = d\n"); break;
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



