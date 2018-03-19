#include "jeu.h"
#include <iostream>

Jeu::Jeu(QObject *parent) : QObject(parent)
{
    InitialiserPartie();
}

void Jeu::InitialiserPartie()
{
    plateau.Init();
    score = 0;
    scoreChanged();
    plateauChanged();

}


QList<QString> Jeu::readPlateau()
{
    QList<QString> L;
    for (int i=0; i<plateau.getTaille(); i++)
    {
        for (int j=0; j<plateau.getTaille(); j++)
        {
            int tuile=plateau.getCase(i,j);
            if (tuile!=0)
            {
                L.append(QString::number(tuile));
            }
            else{
                L.append(" ");
            }
        }
    }
    return L;
}

QString Jeu::readScore()
{
    return QString::number(score);
}

void Jeu::NouveauCoup(int deplacement)
{
    plateau.Mouvement(deplacement, &score);
    plateau.AjouterValeurAleatoire();
    plateau.Print();
    std::cout<<std::endl;
    plateauChanged();
    scoreChanged();
    //maintenant on regarde si on est en gameover
    bool gameover = true;
    for(int i = 1; i<5;i++)
    {
        Plateau plateauTemp = Plateau(plateau);//On recopie le plateau
        if(plateauTemp.Mouvement(i, &scoreDebug))//si ça change quelque chose
            gameover = false;
    }
    if(gameover)
        std::cout<<"GameOver";
}

void Jeu::mvmtHaut() {NouveauCoup(HAUT);}
void Jeu::mvmtBas() {NouveauCoup(BAS);}
void Jeu::mvmtDroite() {NouveauCoup(DROITE);}
void Jeu::mvmtGauche() {NouveauCoup(GAUCHE);}
