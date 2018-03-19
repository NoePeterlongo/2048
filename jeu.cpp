#include "jeu.h"
#include <iostream>

Jeu::Jeu(QObject *parent) : QObject(parent)
{
    scoreChanged();
}

void Jeu::InitialiserPartie()
{
    score = 0;
    scoreChanged();

}

void Jeu::afficherPlateau()
{
    for (int i=0; i<plateau.getTaille(); i++)
    {
        for (int j=0; j<plateau.getTaille(); j++)
        {
            caseChanged(i,j);
        }
    }
}

QString Jeu::readCase(int i, int j)
{
    return QString::number(plateau.getCase(i,j));
}

QString Jeu::readScore()
{
    return QString::number(score);
}

void Jeu::NouveauCoup(int deplacement)
{
    plateau.Mouvement(deplacement);
    //maintenant on regarde si on est en gameover
    bool gameover = true;
    for(int i = 1; i<5;i++)
    {
        Plateau plateauTemp = Plateau(plateau);//On recopie le plateau
        if(plateauTemp.Mouvement(i))//si ça change quelque chose
            gameover = false;
    }
    if(gameover)
        std::cout<<"GameOver";
}
