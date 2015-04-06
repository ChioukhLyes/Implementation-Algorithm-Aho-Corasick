/***************************/
/* Algorithmique du texte */
/*************************/
/* Fichier : genere-mots*/
/***********************/
/**********************/
/*   CHIOUKH LYES    */
/********************/
/*******************/
/*________________*/

#include "all.h"

/******************** Fontion qui génére les mots ***********************/

void generemots(int nombre_mot, int taille_min_mot, int taille_max_mot, int taille_alph) {
char nom[40];
int i, j, c, taille_mot;

/*Création d'un fichier */
sprintf(nom, "mot_taille%d-%d_alphabet%d.txt",taille_min_mot, taille_max_mot,taille_alph);
	
/*Ouverture du fichier en mode écriture 'w' */
FILE *mon_fichier = fopen(nom, "w");
	
/*Fonction randome pour générer des nombres aléatoires */
for (i = 0; i < nombre_mot; i++) {

/* Des tailles aléatoires pour l'ensemble des mots */
taille_mot = (int) (rand() % ((taille_max_mot - taille_min_mot)) + taille_min_mot);

/*Ecrire le mot dans le fichier*/
for (j = 0; j < taille_mot; j++) {

/*On commance par '48' car c'est le code du symbole '0' */
c = (int) (rand() % ((48 + taille_alph) - 48) + 48);
fputc(c, mon_fichier);
}

/*Séparation des mots par des sauts de lignes*/
fputc('\n', mon_fichier);

}
/*Fermeture du fichier*/
fclose(mon_fichier);
}

/******************** Main ***********************/

int main() {
int i, j;
int nombre_mots=100;
srand(time(NULL));
int longueur_mot[6] = {5, 15, 15, 30, 30, 60};
int tailles_alph[4] = {2, 4, 20, 70};
for (i = 0; i < 4; i++) {
for (j = 0; j < 3; j++) {
if(j==0){generemots(nombre_mots, longueur_mot[0], longueur_mot[1],tailles_alph[i]);}
if(j==1){generemots(nombre_mots, longueur_mot[2], longueur_mot[3],tailles_alph[i]);}
if(j==2){generemots(nombre_mots, longueur_mot[4], longueur_mot[5],tailles_alph[i]);}
}}return 0;}
/*Fin*/
