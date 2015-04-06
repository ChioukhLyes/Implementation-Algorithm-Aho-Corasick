# Implementation Algorithm Aho-Corasick

###### Algorithme d'[Aho-Corasick]  de recherche exacte d'un ensemble de k mots dans un texte.

### Méthodes

Utilisation de trois méthodes pour représenter l'arbre
 - Une matrice de transitions ;
 - Un tableau de listes d'adjacence ;
 - Une table de transitions pour la racine et un tableau de listes d'adjacence
pour les autres noeuds de l'arbre.


### Outils

 - Un générateur pseudo-aléatoire de textes qui prend deux paramétres, d'abord la longueur du texte à générer puis la taille de l'alphabet. 
 - Un générateur pseudo-aléatoire de mots qui prend quatre paramétres, d'abord le nombre de mots à générer puis la longueur minimale et la longueur maximale des mots et enfin la taille de l'alphabet.

### Version 

2.0

### Résultats

![alt tag](https://cloud.githubusercontent.com/assets/11443851/7012049/8861ef8c-dcae-11e4-8509-c26fbbc5c3d4.png)

![alt tag](https://cloud.githubusercontent.com/assets/11443851/7012050/88633c20-dcae-11e4-9dda-9178d300ff68.png)


### License

Free Software, Yeah!

[Aho-Corasick]:http://fr.wikipedia.org/wiki/Algorithme_d%27Aho-Corasick
