#include "jeu.h"

Jeu::Jeu(QObject *parent) : QObject(parent)
{

}

void Jeu::InitialiserPartie()
{
    score = 0;

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
