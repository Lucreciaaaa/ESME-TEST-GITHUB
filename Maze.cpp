#include <iostream>
#include "Maze.h"
using namespace std;

Laby::Laby() //Constructeur par defaut
{
	char def = ' ';
	for ( int i = 0; i < LIGNE; i++ ) //Boucle dans LIGNE
	{
		for (int j = 0; j < COLONNE; j++ ) //Boucle dans COLONNE de la LIGNE actuelle
		{
			//Definie les lignes et colonnes pour les cellules
			laby[ i ][ j ] = def;
		} //Fin de la boucle dans les colonnes
	} //Fin de la boucle dans les lignes
	writeBlock(); //Ecrit la positions des blocks dans le labyrinthe
} //Fin du constructeur par defaut

void Laby::printLaby()
{
	for ( int i = 0; i < LIGNE; i++ )
	{
		for ( int j = 0; j < COLONNE; j++ )
		{
			cout << "+---";
		}
		cout << "+" << endl;
		//Boucle dans COLONNE de la LIGNE actuelle
		for ( int j = 0; j < COLONNE; j++ )
		{
			cout << "| " << laby[ i ][ j ] << " ";
		}
		cout << "|" << endl; //Debute une nouvelle ligne de resultat
	}
	for ( int j = 0; j < COLONNE; j++ )
		{
			cout << "+---";
		}
		cout << "+" << endl;
} //Fin de la fonction printLaby()

//Fonction pour écrire les blocks dans le labyrinthe
void Laby::writeBlock()
{
    ifstream fich("Lab.txt");
    fstream f("Lab.txt", fstream::in);
    int i=0;
    int j=0;
    char ch;
    while (f >> noskipws >> ch)
    {
        laby[i][j] = ch;
        i += 1;
        if(i==COLONNE)
        {
              j = j+1;
              i = 0;
        }
    }
} //Fin de la fonction writeBlock

char Laby::getCell( int row, int col )
{
	char cell = laby[ row ][ col ];
	return cell;
} //Fin de la fonction getCell

void Laby::setCell( int ligne, int colonne, char val )
{
	laby[ ligne ][ colonne ] = val;
} //Fin de la fonction setCell




