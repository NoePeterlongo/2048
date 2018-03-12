#include "plateau.h"
#include <iostream>
#include <stdlib.h>
#include <time.h>
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

Plateau::Plateau(const Plateau &autrePlateau)
{
    taille = autrePlateau.taille;

    //allocation dynamique de la table et initialisation
    table = new int*[taille];
    for(int i = 0; i<taille; i++)
    {
        table[i] = new int[taille];
        for(int j = 0; j < taille; j++)
            table[i][j] = autrePlateau.table[i][j];
    }
}

bool Plateau::Set(int ligne, int colonne, int valeur)
{
    if(ligne>=taille || ligne<0 || colonne<0 || colonne>=taille)
        return false;

    table[ligne][colonne] = valeur;
    return true;
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
                        //On recommence à la première ligne
                        ligne = 0;
                    }
                }
                else
                    continuer = false;
            }
        }
        break;

    case BAS:
        for(int col = 0; col<taille; col++)
        {
            bool continuer = true;

            //On commence par coller toutes les cases de la colonne vers le bas
            for(int i = taille-1; i>=1; i--)
            {
                //Pour chaque case nulle, on va chercher la premiere case non nulle qui la 'suit'
                if(table[i][col]==0)
                    for(int j = i-1; j>=0; j--)
                        if(table[j][col] != 0)
                        {
                            Set(i,col, table[j][col]);
                            Set(j,col, 0);
                            break;
                        }
            }

            //maintenant on traite le tableau
            int ligne = taille-1;
            while(continuer)
            {
                if(ligne>=1 && table[ligne][col] != 0)
                {
                    if(table[ligne][col] != table[ligne-1][col])
                        ligne--;
                    else
                    {
                        quelqueChoseAChange = true;
                        Set(ligne, col, 2*table[ligne][col]);
                        Set(ligne-1, col, 0);

                        //Maintenant on colle toutes les cases vers le bas
                        for(int i = ligne-1; i>=1; i--)
                        {
                            //Pour chaque case, on va chercher la premiere case non nulle qui la suit
                            for(int j = i-1; j>=0; j--)
                                if(table[j][col] != 0)
                                {
                                    Set(i,col, table[j][col]);
                                    Set(j,col, 0);
                                    break;
                                }
                        }
                        ligne = taille-1;
                    }
                }
                else
                    continuer = false;
            }
        }
        break;

    case GAUCHE:
        for(int li = 0; li<taille; li++)
        {
            bool continuer = true;

            //On commence par coller toutes les cases de la ligne vers la gauche
            for(int i = 0; i<taille-1; i++)
            {
                //Pour chaque case nulle, on va chercher la premiere case non nulle qui la suit
                if(table[li][i]==0)
                    for(int j = i+1; j<taille; j++)
                        if(table[li][j] != 0)
                        {
                            Set(li,i, table[li][j]);
                            Set(li,j, 0);
                            break;
                        }
            }

            //maintenant on traite le tableau
            int colonne = 0;
            while(continuer)
            {
                if(colonne<taille-1 && table[li][colonne] != 0)
                {
                    if(table[li][colonne] != table[li][colonne + 1])
                        colonne++;
                    else
                    {
                        quelqueChoseAChange = true;
                        Set(li, colonne, 2*table[li][colonne]);
                        Set(li, colonne+1, 0);

                        //Maintenant on colle toutes les cases vers la gauche
                        for(int i = colonne+1; i<taille-1; i++)
                        {
                            //Pour chaque case, on va chercher la premiere case non nulle qui la suit
                            for(int j = i+1; j<taille; j++)
                                if(table[li][j] != 0)
                                {
                                    Set(li,i, table[li][j]);
                                    Set(li,j, 0);
                                    break;
                                }
                        }
                        colonne = 0;
                    }
                }
                else
                    continuer = false;
            }
        }
        break;

    case DROITE:
        for(int li = 0; li<taille; li++)
        {
            bool continuer = true;

            //On commence par coller toutes les cases de la ligne vers la droite
            for(int i = taille-1; i>=1; i--)
            {
                //Pour chaque case nulle, on va chercher la premiere case non nulle qui la 'suit'
                if(table[li][i]==0)
                    for(int j = i-1; j>=0; j--)
                        if(table[li][j] != 0)
                        {
                            Set(li,i, table[li][j]);
                            Set(li,j, 0);
                            break;
                        }
            }

            //maintenant on traite le tableau
            int colonne = taille-1;
            while(continuer)
            {
                if(colonne>=1 && table[li][colonne] != 0)
                {
                    if(table[li][colonne] != table[li][colonne - 1])
                        colonne--;
                    else
                    {
                        quelqueChoseAChange = true;
                        Set(li, colonne, 2*table[li][colonne]);
                        Set(li, colonne-1, 0);

                        //Maintenant on colle toutes les cases vers la droite
                        for(int i = colonne-1; i>=1; i--)
                        {
                            //Pour chaque case, on va chercher la premiere case non nulle qui la suit
                            for(int j = i-1; j>=0; j--)
                                if(table[li][j] != 0)
                                {
                                    Set(li,i, table[li][j]);
                                    Set(li,j, 0);
                                    break;
                                }
                        }
                        colonne = taille-1;
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

void Plateau::AjouterValeurAleatoire()
{
    srand(time(NULL));
    int nombre = 4;

    if(rand()%100 < pourcentageDe2)
        nombre = 2;

    int ligne, colonne;

    do{
    ligne = rand()%taille;
    colonne = rand()%taille;
    }
    while(table[ligne][colonne] != 0);

    table[ligne][colonne] = nombre;
}

void Plateau::Print()
{
    for (int i = 0; i<taille; i++)
    {
        for (int j = 0; j<taille; j++)
            cout<<table[i][j]<<"  ";
        cout<<endl;
    }
}
