#include <iostream>
#include <fstream>
#include <string>
#include <conio.h>
#include <string.h>
#include <stdio.h>
#include <windows.h>
#include <time.h>
using namespace std;

int plateau(string nom_fichier)
{
    int x = 0;
    int y = 0;
    char ch;

    ifstream fichier(nom_fichier);  //ouverture du fichier (contenant le labyrinthe) en mode lecture

 if(fichier)
    {
      //L'ouverture s'est bien passée, on peut donc lire

    string ligne; //Une variable pour stocker les lignes lues

    fstream fin(nom_fichier, fstream::in);  //Ouverture du même fichier en mode lecture et écriture

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

     ifstream fichier1(nom_fichier);

     fstream fin1(nom_fichier, fstream::in);

    char matrice[x][y] = {""};     // tableau de y lignes et x colonnes contenant des caractères

    int i=0;
    int j=0;
    int iE=0;
    int jE=0;
    int iEperm=0;
    int jEperm=0;

    //Création de la matrice qui sera le plateau de jeu
    //(servira pour les divers modifications et déplacements du personnage)
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
            iE = i;
            jE = j;
            iEperm = i;
            jEperm = j;
            i+=1;
        }
        else
        {
            matrice[i][j] = ch;
            i+=1;
        }

    }

    bool victoire = FALSE;
    int p=0;

    //Première Impression de la map
    system("cls");
    cout<<"LE LABORATOIRE DE MORBIUS\n";
    cout<<"THE A-MAZE-ING MAZE\n\n";
    for ( int i = 0; i < y; i++ )
    {
        for ( int j = 0; j < x; j++ )
        {
            printf("%c", matrice[j][i]);
        }
    printf("\n");
    }

    //Lancement de la boucle du jeu
    while(victoire == FALSE)
    {
        char pos;

        pos = getch();
        if(pos=='z')
        {
            jE-=1;
            if(matrice[iE][jE] == ' ')
            {
                matrice[iE][jE+1]=' ';
                matrice[iE][jE]='.';
            }
            else if(matrice[iE][jE] == '#')
            {
                jE+=1;
            }
            else if(matrice[iE][jE] == 'S')
            {
                matrice[iE][jE+1]=' ';
                matrice[iE][jE]='.';
                victoire = TRUE;
            }
            else if(matrice[iE][jE] == 'X')
            {
                matrice[iE][jE+1]=' ';
                iE = iEperm;
                jE = jEperm;
                matrice[iE][jE]='.';
            }
        }
        if(pos=='s')
        {
            jE+=1;
            if(matrice[iE][jE] == ' ')
            {
                matrice[iE][jE-1]=' ';
                matrice[iE][jE]='.';
            }
            else if(matrice[iE][jE] == '#')
            {
                jE-=1;
            }
            else if(matrice[iE][jE] == 'S')
            {
                matrice[iE][jE-1]=' ';
                matrice[iE][jE]='.';
                victoire = TRUE;
            }
            else if(matrice[iE][jE] == 'X')
            {
                matrice[iE][jE-1]=' ';
                iE = iEperm;
                jE = jEperm;
                matrice[iE][jE]='.';
            }
        }
        if(pos=='q')
        {
            iE-=1;
            if(matrice[iE][jE] == ' ')
            {
                matrice[iE+1][jE]=' ';
                matrice[iE][jE]='.';
            }
            else if(matrice[iE][jE] == '#')
            {
                iE+=1;
            }
            else if(matrice[iE][jE] == 'S')
            {
                matrice[iE+1][jE]=' ';
                matrice[iE][jE]='.';
                victoire = TRUE;
            }
            else if(matrice[iE][jE] == 'X')
            {
                matrice[iE+1][jE]=' ';
                iE = iEperm;
                jE = jEperm;
                matrice[iE][jE]='.';
            }
        }
        if(pos=='d')
        {
            iE+=1;
            if(matrice[iE][jE] == ' ')
            {
                matrice[iE-1][jE]=' ';
                matrice[iE][jE]='.';
            }
            else if(matrice[iE][jE] == '#')
            {
                iE-=1;
            }
            else if(matrice[iE][jE] == 'S')
            {
                matrice[iE-1][jE]=' ';
                matrice[iE][jE]='.';
                victoire = TRUE;
            }
            else if(matrice[iE][jE] == 'X')
            {
                matrice[iE-1][jE]=' ';
                iE = iEperm;
                jE = jEperm;
                matrice[iE][jE]='.';
            }
        }

        /*else
        {
            printf("Une erreur est apparue dans le programme \n");
        }*/

        //Imprime la map avec les modifications
        system("cls");
        cout<<"LE LABORATOIRE DE MORBIUS\n";
        cout<<"THE A-MAZE-ING MAZE\n\n";
        for ( int i = 0; i < y; i++ )
        {
            for ( int j = 0; j < x; j++ )
            {
                printf("%c", matrice[j][i]);
            }
        printf("\n");
        }
    }
    system("cls");
    }
    else
    {
        cout << "ERREUR: Impossible d'ouvrir le fichier en lecture." << endl;
    }
    return 0;
}

int main()
{
    cout<<"          _      ______   _               ____   ____  _____         _______ ____ _____ _____  ______            \n";
    cout<<"         | |    |  ____| | |        /\\   |  _ \\ / __ \\|  __ \\     /\\|__   __/ __ \\_   _|  __ \\|  ____|    \n";
    cout<<"         | |    | |__    | |       /  \\  | |_) | |  | | |__) |   /  \\  | | | |  | || | | |__) | |__            \n";
    cout<<"         | |    |  __|   | |      / /\\ \\ |  _ <| |  | |  _  /   / /\\ \\ | | | |  | || | |  _  /|  __|         \n";
    cout<<"         | |____| |____  | |____ / ____ \\| |_) | |__| | | \\ \\  / ____ \\| | | |__| || |_| | \\ \\| |____      \n";
    cout<<"         |______|______|_|______/_/   _\\_\\____/_\\____/|_|  \\_\\/_/____\\_\\_| _\\____/_____|_|  \\_\\______| \n";
    cout<<"                     |  __ \\|  ____| |  \\/  |/ __ \\|  __ \\|  _ \\_   _| |  | |/ ____|                        \n";
    cout<<"                     | |  | | |__    | \\  / | |  | | |__) | |_) || | | |  | | (___                              \n";
    cout<<"                     | |  | |  __|   | |\\/| | |  | |  _  /|  _ < | | | |  | |\\___ \\                           \n";
    cout<<"                     | |__| | |____  | |  | | |__| | | \\ \\| |_) || |_| |__| |____) |                           \n";
    cout<<"                     |_____/|______| |_|  |_|\\____/|_|  \\_\\____/_____|\\____/|_____/                          \n";
    cout<<"\n\n\n\n\n\n";
    cout<<"                              BIENVENUE DANS LE LABORATOIRE DE MORBIUS !!!                                     \n\n";
    cout<<"VOUS ALLEZ PARCOURIR PLUSIEURS LABYRINTHES AFIN DE VOUS ENFUIR DU LABORATOIRE DE MORBIUS LE SCIENTIFIQUE FOU!!!";
    getch();

    plateau("Lab.txt");

    cout<<"          _      ______   _               ____   ____  _____         _______ ____ _____ _____  ______            \n";
    cout<<"         | |    |  ____| | |        /\\   |  _ \\ / __ \\|  __ \\     /\\|__   __/ __ \\_   _|  __ \\|  ____|    \n";
    cout<<"         | |    | |__    | |       /  \\  | |_) | |  | | |__) |   /  \\  | | | |  | || | | |__) | |__            \n";
    cout<<"         | |    |  __|   | |      / /\\ \\ |  _ <| |  | |  _  /   / /\\ \\ | | | |  | || | |  _  /|  __|         \n";
    cout<<"         | |____| |____  | |____ / ____ \\| |_) | |__| | | \\ \\  / ____ \\| | | |__| || |_| | \\ \\| |____      \n";
    cout<<"         |______|______|_|______/_/   _\\_\\____/_\\____/|_|  \\_\\/_/____\\_\\_| _\\____/_____|_|  \\_\\______| \n";
    cout<<"                     |  __ \\|  ____| |  \\/  |/ __ \\|  __ \\|  _ \\_   _| |  | |/ ____|                        \n";
    cout<<"                     | |  | | |__    | \\  / | |  | | |__) | |_) || | | |  | | (___                              \n";
    cout<<"                     | |  | |  __|   | |\\/| | |  | |  _  /|  _ < | | | |  | |\\___ \\                           \n";
    cout<<"                     | |__| | |____  | |  | | |__| | | \\ \\| |_) || |_| |__| |____) |                           \n";
    cout<<"                     |_____/|______| |_|  |_|\\____/|_|  \\_\\____/_____|\\____/|_____/                          \n";
    cout<<"\n\n\n\n\n\n";
    cout<<"                              VOUS AVEZ REUSSI A PARCOURIR LE LABYRINTHE                                         \n";
    cout<<"                            VOULEZ VOUS VOUS RENDRE AU PROCHAIN NIVEAU ? Y/N                                    \n";
    char choix;
    choix = getch();
    if(choix == 'y')
    {
        plateau("Barb.txt");

        cout<<"          _      ______   _               ____   ____  _____         _______ ____ _____ _____  ______            \n";
        cout<<"         | |    |  ____| | |        /\\   |  _ \\ / __ \\|  __ \\     /\\|__   __/ __ \\_   _|  __ \\|  ____|    \n";
        cout<<"         | |    | |__    | |       /  \\  | |_) | |  | | |__) |   /  \\  | | | |  | || | | |__) | |__            \n";
        cout<<"         | |    |  __|   | |      / /\\ \\ |  _ <| |  | |  _  /   / /\\ \\ | | | |  | || | |  _  /|  __|         \n";
        cout<<"         | |____| |____  | |____ / ____ \\| |_) | |__| | | \\ \\  / ____ \\| | | |__| || |_| | \\ \\| |____      \n";
        cout<<"         |______|______|_|______/_/   _\\_\\____/_\\____/|_|  \\_\\/_/____\\_\\_| _\\____/_____|_|  \\_\\______| \n";
        cout<<"                     |  __ \\|  ____| |  \\/  |/ __ \\|  __ \\|  _ \\_   _| |  | |/ ____|                        \n";
        cout<<"                     | |  | | |__    | \\  / | |  | | |__) | |_) || | | |  | | (___                              \n";
        cout<<"                     | |  | |  __|   | |\\/| | |  | |  _  /|  _ < | | | |  | |\\___ \\                           \n";
        cout<<"                     | |__| | |____  | |  | | |__| | | \\ \\| |_) || |_| |__| |____) |                           \n";
        cout<<"                     |_____/|______| |_|  |_|\\____/|_|  \\_\\____/_____|\\____/|_____/                          \n";
        cout<<"\n\n\n\n\n\n";
        cout<<"                              VOUS AVEZ REUSSI A PARCOURIR LE LABYRINTHE                                         \n";
        cout<<"                            VOULEZ VOUS VOUS RENDRE AU PROCHAIN NIVEAU ? Y/N                                    \n";
        char choix;
        choix = getch();
        if(choix == 'y')
        {
            cout<<"Pas encore de prochain niveau";
        }
    }
}
