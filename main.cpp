#include <iostream>
#include <fstream>
#include <string>
#include <conio.h>
#include <string.h>
#include <iostream>
#include <stdio.h>
#include <windows.h>
#include <time.h>
using namespace std;

int main(){


    int x = 0;
    int y = 0;
    char ch;


  ifstream fichier("Lab.txt");  // ouverture du fichier (contenant le labyrinthe) en mode lecture





 if(fichier){
      //L'ouverture s'est bien passée, on peut donc lire



    string ligne; //Une variable pour stocker les lignes lues







    fstream fin("Lab.txt", fstream::in);  // Ouverture du même fichier en mode lecture et écriture



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
    while (fin1 >> noskipws >> ch) {

    //cout<<matrice[i][j];
    //printf("%c : %d\n", ch, ch);
        if(ch == 10){
              j=j+1;
              i=0;

        } else {
            //printf("%c : %d\n", ch, ch);
            matrice[i][j] = ch;
            i+=1;
        }

    }



    int p=0;
    int a=1;
    int b=0;
    char gauche=matrice[a][b-1]; //q        z
    char droite=matrice[a][b+1]; //d      q s d
    char haut=matrice[a-1][b];   //z
    char bas=matrice[a+1][b];    //s

     //Start a=1;b=0
        matrice[a][0]='.';
        for(i=0;i<=x-2;i++){
                for(j=0;j<=y-1;j++){
                    //cout<<"i="<<i<<"j="<<j;
                    printf("%c", matrice[i][j]);
            }
        printf("\n");}
         //Fin Start

    while(p<4){ /////////////////////// Mon a et mon b n'avancent pas or je fais += et -= //////////////////

    //cout<<"gauche="<<gauche
        //<<"droite="<<droite
        //<<"haut="<<haut
        //<<"bas="<<bas;
    printf("%c : %d\n", gauche, gauche);
    printf("%c : %d\n", droite, droite);
    printf("%c : %d\n", haut, haut);
    printf("%c : %d\n", bas, bas);

    matrice[a][b]=' ';
        if(gauche==' ' || droite==' ' || haut==' ' || bas==' '){
            char pos;
            char z;
            char s;
            char q;
            char d;
            cin>>pos;printf("%c : %d\n",pos);
            if(pos=='z' && haut==' '){
                a-=1;
                matrice[a][b]='.';

            }
            if(pos=='s' && bas==' '){
                a+=1;
                matrice[a][b]='.';
            }
            if(pos=='q' && gauche==' '){
                b-=1;
                matrice[a][b]='.';
            }
            if(pos=='d' && droite==' '){
                d+=1;
                matrice[a][b]='.';
            }

        }
        else printf("Je rentre pas dans le if \n");

        for(i=0;i<=x-2;i++){
            for(j=0;j<=y-1;j++){
                //cout<<"i="<<i<<"j="<<j;
                printf("%c", matrice[i][j]);
            }
        printf("\n");
        }

        p=p+1;



    }




}



    else{
        cout << "ERREUR: Impossible d'ouvrir le fichier en lecture." << endl;
    }



    return 0;
}
