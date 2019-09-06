# Type de données

## 1 Variables 

Dans un programme, il apparaît des **variables** qui permettent de donner des noms à des données. Chaque variable doit avoir un **type** (nombre entier, nombre réel, caractère, suite de caractères ou type plus complexe). Chaque variable a aussi un identificateur qui est le nom de la variable.
On dit que Le **langage C est un langage typé statiquement** car chaque variable, chaque constante et chaque expression, a un type **défini à la compilation**.

## 2 Déclaration

la syntaxe pour déclarer une variable est :

 - type identificateur;
 
ou bien avec l'initialisation (on donne à la variable une valeur initiale) 

- type identificateur = valeur;

## 3 Les entiers
Il y a cinq types de variables entières (« integer » en anglais) : **char , short , int , long , long long**. Les types entiers peuvent prendre les modificateurs **signed** et **unsigned** qui permettent respectivement d'obtenir un type signé ou non signé.

 | type          | taille | borne inférieure | borne supérieure |
 |---------------|--------|------------------|------------------|
 | signed char   | 8 bits |-128  | +127 |	
 | unsigned char | 8 bits | 0	 | +255 |	
 | short	 | 16 bits  |-32 768 | +32 767 |
 | unsigned short  | 16 bits |	0 | +65 535 |
 | int	         | ≥ 16 bits |	-32 768	| +32 767 |
 | unsigned int  | ≥ 16 bits |	0 | +65 535	|
 | long          | ≥ 32 bits |	-2 147 483 648 | +2 147 483 647 |
 | unsigned long | ≥ 32 bits |	0  | +4 294 967 295 |
 | long long     | ≥ 64 bits |	-9 223 372 036 854 775 808 | +9 223 372 036 854 775 807 |
 | unsigned long long | ≥ 64 bits | 0 |	+18 446 744 073 709 551 615 |
 
*Remarque* : Les tailles dépendent du système utilisé.

## 4 Les nombres réelles

Les nombres réels ne peuvent pas  tous être représentés, Ils sont approximés par les nombres à virgule flottante les plus proches.  On peut dire que les nombres à virgule flottante sont un sous-ensemble des réels.  Il existe trois types de nombre à virgule flottante.  **float, double, long double**.
 
 **Exemple** classique  qui illustre les problèmes liés à la précision des types flottants :
```c
 #include <stdio.h>

int main(void)
{
    float i = 0;
    int j;
    for (j = 0; j < 1000; j ++)
    {
        i += 0.1;
    }
    printf("i = %f\n", i);
    return 0;
}
```
Le résultat de se programme est  99,999046 car le nombre 0.1 n'a pas de représentation exacte en binaire. Les erreurs vont donc s'accumuler dans la boucle.

## 5 Les booléens

A l'origine, le langage C  ne fournissait pas de type booléen. La valeur entière 0 est équivalente à  la valeur booléenne faux et toutes les autres valeurs entières sont équivalente à la valeur booléenne vrai.

Toutefois le langage a évolué, et depuis la version dite C99.  cette évolution introduit le type _Bool, qui peut contenir les valeurs 0 et 1. Elle a aussi ajouté l'en-tête `<stdbool.h>`, qui définit le type **`bool`** qui est un raccourci pour _Bool, et les valeurs **`true`** et **`false`**.

## 6 Les classes de stockage

Le langage C permet de spécifier, avant le type d'une variable, un certain nombre de classes de stockage :

 - **extern** : déclare une variable sans la définir ;
 - **register** : demande au compilateur de faire tout son possible pour
   utiliser un registre processeur pour cette variable ;
 - **static** : rend une définition de variable persistante.

Exemple une variable statique dans la fonction f() :
```c
#include <stdio.h>

void f(void)
{
    static int i = 0; // i sera initialisée à 0 à la compilation seulement 
    int j = 0; // j sera initialisée à chaque appel de f
    i++;
    j++;
    printf("i vaut %d et j vaut %d.\n", i, j);
}

int main(void)
{
    f();
    f();
    f();
    return 0;
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



