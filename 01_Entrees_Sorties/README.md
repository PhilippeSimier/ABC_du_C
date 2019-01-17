# Les entrées sorties en langage C

## 1 Écriture formatée de données

La fonction **printf** est utilisée pour transférer du texte, des valeurs de variables ou des résultats d'expressions vers le fichier de sortie standard **stdout** (par défaut l'écran). Elle accepte en arguments une chaîne de format et une liste d'arguments facultatifs. Elle génère en sortie une séquence de caractères mise en forme.

#### Les spécificateurs de format

**Les spécificateurs de format** commencent toujours par le symbole **%** et se terminent par un ou deux caractères qui indiquent le format d'impression.
Les spécificateurs de format impliquent une conversion par exemple d'un nombre entier ou flottant en chaîne de caractères.

exemple
```c
printf( "%s", user_name );
```
 | Format | Argument | Format de sortie |
|----------|----------|------------------|
| %c | char | un caractère|
| %d | int  | un entier signé représenté en décimal|
| %o | int  | un entier signé représenté en octal|
| %x | int  | un entier signé représenté en hexadécimal (a,b,c,d,e,f) |
| %X | int  | un entier signé représenté en hexadécimal (A,B,C,D,E,F) |
| %f | float| un flottant simple précision |
| "%lf | double | un flottant en double précision | 
| %p | pointeur| une adresse de variable   |
| %s | char * | une chaîne de caractères |

#### les Spécification de largeur

Dans une spécification de conversion, le champ  de largeur peut apparaître après n’importe quel caractère d’indicateur. L’argument  est un entier décimal non négatif qui contrôle le nombre minimal de caractères qui sont générés. Si le nombre de caractères dans la valeur de sortie est inférieur à la longueur spécifiée, des espaces sont ajoutés à gauche ou à droite des valeurs, selon que l’indicateur d’alignement à gauche (-) est spécifié ou non, jusqu’à ce que la largeur minimale soit atteinte.

exemple:
```c
  printf("%2d\n", 3);     // affiche  3 sur deux caractères
  printf("%.2d\n", 3);    // affiche 03  (deux caractères)
  printf("%.4X\n", 255);  // affiche 00FF (quatre caractères)
  printf("%10s\n", "nom"); // affiche     nom (10 caractères)
```
 
## 2 Lecture formatée de données
La fonction **scanf()** lit les données à partir du flux d’entrée standard stdin et écrit les données dans l’emplacement indiqué par argument. Chaque argument doit être un **pointeur** vers une variable d’un type qui correspond à un spécificateur de type dans format. 


exemple :
```c
int valeur = 0;
scanf( "%d", &valeur );
```


## Changelog

 **24/12/2018 :** Ajout du README . 
 
 
> **Notes :**


> - Licence : **licence publique générale** ![enter image description here](https://img.shields.io/badge/licence-GPL-green.svg)
> - Auteur **Philippe SIMIER Lycée Touchard Le Mans**
>  ![enter image description here](https://img.shields.io/badge/built-passing-green.svg)
<!-- TOOLBOX 

Génération des badges : https://shields.io/
Génération de ce fichier : https://stackedit.io/editor#



