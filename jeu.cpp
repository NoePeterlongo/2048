#include "jeu.h"
#include <iostream>
#include <string>


Jeu::Jeu(QObject *parent) : QObject(parent)
{
    initialiserPartie();

    if(fopen(chemin, "r")==NULL)//Si le fichier n'existe pas
    {
        fopen_s(&fichierSauvegarde, chemin, "w");
        fprintf_s(fichierSauvegarde, "Meilleur score : 0");
        fclose(fichierSauvegarde);
    }
    fopen_s(&fichierSauvegarde, chemin, "r");
    fscanf_s(fichierSauvegarde, "Meilleur score : %d", &meilleurScore);
    fclose(fichierSauvegarde);
    meilleurScoreChanged();
}

void Jeu::initialiserPartie()
{
    plateau.Init();
    score = 0;
    scoreChanged();
    plateauChanged();
    colorChanged();

    idCoup = -1;
    idCoupMax = -1;
    plateauInitial = new Plateau(plateau);
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

QList<QString> Jeu::readColor()
{
    QList<QString> L;
    for (int i=0; i<plateau.getTaille(); i++)
    {
        for (int j=0; j<plateau.getTaille(); j++)
        {
            int tuile=plateau.getCase(i,j);
            if (tuile==0)
            {
                L.append(Lcolor[0]);
            }
            else if (log2(tuile)<12)
            {
                L.append(Lcolor[log2(tuile)]);
            }
            else{
                L.append(Lcolor[0]);
            }
        }
    }
    return L;
}

QString Jeu::readScore()
{
    return QString::number(score);
}

QString Jeu::readMeilleurScore()
{
    return QString::number(meilleurScore);
}

void Jeu::NouveauCoup(int deplacement)
{
    plateau.Mouvement(deplacement, &score);
    plateau.AjouterValeurAleatoire(&posX, &posY, &val);
    idCoup++;
    idCoupMax = idCoup;

    coups[idCoup] = new Coup(deplacement, posX, posY, val);

    plateau.Print();
    std::cout<<std::endl;

    if(score>meilleurScore)
    {
        meilleurScore = score;
        fichierSauvegarde = fopen(chemin, "w");
        fprintf_s(fichierSauvegarde, "Meilleur score : %d", meilleurScore);
        fclose(fichierSauvegarde);
        meilleurScoreChanged();
    }

    plateauChanged();
    colorChanged();
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

void Jeu::annulerCoup(bool reculer)
{
    if (reculer)
    {
        if (idCoup >= 0)
        {
            idCoup--;
            plateau.Init();
            plateau = *plateauInitial;
            score=0;
            for(int i=0; i<idCoup+1 && i<1000; i++)
            {
                plateau.Mouvement(coups[i]->mouvement, &score);
                plateau.Set(coups[i]->positionNouvelleTuilleX, coups[i]->positionNouvelleTuilleY, coups[i]->valeurNouvelleTuille);
            }
            plateauChanged();
            colorChanged();
            scoreChanged();
        }
    }
    else
    {
        if (idCoup<idCoupMax)
        {
            idCoup++;
            plateau.Init();
            plateau = *plateauInitial;
            score=0;
            for(int i=0; i<idCoup+1 && i<1000; i++)
            {
                plateau.Mouvement(coups[i]->mouvement, &score);
                plateau.Set(coups[i]->positionNouvelleTuilleX, coups[i]->positionNouvelleTuilleY, coups[i]->valeurNouvelleTuille);
            }
            plateauChanged();
            colorChanged();
            scoreChanged();
        }
    }
}
