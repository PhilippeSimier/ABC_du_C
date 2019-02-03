# Les fonctions

## 1 définition

Les **fonctions** permettent de diviser les tâches importantes de façon à écrire de petits programmes. Ainsi en général, un programme en langage C comprend un grand nombre de petites fonctions. Un programme peut se trouver dans un ou plusieurs fichiers et ceux-ci peuvent être compilés séparément.

Le code suivant définit une fonction **fonction** renvoyant une valeur de type type_retour et prenant N arguments, **par1** de type type1, **par2** de type type2.

```c
type_retour fonction(type1 par1, type2 par2) 
{
        /* Déclarations de variables ... */
        /* Instructions ... */
}
```
L'exécution d'une fonction se termine soit lorsque l'accolade fermante est atteinte, soit lorsque le mot clef **return** est rencontré. La valeur renvoyée par une fonction est donnée comme paramètre à return. exemple **return 5** renvoie la valeur entière 5.

Les passages des arguments aux fonctions **se font toujours par valeur** , c'est à dire que la fonction appelée reçoit une copie provisoire des arguments qui lui est propre. Cela veut dire que la fonction ne peut pas modifier la valeur des arguments dans le programme appelant. A l'intérieur de la fonction, chaque argument est une variable locale initialisée à la valeur avec laquelle la fonction a été appelée.  

Quand l'argument d'une fonction est un tableau, c'est la position du premier élément (un pointeur) qui est transmise. Les éléments du tableau ne sont pas recopiés. On dit que **les tableaux sont transmis par variable**. Dans le chapitre 05, j'explique l'emploi des pointeurs qui permet aux fonctions de modifier autre chose que des tableaux dans les fonctions. (on peut considérer une variable comme un tableau à un seul élément).

Les variables locales à une fonction sont détruites à la fin de l'exécution de la fonction sauf si elles ont été déclarées **statique**.  autrement dit les variables locales statiques existent même quand la fonction qui les contient n'est pas appelée. Cela implique que de tels variables engendrent une mémorisation permanente. 
 
## 2 Déclaration d'une fonction par prototype

Le **prototype** d'une fonction correspond simplement à son en-tête (tout ce qui précède la première accolade ouvrante). C'est-à-dire son nom, son type de retour et les types des différents paramètres. Cela permet au compilateur de vérifier que la fonction est appelée avec le bon nombre de paramètres et surtout avec les bons types. La ligne suivante déclare la fonction fonction, mais sans la définir :

```c
type_retour fonction(type1 par1, type2 par2);
```
*Remarque* les noms des paramètres peuvent être omis. 
La déclaration doit se terminer par un point-virgule (;) sans quoi vous aurez  une flopée d'erreurs.

##3 Exemple
```c
int max(int a, int b)
{
int max;
    if(a > b) 
	    max = a;
	else 
	    max = b;
	return max;    
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



