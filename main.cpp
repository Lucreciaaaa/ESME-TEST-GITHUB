#include <iostream>
#include <fstream>
#include <string>
#include <iostream>
using namespace std;

int main()
{
  ifstream fichier("Lab.txt");





 if(fichier)
    {
      //L'ouverture s'est bien passée, on peut donc lire



    string ligne; //Une variable pour stocker les lignes lues



    int x = 0;
     int y = 0;
     char ch;



    fstream fin("Lab.txt", fstream::in);



    while(getline(fichier, ligne)) //Tant qu'on n'est pas à la fin, on lit
     {
        y = y + 1;
     }



    while (fin >> noskipws >> ch)
     {
       x = x+1;
     }



    x = x/y;
     cout << x << endl;
     cout << y << endl;



   int matrice[x][y] = {};



   for (int i=0; i <= y; i++)
    {
      for (int j=0; j <= x; j++)
      {
        cout << matrice[i][j] << endl;
      }
    }
    }



 else
    {
      cout << "ERREUR: Impossible d'ouvrir le fichier en lecture." << endl;
    }



 return 0;
}

