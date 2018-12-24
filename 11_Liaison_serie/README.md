# Liaison série - Raspberry Pi3 plus

## 1 Présentation
Pour obtenir un port série standard RS232, il est nécessaire d'ajouter une carte hat qui comprend les circuits nécessaires à la conversion de niveaux des signaux électriques.

 ![raspi-config ](/11_Liaison_serie/images/carte_hat_RS232.PNG)
 
Avant d’utiliser le port série, vérifier que la console n’est pas en écoute sur le port série. Pour cela exécutez
```bash
pi@raspPi3plus:~ $ sudo raspi-config
```
![raspi-config ](/11_Liaison_serie/images/raspi-config.PNG)

Sélectionner l'**option 5**  puis **P6 serial**

![ecran2 ](/11_Liaison_serie/images/ecran2.PNG)

Désactiver le shell sur le port série, puis activer l'interface série.

![ecran3 ](/11_Liaison_serie/images/ecran3.PNG)

## 2 Configuration en ligne de commande
La commande stty permet  de connaitre la configuration d'un port série.
Exemple pour **ttyS0** :
```bash
pi@raspPi3plus:~ $ stty -F /dev/ttyS0
speed 9600 baud; line = 0;
-brkint -imaxbel
```
Elle permet également de configurer le port série
```bash
pi@raspPi3plus:~ $ sudo stty -F /dev/ttyS0 57600
pi@raspPi3plus:~ $ stty -F /dev/ttyS0
speed 57600 baud; line = 0;
-brkint -imaxbel
```
Pour effectuer un test de transmission en ligne de commande : rediriger la sortie de la commande echo vers /dev/ttyS0
```bash
pi@raspPi3plus:~ $ echo 'bonjour le monde' > /dev/ttyS0
```
## 3 Programmation en C
Sous Linux rasbian, chaque port série de votre raspberry est représenté par un fichier de périphérique situé dans le répertoire /dev. Le port série présent sur le connecteur 40 broches correspond au fichier **/dev/ttyS0**.
Les ports séries correspondant aux adaptateurs USB correspondent aux fichiers **/dev/ttyUSB0** **/dev/ttyUSB1** etc

Au niveau d'un programme en C, on ouvre ces fichiers exactement comme on ouvrirait n'importe quel autre fichier grâce à l'appel système **open()** :

```C
    fd = open(device, O_RDWR | O_NOCTTY );
    if ( fd == -1 ) {
        printf("pb ouverture: %s\n", strerror(errno));
        exit(EXIT_FAILURE);
    }

```
Une fois que le port est ouvert, on peut y lire et y écrire des caractères au moyen des primitives read() et write().

### 3-1 Paramétrage de la liaison série
Tous les paramètres d'une liaison sont regroupés dans une structure appelée termios et définie dans le fichier `<termios.h>`  qu'il nous faut donc inclure.
Cette structure comporte les champs suivants :
```C
struct termios {
		tcflag_t c_iflag;		/* input mode flags */
		tcflag_t c_oflag;		/* output mode flags */
		tcflag_t c_cflag;		/* control mode flags */
		tcflag_t c_lflag;		/* local mode flags */
		cc_t c_line;			/* line discipline */
		cc_t c_cc[NCCS];		/* control characters */
	};
```
La fonction **tcgetattr()** permet d'obtenir les paramètres actuels d'une liaison. 

### 3-2 Les champs de la structure termios

 1. **c_iflag** : les modes d'entrée
Ils définissent un traitement à appliquer sur les caractères en provenance de la liaison série :
**IGNBRK** : les caractères BREAK sont ignorés.
**IGNPAR** : les caractères qui comportent une erreur de parité sont ignorés.
**ISTRIP** : dans le cas d'une transmission sur 8 bits, le huitième bit est systématiquement mis à zéro.

 2. **c_oflag** : les modes de sortie 
Ils définissent un traitement à appliquer sur les caractères envoyés sur la liaison série. On y trouve notamment OLCUC qui transforme les minuscules (non accentuées !) en majuscules.

 3. **c_cflag** : Les modes de contrôle Ce champ est important, car c'est ici que l'on définit le débit, la parité utilisée, les bits de donnée et de stop, ...
**CLOCAL** : si ce flag n'est pas utilisé, une déconnexion (ie. chute du signal DCD) entraîne la fermeture automatique du port série et les prochains appels à read() renverront la valeur -1. 
**CS7** : chaque caractère est composé de 7 bits.
**CS8** : chaque caractère est composé de 8 bits (c'est le cas le plus fréquent).
**PARENB** : activation du mécanisme de parité paire.
**PARODD** : utilisation d'une parité impaire au lieu d'une parité paire par défaut.

 4. **c_lflag** : les modes locaux
Ce champ est d'une importance capitale : il définit le mode (canonique ou non) et la gestion de l'écho des caractères reçus. 
**ECHO** : un écho des caractères reçus est effectué.
**ICANON** : passage en mode canonique, c'est-à-dire que les caractères reçus sont stockés dans un tampon et qu'ils ne sont disponibles qu'à la réception d'un caractère eol (de code ASCII décimal 10).

 5. c_cc : les caractères de contrôle 
 **VMIN** : en mode non-canonique, spécifie le nombre de caractéres que doit contenir le tampon pour être accessible à la lecture. En général, on fixe cette valeur à 1.
**VTIME** : en mode non-canonique, spécifie, en dixièmes de seconde, le temps au bout duquel un caractère devient accessible, même si le tampon ne contient pas c_cc[VMIN] caractères. Une valeur de 0 représente un temps infini.

### 3-3 Le paramétrage de la vitesse
la fonction **cfsetospeed ()** et  **cfsetispeed** permettent de définir les débits en bauds de sortie et d'entrée stockés dans la structure termios indiquée, la valeur doit être l'une des constantes suivantes: 

 - B0
 - B50
 - B75
 - B110
 - B134
 - B150
 - B200
 - B300
 - B600
 - B1200
 - B1800
 - B2400
 - B4800
 - B9600
 - B19200
 - B38400
 - B57600
 - B115200

```C
    if(cfsetispeed(&term, B9600) < 0 || cfsetospeed(&term, B9600) < 0) {
       printf("Erreur configuration\n");
       }

```
## 4 la bibliothèque série
la bibliothèque série propose un ensemble de fonctions pour :

 - Ouvrir fermer un port série;
 - Configurer le port série ouvert
 - envoyer et recevoir un caractère
 - envoyer et recevoir un message
 - vider le tampon de réception des caractères non lus.
 - Obtenir le nombre de caractères non lus dans le tampon
 - Obtenir la vitesse de transmission du port ouvert
 
Le programme **main.c** est un exemple d'utilisation de la bibliothèque série.


## Changelog

 **24/12/2018 :** Ajout du README . 
 
 
> **Notes :**


> - Licence : **licence publique générale** ![enter image description here](https://img.shields.io/badge/licence-GPL-green.svg)
> - Auteur **Philippe SIMIER Lycée Touchard Le Mans**
>  ![enter image description here](https://img.shields.io/badge/built-passing-green.svg)
<!-- TOOLBOX 

Génération des badges : https://shields.io/
Génération de ce fichier : https://stackedit.io/editor#



