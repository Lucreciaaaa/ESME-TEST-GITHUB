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


  ifstream fichier("Lab.txt");





 if(fichier){
      //L'ouverture s'est bien passée, on peut donc lire



    string ligne; //Une variable pour stocker les lignes lues







    fstream fin("Lab.txt", fstream::in);



    while(getline(fichier, ligne)) //Tant qu'on n'est pas à la fin, on lit
     {
        y = y + 1;
     }

    while (fin >> noskipws >> ch)
     {
       x = x+1;
     }


     x /=y;
     cout << "x=" << x << endl;
     cout << "y=" << y << endl;


     ifstream fichier1("Lab.txt");


     fstream fin1("Lab.txt", fstream::in);


    char matrice[x][y] = {""};

    int i=0;
    int j=0;
    while (fin1 >> noskipws >> ch) {
        strcpy(&matrice[i][j], &ch);
        cout<<matrice[i][j];
        i+=1;
        if(i==x){
              j=j+1;
              i=0;
        }





    }





}



 else{
      cout << "ERREUR: Impossible d'ouvrir le fichier en lecture." << endl;
}



 return 0;
}

