/***************************/
/* Algorithmique du texte */
/*************************/
/* Fichier :genere-texte*/
/***********************/
/**********************/
/*   CHIOUKH LYES    */
/********************/
/*******************/
/*________________*/

#include "all.h"

/******************** Fontion qui génére un texte ***********************/

void genereTexte(int Taille_alph) {
char nom[40];
/* 'i'est un double */
double i;
int c;
 
/*Création d'un fichier */
sprintf(nom, "texte_alphabet_%d.txt", Taille_alph);

/*Ouverture du fichier en mode écriture 'w' */
FILE * mon_fichier = fopen(nom, "w");

/*Fonction randome pour générer des nombres aléatoires */
for (i = 0; i < 5000000; i++) {

/*utilisation de la fonction suivante pour rester dans les bornes */
/*On commance par '48' car c'est le code du symbole '0' */
c = (int) (rand() % ((48 + Taille_alph) - 48) + 48);

/*Ecrire dansle fichier */
fputc(c,mon_fichier);
}
/*Fermeture du fichier*/
fclose(mon_fichier);
}

/******************** Main ***********************/

int main() {
int i;
int tailles_alph[4] = {2, 4, 20, 70};
srand(time(NULL));
for (i = 0; i < 4; i++) {
genereTexte(tailles_alph[i]);
}return 0;}
/*Fin*/
