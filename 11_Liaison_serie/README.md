# Liaison série - Raspberry Pi3 plus

## 1 Présentation
Pour obtenir un port série standard RS232, il est nécessaire d'ajouter une carte hat qui comprend les circuits nécessaires à la conversion de niveaux des signaux électriques.
 ![raspi-config ](/11_Liaison_serie/images/carte_hat_RS232.PNG)
 
Avant d’utiliser le port série, vérifier que la console n’est pas en écoute sur le port Série. Pour cela exécutez
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

## Changelog

 **24/12/2018 :** Ajout du README . 
 
 
> **Notes :**


> - Licence : **licence publique générale** ![enter image description here](https://img.shields.io/badge/licence-GPL-green.svg)
> - Auteur **Philippe SIMIER Lycée Touchard Le Mans**
>  ![enter image description here](https://img.shields.io/badge/built-passing-green.svg)
<!-- TOOLBOX 

Génération des badges : https://shields.io/
Génération de ce fichier : https://stackedit.io/editor#



