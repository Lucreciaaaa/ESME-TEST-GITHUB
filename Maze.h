#ifndef MAZE_H
#define MAZE_H
#include <iostream>
#include <fstream>
#include <string>
#include <string.h>
#include <iostream>
#include <stdio.h>

using namespace std;

static const int LIGNE = 7;
static const int COLONNE = 14;

class Laby
{
public:
	Laby(); //Constructeur par défaut
	void printLaby(); //Imprimer laby
	void writeBlock(); //Ecrire les blocks dans le labyrinthe
	char getCell( int row, int col ); //Recuperer le contenue des cellules
	void setCell( int row, int col, char val ); //Définir le contenue des cellules

private:
	char laby[ LIGNE ][ COLONNE ];

}; //Fin de la classe Laby

#endif




