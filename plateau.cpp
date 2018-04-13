#include "plateau.h"
#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;

Plateau::Plateau()
{
    taille = 4;//Pour l'instant la taille est fixée

    //allocation dynamique de la table et initialisation à 0 de toutes les cases
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

void Plateau::Init()//remise à 0, ajout de deux cases aléatoires
{
    for(int i = 0; i<taille; i++)
    {
        for(int j = 0; j < taille; j++)
            table[i][j] = 0;
    }
    int x,y,v;
    AjouterValeurAleatoire(&x,&y,&v);
    AjouterValeurAleatoire(&x,&y,&v);

    srand(time(NULL));//initalisation du générateur aléatoire
}

Plateau::~Plateau()
{
    for(int i = 0; i<taille; i++)
        delete[] table[i];
    delete[] table;
}

//Change une valeur dans table, en faisant des vérifications
bool Plateau::Set(int ligne, int colonne, int valeur)
{
    if(ligne>=taille || ligne<0 || colonne<0 || colonne>=taille)
        return false;

    table[ligne][colonne] = valeur;
    return true;
}

//Applique un mouvement au plateau, et met à jour le score
bool Plateau::Mouvement(int mouvement, int* score)
{
    bool quelqueChoseAChange = false;//variable utilisée pour détecter le gameover

    switch(mouvement)
    {
    case HAUT:
        for(int col = 0; col<taille; col++)//On traite les colonnes une à une
        {

            //On commence par coller toutes les cases de la colonne vers le haut :
            for(int i = 0; i<taille-1; i++)
            {
                //Pour chaque case nulle, on va chercher la premiere case non nulle qui la suit
                if(table[i][col]==0)
                    for(int j = i+1; j<taille; j++)
                        if(table[j][col] != 0)//La case non nulle qui suit : on déplace sa valeur, elle devient alors nulle, et on continue en charchant la prochaine case non nulle
                        {
                            quelqueChoseAChange = true;
                            Set(i,col, table[j][col]);
                            Set(j,col, 0);
                            break;
                        }
            }

            //maintenant on traite le tableau, et les fusions
            int ligne = 0;
            bool continuer = true;
            while(continuer)
            {
                /* on traite les cases une à une :
                 * si la case sur laquelle on est est suivie par une case identique,
                 * on les fusionne */
                if(ligne<taille-1 && table[ligne][col] != 0)
                {
                    if(table[ligne][col] != table[ligne+1][col])
                        ligne++;//On change de case
                    else
                    {
                        //fusion
                        quelqueChoseAChange = true;
                        Set(ligne, col, 2*table[ligne][col]);
                        *score += table[ligne][col];
                        Set(ligne+1, col, 0);

                        //Maintenant on colle toutes les cases vers le haut,
                        //Comme précédemment
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
                        //On recommence à la première ligne (On ne le fait plus, ça change le gameplay : dans ce cas une case pourrait fusionner plusieurs fois dans un coup)
                        //ligne = 0;
                    }
                }
                else
                    continuer = false;
            }
        }
        break;

    //les autres coups sont symétriques
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
                            quelqueChoseAChange = true;
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
                        *score += table[ligne][col];
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
                        //ligne = taille-1;
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
                            quelqueChoseAChange = true;
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
                        *score += table[li][colonne];
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
                        //colonne = 0;
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
                            quelqueChoseAChange = true;
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
                        *score += table[li][colonne];
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
                        //colonne = taille-1;
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


//Cette fonction sélectionne aléatoirement une case vide du plateau et y met un 2 ou un 4
//Grâce aux pointeurs, on récupère les données de la case modifiée pour enregistrer les coups
void Plateau::AjouterValeurAleatoire(int* positionX, int* positionY, int* valeur)
{
    *positionX = -1;
    *positionY = -1;
    *valeur = -1;

    //On commence par vérifier s'il reste une case libre
    bool ilResteUneCaseLibre = false;
    for (int i = 0; i<taille; i++)
        for(int j = 0; j<taille; j++)
            if(table[i][j]==0) ilResteUneCaseLibre = true;
    if (!ilResteUneCaseLibre)
        return;

    //On choisit la valeur de la case ajoutée
    int nombre = 4;
    if(rand()%100 < pourcentageDe2)
        nombre = 2;

    int ligne, colonne;

    //On choisit des valeurs aléatoires pour la position de la case,
    //jusqu'à ce qu'on tombe sur une case libre
    do{
    ligne = rand()%taille;
    colonne = rand()%taille;
    }
    while(table[ligne][colonne] != 0);

    table[ligne][colonne] = nombre;

    *positionX = ligne;
    *positionY = colonne;
    *valeur = nombre;
}

int Plateau::getCase(int ligne, int colonne)
{
    return table[ligne][colonne];
}

int Plateau::getTaille()//Non utilisée ici
{
    return taille;
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

void Plateau::operator=(const Plateau& autrePlateau)
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
