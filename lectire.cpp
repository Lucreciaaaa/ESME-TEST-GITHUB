#include <iostream>
#include <fstream>
#include <string>
#include <conio.h>
#include <string.h>
#include <stdio.h>
#include <windows.h>
#include <time.h>
using namespace std;

int main(){
    cout<<"The A-Maze-Ing Maze \n";
    cout<<"\n";
    int x = 0;
    int y = 0;
    char ch;

  ifstream fichier("Lab.txt");  //ouverture du fichier (contenant le labyrinthe) en mode lecture

 if(fichier)
    {
      //L'ouverture s'est bien passée, on peut donc lire

    string ligne; //Une variable pour stocker les lignes lues

    fstream fin("Lab.txt", fstream::in);  //Ouverture du même fichier en mode lecture et écriture

    while(getline(fichier, ligne)) //Tant qu'on n'est pas à la fin, on lit
     {
        y = y + 1;
     }

    while (fin >> noskipws >> ch)
     {
        x = x+1;
     }

     x /=y;
     //cout << "x=" << x << endl;    // x représente le nombre de colonnes
     //cout << "y=" << y << endl;    // y représente le nombre de lignes

     ifstream fichier1("Lab.txt");

     fstream fin1("Lab.txt", fstream::in);

    char matrice[x][y] = {""};     // tableau de y lignes et x colonnes contenant des caractères

    int i=0;
    int j=0;
    while (fin1 >> noskipws >> ch)
    {
        if(i == x)
        {
            j=j+1;
            i=0;
        }
        else if(ch == 'E')
        {
            matrice[i][j] = '.';
            i+=1;
        }
        else
        {
            matrice[i][j] = ch;
            i+=1;
        }

    }

    bool Victoire = FALSE;
    int a=1;
    int b=0;
    char gauche = matrice[a][b-1]; //q        z
    char droite = matrice[a][b+1]; //d      q s d
    char haut = matrice[a-1][b];   //z
    char bas = matrice[a+1][b];    //s

    for ( int i = 0; i < y; i++ )
    {
        for ( int j = 0; j < x; j++ )
        {
            printf("%c", matrice[j][i]);
        }
    printf("\n");
    }

    while(victoire == FALSE)
    {

    matrice[a][b]=' ';
        if(gauche==' ' || droite==' ' || haut==' ' || bas==' '){
            char pos;
            char z;
            char s;
            char q;
            char d;

        else printf("Je rentre pas dans le if \n");

        system("cls");
        for ( int i = 0; i < y; i++ )
        {
            for ( int j = 0; j < x; j++ )
            {
                printf("%c", matrice[j][i]);
            }
        printf("\n");
        }

        p=p+1;

    }
}
    else
    {
        cout << "ERREUR: Impossible d'ouvrir le fichier en lecture." << endl;
    }
    return 0;
}
