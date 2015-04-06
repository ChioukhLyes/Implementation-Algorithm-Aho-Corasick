/***************************/
/* Algorithmique du texte */
/*************************/
/* Fichier : ac-listes  */
/***********************/
/**********************/
/*   CHIOUKH LYES    */
/********************/
/*******************/
/*________________*/

#include "all.h"

/* Définition du type de trie a utiliser */
typedef struct _trieListes *Trie;

/*****************************************************************************/
/*               Chercher noeud qui contient notre lettre                    */
/*****************************************************************************/
int chercher_noeud(List list, unsigned char l) {
List temp = list;
while (temp != NULL) {
if (temp->letter == l) {
return temp->targetNode;
}
temp = temp->next;
}return -1; /* Lettre non trouvée */}

/*****************************************************************************/
/*               Insertion d'un nouveau noeud                                */
/*****************************************************************************/
void nouveau_noeud(List *ma_list, unsigned char c, int noeud) {
List temp = (List)malloc(sizeof(struct _list));
temp->letter = c;	
temp->targetNode = noeud;
/*Insertion au debut*/
temp->next = *ma_list;
*ma_list = temp;
}

/*****************************************************************************/
/*             Utilisation d'une file (pour les etats de supp)               */
/*****************************************************************************/
Queue createQueue() {
/* Allocation de mémoire */
Queue ma_queue = (Queue)malloc(sizeof(struct _queue));
ma_queue->debut = NULL;
ma_queue->fin = NULL;
ma_queue->taille = 0;
return ma_queue;
}

/*****************************************************************************/
/*                    Insertion dans une file                                */
/*****************************************************************************/
void insertQueue(Queue ma_queue, int valeur) {
if (ma_queue->taille == 0) {
/* Queue vide */
ma_queue->fin = (Element)malloc(sizeof(struct _element));
ma_queue->fin->valeur = valeur;
ma_queue->fin->prochain = NULL;
ma_queue->debut = ma_queue->fin;
} 
else {
/* Queue non vide */
ma_queue->fin->prochain = (Element)malloc(sizeof(struct _element));
ma_queue->fin->prochain->valeur = valeur;
ma_queue->fin->prochain->prochain = NULL;
ma_queue->fin = ma_queue->fin->prochain;
}
ma_queue->taille =ma_queue->taille + 1;
}

/*****************************************************************************/
/*                    Récupération de valeur d'une file                      */
/*****************************************************************************/
int recupQueue(Queue ma_queue) {
if (ma_queue->taille == 0) { return -1; /*Queue vide*/}
int valeur = ma_queue->debut->valeur;
ma_queue->debut = ma_queue->debut->prochain;
/*Décrémenter la taille dela file*/
ma_queue->taille = ma_queue->taille - 1;
return valeur;
}

/*****************************************************************************/
/*                            Création du trie                               */
/*****************************************************************************/
Trie createTrie(int maxNode) {
int i;
/* Allocations nécessaires */
Trie mon_trie = (Trie)malloc(sizeof(struct _trieListes));
mon_trie->transition = (List *)malloc(maxNode * sizeof(struct _list));
mon_trie->mon_suppl = (int *)malloc(maxNode * sizeof(int));
mon_trie->finite = (char *)malloc(maxNode * sizeof(char));
/* Initialisations */
mon_trie->maxNode = maxNode;
mon_trie->nextNode = 1;
for (i = 0; i < maxNode; i++) {
mon_trie->mon_suppl[i] = -1; /* Initialiser les etats de suppléance */ 
mon_trie->finite[i] = 0; /* Tous les etats sont non terminaux */
}
/* retourner le trie*/
return mon_trie;
}

/*****************************************************************************/
/*                           Insertion dans le trie                          */
/*****************************************************************************/
void insertTrie(Trie mon_trie, unsigned char *w) {
int j=0;
int i=0;
int noeud_courant = 0;
int temp;

/* Récupération de la taille du mot */
while (w[j] != '\0') {j=j+1;}

int taille_mot = j;

/* debut insertion */
while (w[i] != '\0') {
temp = chercher_noeud(mon_trie->transition[noeud_courant], w[i]);
if (temp == -1) {

/* Vérifier la possibilité de l'insertion (l'espace)*/
if (taille_mot - i > mon_trie->maxNode - mon_trie->nextNode) {
return; /* Quitter */
}
/* Insertion du mot */
while (w[i] != '\0') {
List temp1 = (List)malloc(sizeof(struct _list));
temp1->targetNode = mon_trie->nextNode;
temp1->letter = w[i];
temp1->next = mon_trie->transition[noeud_courant];
mon_trie->transition[noeud_courant] = temp1;
noeud_courant = mon_trie->nextNode;
mon_trie->nextNode = mon_trie->nextNode + 1;
i=i+1;
}
} else {
noeud_courant = temp;
}
i= i+1;
}	
/* Dernier noeud commme terminal */
mon_trie->finite[noeud_courant] = 1;

}

/*****************************************************************************/
/*           Completer la racine (les transitions vers la racine)            */
/*****************************************************************************/
void completer_trie(Trie trie) {
/* Récuperer la liste de la racine */
List list = trie->transition[0];
int i;
for (i = 0; i < 256; i++) {
/* 256 : caractéres non signés */
if (chercher_noeud(list, i) == -1) {
nouveau_noeud(&list, i, 0);
}}}

/*****************************************************************************/
/*                  Rechercher et retourner les transitions                  */
/*****************************************************************************/

Trans avoirTrans(Trie trie,  int ISRoot, int origine) {
int isRoot;

if (ISRoot) {isRoot = -1;} else {isRoot = 0;}
/* Transitions qui va contenir le resultat (Initialisation obligatoire)*/
Trans trans = NULL;
List ma_list = trie->transition[origine];
/* Récuperer et ajouter toute les transitions de la liste */
while (ma_list != NULL) {
if (ma_list->targetNode > isRoot) {
Trans tmp = (Trans)malloc(sizeof(struct _transition));
tmp->vers = ma_list->targetNode;
tmp->origine = origine;
tmp->prochain = trans;
tmp->letter = ma_list->letter;
trans = tmp;
ma_list = ma_list->next;
}}
return trans;
}

/*****************************************************************************/
/*        Chercher et retourner le 'vers' d'une transition                   */
/*****************************************************************************/
int chercher_vers(Trie trie, int org, unsigned char c) {
if (org == -1) {return 0;}
List list = trie->transition[org]; /* Récupération de la liste */
return chercher_noeud(list, c);    /* Retourner la destination */
}

/*****************************************************************************/
/*                     Les etapes de l'algorithmes AC                        */
/*****************************************************************************/

/*****************************************************************************/
/*                                Completer                                  */
/*****************************************************************************/

void complete(Trie trie) {
unsigned char c;
int org=0, vers=0, s=0;
	
/* Création de la file */
Queue queue = createQueue();
/* Avoir les transition de la racine */
Trans transitions = avoirTrans(trie, 0, 0);
/* Fonction de supp pour les fils de la racine 'sons of the root '*/
while (transitions != NULL) {
vers = transitions->vers;
transitions = transitions->prochain;
/* inserer dans la file */
insertQueue(queue, vers);
/* Destination = racine*/
trie->mon_suppl[vers] = 0;
}
/* Récupérer les elements a partir de la file, et exectuer la fonction de supp */
while (queue->taille != 0) {
org = recupQueue(queue);
transitions = avoirTrans(trie, 1, org);
while (transitions != NULL) {
org = transitions->origine;
c = transitions->letter;
vers = transitions->vers;
transitions = transitions->prochain;
insertQueue(queue, vers);

s = trie->mon_suppl[org];
/* Transition non définie */
while (chercher_vers(trie, s, c) == -1) {
s = trie->mon_suppl[s];
}
trie->mon_suppl[vers] = chercher_vers(trie, s, c);
/* Fonction de sortie */
if (trie->finite[trie->mon_suppl[vers]]) {
trie->finite[vers] = 1;}}}}

/*****************************************************************************/
/*                                Pre-AC                                     */
/*****************************************************************************/

Trie preAC(unsigned char **mots, int nb_max) {
/* Création de l'etat q0 et du trie */
Trie trie = createTrie(nb_max * 60);
/* Taille max d'un mot  = 60 */
int i;
/* Inserer dans le trie */
for (i = 0; i < nb_max; i++) {insertTrie(trie, mots[i]);}
/* Completer la racine */
completer_trie(trie);
/* Completer avec les supps*/
complete(trie);
/* return */
return trie;
}

/*****************************************************************************/
/*                                Aho-Corasick                               */
/*****************************************************************************/

void ahoCorasick(unsigned char **mots, int nb_max, unsigned char *texte, long int texte_taille) {
int org = 0, occ = 0, i=0;
/* Création du trie */	
Trie trie = preAC(mots, nb_max);
/* Testerla création du trie */
if (trie == NULL) {return; /* Quitter */}
/* phase de recherche */
for (i = 0; i < texte_taille; i++) {
/* S'il n'existe pas de desitnation on cherche le supp */
while (chercher_vers(trie, org, texte[i]) == -1) {
org = trie->mon_suppl[org];
}
org = chercher_vers(trie, org, texte[i]);
/* si etat final ? alors incrémenter occ */
if (trie->finite[org]) {
occ = occ + 1;}}
printf("\nLe nombre total de mots trouvés dans le texte est %d\n", occ);
}

/*****************************************************************************/
/*                               Main                                        */
/*****************************************************************************/
int main(int argc, char **argv) {
/* Déclaration du clock */
clock_t debut;
clock_t fin;

char *Fichier_texte = (char *)malloc(40 * sizeof(char));
unsigned char * mon_text = (unsigned char *)malloc(5000000 * sizeof(unsigned char));
char *Fichier_mots = (char *)malloc(40 * sizeof(char));
unsigned char **mes_mots = (unsigned char **)malloc(100 * sizeof(unsigned char *));
int j, c;
long int i;

/* Utilisation des paramétres lors de l'exécution */
if (argc == 3){
if(strcpy(Fichier_texte, argv[1])==NULL) {printf("Impossible de trouver  le fichier contenant le texte\n");}
if(strcpy(Fichier_mots, argv[2])==NULL){printf("Impossible de trouver le fichier contenant les mots\n");}
} 
else{

/* L'utilisateur ne donne pas de paramétres  */
printf("Veuillez donner le nom du fichier qui contient le texte  :\n");
if (scanf("%s", Fichier_texte) == 0) {printf("Impossible de trouver le fichier contenant le texte\n"); return -1;}

printf("Entrez le nom du fichier contenant les mots a rechercher :\n");
if (scanf("%s", Fichier_mots) == 0) {printf("Impossible de trouver le fichier contenant les mots\n"); return -1;}
}
/* Ouverture des fichiers Fichier_texte et Fichier_mots en mode lecture */
FILE * texte_fichier = fopen(Fichier_texte, "r");
FILE * mots_fichier = fopen(Fichier_mots, "r");

/* Récuperer le texte dans une variable */
for (i = 0; i < 5000000; i++) {
mon_text[i] = fgetc(texte_fichier);
}

/* Récupération de la liste des mots */
for (i = 0; i < 100; i++) {
mes_mots[i] = (unsigned char *)malloc(60 * sizeof(unsigned char));
j = 0;
c = fgetc(mots_fichier);
while (c != '\n') {
mes_mots[i][j] = c;
c = fgetc(mots_fichier);
j = j+1;
}}
 
/* Debut de calcule du temps d'exécution */
debut = clock();
ahoCorasick(mes_mots, 100, mon_text, 5000000);
fin = clock();

/* Fin de calcule du temps d'exécution */
printf("**************************************************\n");
printf("Vous avez exécuté l'algorithme de recherche Aho-Corasick.\n");
printf("**************************************************\n");
printf("La structure utilisée pour representer le trie : 'Tableau de listes d'adjacence'.\n");
printf("**************************************************\n");
printf("Le fichier qui contient le texte est : %s.\n",Fichier_texte );
printf("**************************************************\n");
printf("Le fichier qui contient l'ensemble des mots est : %s.\n",Fichier_mots );
printf("******************      Temps    *****************\n");
printf("Le temp d'exécution de cette recherche est : %f seconde(s)...\n", (double) (fin - debut) / CLOCKS_PER_SEC);
printf("**************************************************\n");

/* Fermer les fichiers */
fclose(mots_fichier);
fclose(texte_fichier);

return 0;
}
/*Fin*/
