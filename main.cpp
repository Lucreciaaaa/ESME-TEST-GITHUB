#include <iostream>
#include <fstream>
#include <string>
#include <string.h>
#include <iostream>
#include <stdio.h>
using namespace std;

int main(){


    int x = 0;
    int y = 0;
    char ch;


  ifstream fichier("Lab.txt");  // ouverture du fichier (contenant le labyrinthe) en mode lecture





 if(fichier){
      //L'ouverture s'est bien pass�e, on peut donc lire



    string ligne; //Une variable pour stocker les lignes lues







    fstream fin("Lab.txt", fstream::in);  // Ouverture du m�me fichier en mode lecture et �criture



    while(getline(fichier, ligne)) //Tant qu'on n'est pas � la fin, on lit
     {
        y = y + 1;
     }

    while (fin >> noskipws >> ch)
     {
       x = x+1;
     }


     x /=y;
     cout << "x=" << x << endl;    // x repr�sente le nombre de colonnes
     cout << "y=" << y << endl;    // y repr�sente le nombre de lignes


     ifstream fichier1("Lab.txt");


     fstream fin1("Lab.txt", fstream::in);


    char matrice[x][y] = {""};     // tableau de y lignes et x colonnes contenant des caract�res

    int i=0;
    int j=0;
    while (fin1 >> noskipws >> ch) {  // QUE FAIT L'OPERATEUR NOSKIPWS ?
        strcpy(&matrice[i][j], &ch);
cout<<matrice[i][j];
         i+=1;
        if(i==x){
              j=j+1;
              i=0;

        }

    }




 // collisions � l'int�rieur du labyrinthe + d�terminer la position de l'�toile

 for ( i = 0; i < y; i++ ) {
      for ( j = 0; j < x; j++ )

        {
            if (matrice[i][j] == '#') {      // si le pointeur tombe sur un mur, il s'arr�te
                break ;
                cout << "\nObstacle !" << "\n" << i << "\n" << j; }// obstacle � la ligne j et � la colonne i

            else { return i,j ;

            }
}

 }



}

 else{
      cout << "ERREUR: Impossible d'ouvrir le fichier en lecture." << endl;
}



 return 0;
 }

 // FERMER LE FICHIER
