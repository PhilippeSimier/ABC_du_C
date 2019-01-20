# Les entrées sorties en langage C

La bibliothèque ***stdio.h*** contient les fonctions permettant de gérer les entrées sorties (saisies au clavier, affichage de texte). Pour utiliser les fonctionnalités de bibliothèque stdio.h, il faut mettre au début du programme :
```c
#include <stdio.h>
```

## 1 Afficher des données sous forme de texte
Pour afficher un caractère, utiliser la fonction **putchar()**
```c
putchar('A');   // affiche la lettre A
putchar(65);      // afficche aussi la lettre A
```
Pour afficher une chaîne de caractères,  utiliser ma fonction **puts()**
```c
puts("Coucou !");   // affiche le massage Coucou !
```
La fonction puts va automatiquement à la ligne après l'affichage.

## 2 Écriture formatée de données

La fonction **printf** est utilisée pour transférer du texte, des valeurs de variables ou des résultats d'expressions vers le fichier de sortie standard **stdout** (par défaut l'écran). Elle accepte en arguments une chaîne de format et une liste d'arguments facultatifs. Elle génère en sortie une séquence de caractères correspondant à  la mise en forme des données.

#### Les spécificateurs de format

**Les spécificateurs de format** commencent toujours par le symbole **%** et se terminent par un ou deux caractères qui indiquent le format d'impression.
chaque spécificateur de format implique une conversion par exemple conversion d'un nombre entier ou flottant en chaîne de caractères.

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
| %u | unsigned int | un entier non signé|
| %zu | size_t | résultat de l'opérateur sizeof |
| %f | float| un flottant simple précision en notation virgule fixe|
| %lf | double | un flottant en double précision en notation virgule fixe | 
| %e | double | un double précision représenté en notation mantisse exposant (la lettre **e** introduit l'exposant) |
| %p | pointeur| une adresse de variable   |
| %s | char * | une chaîne de caractères |

#### Le champ de largeur

Le champ Largeur spécifie un nombre minimal de caractères à produire et est généralement utilisé pour remplir les champs de largeur fixe dans une sortie tabulée. Le champ  de largeur peut apparaître avant n’importe quel caractère d’indicateur. C'est un entier décimal  qui contrôle le nombre minimal de caractères qui sont générés. Si le nombre de caractères dans la valeur de sortie est inférieur à la longueur spécifiée, des espaces sont ajoutés à gauche ou à droite des valeurs, selon que l’indicateur d’alignement à gauche (-) est spécifié ou non, jusqu’à ce que la largeur minimale soit atteinte.

Exemple:
```c
  printf("%2d\n", 3);        // affiche  3 sur deux caractères
  printf("%10s\n", "nom");   // affiche     nom (10 caractères)
  printf("%04X\n",255);      // affiche  00FF  
```
#### Le champ de précision

Le champ **Précision** spécifie généralement une limite maximale pour la sortie, en fonction du type de formatage utilisé. Pour les types numériques à virgule flottante, il spécifie le nombre de chiffres à droite de la virgule décimale auquel la sortie doit être arrondie.

Exemple:
```c
  printf("%.2d\n", 3);       // affiche 03  (deux caractères)
  printf("%.4X\n", 255);     // affiche 00FF (quatre caractères)
  printf("%.2e\n", 0.0015);  // affiche 1.50e-03
  printf("%.4s\n","philippe"); // affiche phil (quatre caractères)
```


## 3 Lecture au clavier
La fonction **getchar()** permet de lire un caractère à partir du flux d'entrée standard (stdin).
la fonction **fgets()** lit au plus size - 1 caractères depuis le flux spécifié et les place dans
la chaine de caractères buffer.
Exemple :
```c
char buffer[255];
fgets(buffer, sizeof(buffer), stdin);
```
 
## 4 Lecture formatée de données
La fonction **scanf()** lit les données à partir du flux d’entrée standard stdin et écrit les données dans l’emplacement indiqué par argument. Chaque argument doit être un **pointeur** vers une variable d’un type qui correspond à un spécificateur de type dans format. 


exemple :
```c
int valeur = 0;
scanf( "%d", &valeur );  // ne pas oublier le & devant la variable
```
Lecture de chaînes de caractères contenant des espaces blancs avec scanf().

```c
char ligne[1000];
scanf("%[^\n]%*c", ligne);
```
Le %*c dans "%[^\n]%*c" indique qu'il faut lire un caractère  (le retour à la ligne) et qqu'il faut le stocker nulle part et donc l'oublier aussitôt (le retour à la ligne).  Ce comportement consistant à lire quelque chose mais à ne pas le stocker est du au \*

## Changelog

 **24/12/2018 :** Ajout du README . 
 
 
> **Notes :**


> - Licence : **licence publique générale** ![enter image description here](https://img.shields.io/badge/licence-GPL-green.svg)
> - Auteur **Philippe SIMIER Lycée Touchard Le Mans**
>  ![enter image description here](https://img.shields.io/badge/built-passing-green.svg)
<!-- TOOLBOX 

Génération des badges : https://shields.io/
Génération de ce fichier : https://stackedit.io/editor#



