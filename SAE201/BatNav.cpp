
/* PROJET PHASE 1 SAE 201 SANS INTERFACE GRAPHIQUE*/
/* MATHEO KILIAN ALBAN*/
/* CHANGER L'ENCODAGE EN UTF-8 */


//------------------------------------------------------------------------------------------//

// COMMANDE
#include <iostream>
#include <ctime>
#include <stdlib.h>
using namespace std;

//------------------------------------------------------------------------------------------//


//------------------------------------------------------------------------------------------//

// variable constante définissant les lignes et colonnes 
// à modifier si besoin 
const int ligne = 7;
const int colonne = 7;
int MaxBat = 5;

//------------------------------------------------------------------------------------------//


//------------------------------------------------------------------------------------------//

// grille de jeux 
int matrix[ligne][colonne];

//------------------------------------------------------------------------------------------//

// a enlever en cas de besoin 
void Clear()
{
    for (int i = 0; i < ligne; i++)
    {
        for (int j = 0; j < colonne; j++)
        {
            matrix[i][j] = 0;
        }
    }
}
//------------------------------------------------------------------------------------------//

// afficher dans la console la grille
void afficher()
{
    for (int i = 0; i < ligne; i++)
    {
        for (int j = 0; j < colonne; j++)
        {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

//------------------------------------------------------------------------------------------//

// fonction rand pour positionner aléatoirement les bateaux sur la grille
// a modifier pour placement manuel 
void PositionBat()
{
    int s = 0;
    while (s < MaxBat)
    {
        int x = rand() % ligne;
        int y = rand() % colonne;
        if (matrix[x][y] != 1)
        {
            s++;
            matrix[x][y] = 1;
        }
    }
}

//------------------------------------------------------------------------------------------//

// afficher dans la console le nombre de navire restant (incrémentation)
int NombreNav()
{
    int c = 0;
    for (int i = 0; i < ligne; i++)
    {
        for (int j = 0; j < colonne; j++)
        {
            if (matrix[i][j] == 1)
            {
                c++;
            }
        }
    }

    return c;
}

//------------------------------------------------------------------------------------------//


//------------------------------------------------------------------------------------------//

//gestion des attaques 
bool Attaque(int x, int y)
{
    if (matrix[x][y] == 1) // exception à lever 
    {
        matrix[x][y] = 2;
        return true;
    }

}

//------------------------------------------------------------------------------------------//


//  MAIN //


//------------------------------------------------------------------------------------------//

int main()
{
    srand(time(NULL));

    Clear();
    cout << "Bienvenue dans la bataille navale !  " << endl;
    afficher();
    cout << "-------------------------------- Bonne Chance --------------------------------" << endl;
    PositionBat();
    int pos1, pos2;

    char prompt;



    while (1)
    {

        cout << "Entrez un emplacement (ligne + colonne : 0 0) ";
        cin >> pos1 >> pos2;
        if (Attaque(pos1, pos2))
        {

        }
        else {

        }
        cout << "Nombre de navires restants : " << NombreNav() << endl;
        if (NombreNav() == 0) {
            break;
        }



    }

    cout << "Victoire ! " << endl;
    afficher();



    return 0;
}


//------------------------------------------------------------------------------------------//
