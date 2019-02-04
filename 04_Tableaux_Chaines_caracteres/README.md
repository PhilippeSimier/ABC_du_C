# Les tableaux

## 1 définition

Il existe deux types de tableaux : les tableaux statiques, dont la taille est connue à la compilation, et les tableaux dynamiques, dont la taille est connue à l'exécution. Nous ne nous intéresserons pour l'instant qu'aux tableaux statiques.
Un tableau permet de mémoriser plusieurs données du même type.
 
## 2 Déclaration d'un tableau

```c
    #define N 50
    int tableau[N];
```
Déclare un tableau de N éléments, les éléments étant de type int. N doit être un nombre connu à la compilation, N ne peut pas être une variable.  La déclaration 
**int tab[N]** réserve une zone mémoire suffisante pour stocker 50 variables de type int, désignées par tab[0], tab[1]..., tab[49]
Lorsqu'un tableau est créé, il prend un espace contigu en mémoire, autrement dit, les cases sont les unes à la suite des autres. Toutes les cases d'un tableau sont du même type. Ainsi, un tableau de **int** contiendra uniquement des **int**, et pas autre chose.

## 3 Accès aux éléments

Si vous écrivez juste **tableau**, vous obtenez un pointeur sur la première case du tableau. Les éléments d’un tableaux sont numérotés par des indices, 0,1,2,3,4,5…

 - ***tableau** donne la valeur du premier élément **tableau[0]**
 - ***(tableau+1)** donne la valeur du deuxième élément **tableau[1]**
 - **tableau[]** représente un pointeur sur la première case du tableau.

```c
    tableau[5] = 18;
```

## 4 Parcourir un tableau

Les boucles for sont très pratiques pour parcourir un tableau.
```c
for (int i = 0 ; i < N ; i++)
{
    printf("%d\n", tableau[i]);
}
```
## 5 Initialiser un tableau
Il est possible d'initialiser directement les tableaux lors de leur déclaration :
```c
    int tableau[5] = { 1 , 5 , 45 , 3 , 9 };
```
Si on déclare un tableau, mais qu'on l'initialise avec moins d'éléments qu'il peut contenir, les éléments restant seront mis à zéro. On utilise cette astuce pour initialiser rapidement un tableau à zéro :

```c
    int tableau[N] = {0};
```


## Changelog

 **04/02/2019 :** Ajout du README . 
 
 
> **Notes :**


> - Licence : **licence publique générale** ![enter image description here](https://img.shields.io/badge/licence-GPL-green.svg)
> - Auteur **Philippe SIMIER Lycée Touchard Le Mans**
>  ![enter image description here](https://img.shields.io/badge/built-passing-green.svg)
<!-- TOOLBOX 

Génération des badges : https://shields.io/
Génération de ce fichier : https://stackedit.io/editor#



