# Les accès fichiers

## 1 Introduction 

Dans un ordinateur il y a principalement deux sortes de mémoire:  la mémoire centrale et la mémoire non volatile pour mémoriser des données de manière permanente. (Disque ou clef USB). 
Un fichier est une série de données stockées sur un périphérique de stockage. 
Un **fichier texte** est un fichier qui contient du texte (une suite de caractères codés en ASCII ou UTF8). Lorsqu'un fichier texte contient des nombres, ces nombres sont codés sous forme de texte à l'aide de caractères '1', '2', etc.  On peut visualiser un fichier avec un éditeur de texte comme nano. 
Un **fichier binaire** contient du code binaire. On ne peut pas visualiser son contenu avec un éditeur de texte. Lorsqu'une variable est écrite dans un fichier binaire, on écrit directement la valeur exacte de la variable telle qu'elle est codée en binaire en mémoire.  Cette manière de stocker est plus précise et plus compacte pour coder des nombres. 

## 2 Ouverture

Avant qu'on puisse lire un fichier ou écrire dedans, il faut que le fichier ait été ouvert par la fonction fopen. Cette fonction va lier un nom externe de fichier avec une variable interne, un pointeur sur fichier FILE* qui devra être utilisé à chaque fois que l'on voudra faire ultérieurement des lectures ou des écritures sur ce fichier. 
```c
	FILE *fd;
	 
	if ((fd = fopen("fichier.txt", "r")) == NULL) {
		perror("Erreur ouverture du fichier");
		exit(errno);
	}
```
 La fonction **fopen** prend deux arguments, le premier est le nom de fichier, ou plus exactement le chemin vers le fichier dans l'arborescence des répertoires. dans le cas d'un chemin relatif, le chemin part du répertoire de travail, c'est à dire là ou est exécuté le programme.  dans le cas du chemin absolu, le chemin part de la racine de l'arborescence des répertoires (la partition **/** sous linux).
 le deuxième argument est le mode (lecture, écriture, ajout)
 
 | mode | type | désignation |
 |------|------|-------------|
 | "r"  | lecture | Le fichier est ouvert au début en lecture seule
 | "w"  | écriture | Le fichier est ouvert en écriture seule si le fichier existait les données qui se trouvaient dedans seront écrasées |
 | "a"   | écriture | le fichier n'est pas écrasé mais est près à écrire à la suite des données existantes |
 | "r+"  | lecture-écriture | le fichier est prêt pour lire et écrire au début du fichier, le fichier n'est pas écrasé |
 | "w+" | lecture-écriture | le fichier est écrasé |
 | "a+" | lecture-écriture | le fichier n'est pas écrasé, mais est près pour écrire des données à la suite des données existantes |

la fonction fopen retourne un pointeur NULL en cas d'erreur d'ouverture du fichier. (fichier inexistant, ou permissions insuffisantes au niveau du système).

## 3 Fermeture
Après avoir lu ou écrit des données dans un fichier, il faut le refermer en appelant la fonction **fclose()**. Elle prend en paramètre le pointeur de fichier et ferme le fichier. l'appel à la fonction fclose vide le buffer où les données sont stokées temporairement an attendant leur transfert définitif.

## 4 Lire et Ecrire des données formatées
Pour lire des données numériques (des nombres) ou autres dans un fichier texte on peut utiliser la fonction fscanf() qui est analogue scanf(). La fonction fscanf() prend pour premier paramètre le pointeur de fichier. 

Pour écrire des données numériques (des nombres) ou autres dans un fichier texte on peut utiliser la fonction fprintf()  qui est analogue printf(). La fonction fprintf() prend pour premier paramètre le pointeur de fichier. 

## Changelog

 **24/01/2019 :** Ajout du README . 
 
 
> **Notes :**


> - Licence : **licence publique générale** ![enter image description here](https://img.shields.io/badge/licence-GPL-green.svg)
> - Auteur **Philippe SIMIER Lycée Touchard Le Mans**
>  ![enter image description here](https://img.shields.io/badge/built-passing-green.svg)
<!-- TOOLBOX 

Génération des badges : https://shields.io/
Génération de ce fichier : https://stackedit.io/editor#



