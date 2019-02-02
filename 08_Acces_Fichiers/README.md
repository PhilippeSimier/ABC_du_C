# Les accès fichiers

## 1 Introduction 

Dans un ordinateur il y a principalement deux sortes de mémoire:  la mémoire centrale et la mémoire non volatile pour mémoriser des données de manière permanente. (Disque carte SD ou clef USB). 
Un fichier est une série de données stockées sur un périphérique de stockage.
 
Un **fichier texte** est un fichier qui contient du texte (une suite de caractères codés en ASCII ou UTF8). Lorsqu'un fichier texte contient des nombres, ces nombres sont codés sous forme de texte à l'aide de caractères '1', '2', etc.  On peut visualiser un fichier avec un éditeur de texte comme nano. 

Un **fichier binaire** contient du code binaire. On ne peut pas visualiser son contenu avec un éditeur de texte. Lorsqu'une variable est écrite dans un fichier binaire, on écrit directement la valeur exacte de la variable telle qu'elle est codée en binaire en mémoire.  Cette manière de stocker est plus précise et plus compacte pour coder des nombres. 

## 2 Ouverture d'un fichier

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

## 4 Lire et Ecrire des chaînes de caractères

La bibliothèque standard fournit la fonction **fgets** pour lire la ligne suivante dans le fichier d'entrée. la fonction fgets renvoie **NULL** à la fin du fichier.

la fonction **fputs** écrit une chaîne de caractères dans un fichier ouvert en écriture.

exemple
```c
#define NB_CAR 50

FILE *fr;
FILE *fW;
char ligne[NB_CAR];

if((fr = fopen("input.txt", "r")) == NULL){
        perror("Erreur Ouverture du fichier");
        exit(errno);
    }
if((fw = fopen("output.txt", "w")) == NULL){
        perror("Erreur Ouverture du fichier");
        exit(errno);
    } 

while (fgets(ligne, NB_CAR, fr) != NULL){
    fputs(ligne, fw);
}    
```


## 5 Lire et Ecrire des données formatées 

Pour lire des données numériques (des nombres) ou autres dans un fichier texte on peut utiliser la fonction **fscanf()** qui est analogue scanf(). La fonction **fscanf()** prend pour premier paramètre le pointeur de fichier. 


Pour écrire des données numériques (des nombres) ou autres dans un fichier texte on peut utiliser la fonction **fprintf()**  qui est analogue printf(). La fonction **fprintf()** prend pour premier paramètre le pointeur de fichier. 
 
 Exemple
 On peut mettre des appels de fonctions comme fscanf dans une condition. içi **fscanf** retourne 1 en cas de succès. Notons aussi qu'à chaque lecture par **fscanf**, le pointeur de fichier passe à la suite dans le fichier. le pointeur avance automatiquement dans le fichier lorsqu'on effectue une lecture.
```c
// lecture d'un entier dans fichierLecture.txt
// ecriture d'un entier dans fichierEcriture.txt
int n;
FILE *fpr, *fpw;

fpr = fopen("fichierLecture.txt", "r");
fpw = fopen("fichierEcriture.txt", "w");
while (fscanf(fpr, "%d", &n) == 1){
     fprintf(fpw, "%d ", 10*n);
    }
fclose(fpr);
fclose(fpw);    
    	
```

## 6 Lire et Ecrire des données dans un fichier binaire
Pour lire dans un fichier binaire, on lit en général dans le fichier les éléments d'un tableau, chaque éléments du tableau est appelé **bloc**.
La fonction de lecture **fread** prend en paramètre le tableau, la taille de chaque bloc, le nombre de bloc à lire et le pointeur de fichier. La fonction fread transfère les données binaires vers le tableau. La fonction fread retourne le nombre d'éléments effectivement lus.

Pour écrire dans un fichier binaire, on utilise la fonction **fwrite** qui transfère les données de la mémoire centrale vers un fichier binaire.
La fonction **fwrite** prend en paramètre le tableau, la taille de chaque bloc, le nombre de bloc et le pointeur de fichier.
 chaque appel à fread ou fwrite fait avancer la position courante du nombre d'octets lus ou écrits.

La fonction **fseek** permet de se positionner dans un fichier, en modifiant la position courante pour pouvoir lire ou écrire à l'endroit souhaité.

## Changelog

 **24/01/2019 :** Ajout du README . 
 
 
> **Notes :**


> - Licence : **licence publique générale** ![enter image description here](https://img.shields.io/badge/licence-GPL-green.svg)
> - Auteur **Philippe SIMIER Lycée Touchard Le Mans**
>  ![enter image description here](https://img.shields.io/badge/built-passing-green.svg)
<!-- TOOLBOX 

Génération des badges : https://shields.io/
Génération de ce fichier : https://stackedit.io/editor#



