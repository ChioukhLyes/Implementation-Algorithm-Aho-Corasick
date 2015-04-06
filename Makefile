#/***************************/
#/* Algorithmique du texte */
#/*************************/
#/* Fichier : ac-matrice */
#/***********************/
#/**********************/
#/*   CHIOUKH LYES    */
#/********************/
#/*******************/
#/*________________*/

CFLAGS = -Wall -ansi

#Emplacement des différents fichiers
SRC = sources
INC = includes
RES = ressources
BIN = binaries
OBJ = objects

# Point de départ
Projet : $(BIN)/ac-matrice.exe $(BIN)/ac-listes.exe $(BIN)/ac-mixte.exe $(BIN)/genere-texte.exe $(BIN)/genere-mots.exe 


# Les binairies

$(BIN)/ac-matrice.exe : $(OBJ)/ac-matrice.o 
	gcc -o $(BIN)/ac-matrice.exe $(OBJ)/ac-matrice.o
	
$(BIN)/ac-listes.exe : $(OBJ)/ac-listes.o 
	gcc -o $(BIN)/ac-listes.exe $(OBJ)/ac-listes.o
	
$(BIN)/ac-mixte.exe : $(OBJ)/ac-mixte.o 
	gcc -o $(BIN)/ac-mixte.exe $(OBJ)/ac-mixte.o
	
$(BIN)/genere-texte.exe : $(OBJ)/genere-texte.o
	gcc -o $(BIN)/genere-texte.exe $(OBJ)/genere-texte.o

$(BIN)/genere-mots.exe : $(OBJ)/genere-mots.o
	gcc -o $(BIN)/genere-mots.exe $(OBJ)/genere-mots.o

# Les objects

$(OBJ)/ac-matrice.o : $(SRC)/ac-matrice.c
	gcc  $(CFLAGS) -c -o $(OBJ)/ac-matrice.o $(SRC)/ac-matrice.c  -I$(INC)


$(OBJ)/ac-listes.o : $(SRC)/ac-listes.c
	gcc  $(CFLAGS) -c -o  $(OBJ)/ac-listes.o $(SRC)/ac-listes.c -I$(INC)
	
$(OBJ)/ac-mixte.o : $(SRC)/ac-mixte.c
	gcc  $(CFLAGS) -c -o $(OBJ)/ac-mixte.o $(SRC)/ac-mixte.c -I$(INC)
	

$(OBJ)/genere-texte.o : $(SRC)/genere-texte.c
	gcc  $(CFLAGS) -c -o $(OBJ)/genere-texte.o  $(SRC)/genere-texte.c  -I$(INC)


$(OBJ)/genere-mots.o : $(SRC)/genere-mots.c
	gcc $(CFLAGS) -c -o $(OBJ)/genere-mots.o $(SRC)/genere-mots.c  -I$(INC)

# Supprimer les fichiers intermédiaires 
clean : 
	rm -f  $(OBJ)/*.o $(BIN)/* *~

# On aurait pu utiliser les variables internes :
# $@
# $^
# $<
#############################################################################################################################
#############################################################################################################################
