# GPS

## La réception GPS

Un récepteur GPS est capable de se géolocaliser grâce à la réception de signaux émis par des satellites géostationnaires. Le récepteur GPS détermine par calcul sa position et peut la transmettre sous forme d’une trame NMEA.

Le calcul de la position est effectué par le récepteur qui fabrique une **trame de caractères NMEA**. Cette trame est ensuite envoyée via une liaison série. L’ordinateur décode la trame et affiche éventuellement la carte correspondant à la position GPS reçue.


## La trame NMEA

Une trame NMEA (National Marine Electronics Association) est une suite de caractères contenant des
informations de géolocalisation comme :

 - La latitude, la longitude,
 - La vitesse, l’altitude
 - Le nombre de satellites
 - L’heure, la date

Il existe plusieurs trames correspondant à des besoins différents. Chaque trame possède une syntaxe
différente. Nous nous intéresserons à la trame la plus utilisée pour connaître la position courante du
récepteur : La trame **GGA**.
Une trame est constituée de champs. Les champs sont séparés entre eux par des virgules. Un champ
peut être vide mais la présence de la virgule est obligatoire.

### La trame GGA
Exemple de trame GGA :

    $GPGGA,102208.000,4759.7351,N,00012.2376,E,1,05,1.4,41.8,M,47.5,M,,0000*67

| Nom du champ | Ex de Valeur | Signification |
|--------------|--------------|---------------|
|Type de trame | $GPGGA | Indique qu’il s’agit d’une trame de type GGA |
|Heure	       | 102208.000 | Signifie que la trame a été envoyée à 10h22min08.000 s |
| Latitude     | 4759.7351 | Latitude en deg, min, sec. Les secondes doivent être convertit en base 60 : 7305/100*60 = 4385 , soit 43.85 s |
| Indicateur latitude | N | N : Nord , S : Sud |
| Longitude | 00012.2376 | Longitude en deg, min, sec soit 0°12'14.74" |
| Indicateur longitude | E | E : Est , W :Ouest |
| Positionnement | 1 |  0=non calé, 1=calé, 2=calé en mode différentiel, 6 = estimé |
| Nb de satellites | 05 | Nombre de satellites utilisés pour le calcul. La précision du positionnement dépend du nombre de satellites détectés |
| Précision | 1.4 | Dilution horizontale de la précision. Permet de connaître la fiabilité du calcul. 1 : Valeur optimale, 2 à 3 : excellente, 5 à 6 : bonne, supérieure à 8 : Mesure non fiable |
| Altitude | 41.8 | Altitude par rapport au niveau moyen de la mer |
|Unité altitude | M| Altitude en mètres |
| Altitude | 47.5 | Correction de la hauteur de la géoïde en Mètres par rapport à l'ellipsoïde WGS84 (MSL).|
|Unité altitude | M| Altitude en mètres |
| | | champs vide|
| |0000 | identification de la station DGPS |
|checksum | *67| 


## Conversion des angles NMEA en degrés décimaux

Les angles NMEA sont exprimés en degrés (2 chiffres) suivi de la valeur en seconde (1/60 degré).
exemple : 

 - pour la latitude : 4759.7351   donne 47 degrés et 59.7351 secondes 
Ce qui donne en degrés décimaux 

    47 + 59.7351/60 = 47.9956

 -  pour la longitude 00012.2376 donne 000 degrés et 12.2376 secondes
Ce qui donne en degrés décimaux
 
    00 + 12.2376/60 = 0.20396



# Changelog

**29/01/2020 : ** Ajout du README . 

> **Notes :**


> - Licence : **licence publique générale** ![enter image description here](https://img.shields.io/badge/licence-GPL-green.svg)
> - Auteur **Philippe SIMIER** Lycée Touchard Le Mans
>  ![enter image description here](https://img.shields.io/badge/built-passing-green.svg)
<!-- TOOLBOX 

Génération des badges : https://shields.io/
Génération de ce fichier : https://stackedit.io/editor#
example : https://github.com/adrien3d/IO_WSSFM10-Arduino

