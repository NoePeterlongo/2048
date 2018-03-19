#include "jeu.h"

Jeu::Jeu(QObject *parent) : QObject(parent)
{

}

void Jeu::afficherPlateau()
{
    for (int i=0; i<plateau.getTaille(), i++)
    {
        for (int j=0; j<plateau.getTaille(), j++)
        {

        }
    }
}

QString Jeu::readCase(int i, int j)
{
    return QString::number(plateau.getCase(i,j));
}
