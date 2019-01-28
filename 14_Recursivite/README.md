# Fonctions récursives

## 1 Introduction
La notion de **récursivité** est avant tout un problème algorithmique qui ne dépend pas du langage utilisé.
Les fonctions en langages C peuvent être utilisées de manière récursive, c'est à dire qu'une fonction peut s'appeler elle-même. Cette utilisation est ce que l'on appelle la récursivité.
L' exemple traditionnel est l'écriture d'un nombre sous la forme d'une chaîne de caractères dans une base (Dans l'exemple suivant chaque chiffre est séparé par le séparateur virgule).

```c
void afficherNombre(int n, int base){
    int i = 0;
    if (n < 0){
        putchar('-');
        n = -n;
    }
    if((i = n/base) != 0){
        
        afficherNombre(i, base);
        putchar(',');
    }
    putchar(n % base + '0');   
}

int main(int argc, char** argv) {
    int n = 1023;
    afficherNombre(n, 10);
    return (EXIT_SUCCESS);
}
```
Les appels des fonctions récursives sont en fait empilées dans la Call Stack. Chaque appel se trouve donc l'un à la suite de l'autre dans la pile du programme. Une fonction de ce type possède donc deux parcours: la phase de descente puis la phase de remontée. 
Avec netbeans on peut observer l'état de la pile, en plaçant un point d'arrêt au début de la fonction puis en l' exécutant en pas à pas. 
### Phase descendante 

|  name  | variable i |
|----------|------------|
| afficherNombre (n=1, base=10) | i = 0 |
| afficherNombre (n=10, base=10) | i  =1 |
| afficherNombre (n=102, base=10) | i = 10 |
| afficherNombre (n=1024, base=10)  | i = 102 |

### Phase de remontée

| variable n | variable i| Affichage |
|------------|-----------|-----------|
| n = 1      |	i = 0    |  '1' |
| n = 1      | i = 1     |  ',' et '0' |
| n = 102    | i = 10    |  ',' et '2' |
| n = 1024   | i = 102   | ',' et '4' |



## Changelog

 **24/01/2019 :** Ajout du README . 
 
 
> **Notes :**


> - Licence : **licence publique générale** ![enter image description here](https://img.shields.io/badge/licence-GPL-green.svg)
> - Auteur **Philippe SIMIER Lycée Touchard Le Mans**
>  ![enter image description here](https://img.shields.io/badge/built-passing-green.svg)
<!-- TOOLBOX 

Génération des badges : https://shields.io/
Génération de ce fichier : https://stackedit.io/editor#



