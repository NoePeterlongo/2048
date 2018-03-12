#include "plateau.h"
#include <iostream>
using namespace std;

Plateau::Plateau(int Taille = 4)
{
    taille = Taille;

    //allocation dynamique de la table et initialisation
    table = new int*[taille];
    for(int i = 0; i<taille; i++)
    {
        table[i] = new int[taille];
        for(int j = 0; j < taille; j++)
            table[i][j] = 0;
    }
}

bool Plateau::Set(int ligne, int colonne, int valeur)
{
    if(ligne>=taille || ligne<0 || colonne<0 || colonne>=taille)
        return false;

    table[ligne][colonne] = valeur;
}

bool Plateau::Mouvement(int mouvement)
{
    bool quelqueChoseAChange = false;

    switch(mouvement)
    {
    case HAUT:
        for(int col = 0; col<taille; col++)
        {
            bool continuer = true;

            //On commence par coller toutes les cases de la colonne vers le haut
            for(int i = 0; i<taille-1; i++)
            {
                //Pour chaque case nulle, on va chercher la premiere case non nulle qui la suit
                if(table[i][col]==0)
                    for(int j = i+1; j<taille; j++)
                        if(table[j][col] != 0)
                        {
                            Set(i,col, table[j][col]);
                            Set(j,col, 0);
                            break;
                        }
            }

            //maintenant on traite le tableau
            int ligne = 0;
            while(continuer)
            {
                if(ligne<taille-1 && table[ligne][col] != 0)
                {
                    if(table[ligne][col] != table[ligne+1][col])
                        ligne++;
                    else
                    {
                        quelqueChoseAChange = true;
                        Set(ligne, col, 2*table[ligne][col]);
                        Set(ligne+1, col, 0);

                        //Maintenant on colle toutes les cases vers le haut
                        for(int i = ligne+1; i<taille-1; i++)
                        {
                            //Pour chaque case, on va chercher la premiere case non nulle qui la suit
                            for(int j = i+1; j<taille; j++)
                                if(table[j][col] != 0)
                                {
                                    Set(i,col, table[j][col]);
                                    Set(j,col, 0);
                                    break;
                                }
                        }
                    }
                }
                else
                    continuer = false;
            }
        }
        break;
    }
    return quelqueChoseAChange;
}

void Plateau::Print()
{
    for (int i = 0; i<taille; i++)
    {
        for (int j = 0; j<taille; j++)
            cout<<table[i][j]<<" ";
        cout<<endl;
    }
}
