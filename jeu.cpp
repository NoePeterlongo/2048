#include "jeu.h"
#include <iostream>
#include <string>


Jeu::Jeu(QObject *parent) : QObject(parent)
{
    initialiserPartie();

    //Traitement du fichier de meilleur score :

    if(fopen(chemin, "r")==NULL)//Si le fichier n'existe pas
    {
        fopen_s(&fichierSauvegarde, chemin, "w");
        fprintf_s(fichierSauvegarde, "Meilleur score : 0");
        fclose(fichierSauvegarde);
    }
    fopen_s(&fichierSauvegarde, chemin, "r");
    //On récupère le meilleur score
    fscanf(fichierSauvegarde, "Meilleur score : %d", &meilleurScore);
    fclose(fichierSauvegarde);
    meilleurScoreChanged();//On met à jour l'affichage du meilleur score


}

void Jeu::initialiserPartie()
{
    plateau.Init();//réinitialisation du plateau
    score = 0;
    //Mise à jour de l'affichage
    scoreChanged();
    plateauChanged();
    colorChanged();

    //initialisation de la position dans le tableau d'enregistrement des coups
    idCoup = -1;
    idCoupMax = -1;
    plateauInitial = new Plateau(plateau);

    gameOverVisible = false;
    gameOverVisibleChanged();
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
            else if (log2(tuile)<16)
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

bool Jeu::readGameOverVisible()
{
    return gameOverVisible;
}

void Jeu::NouveauCoup(int deplacement)
{
    //On applique le mouvement, et s'il a changé quelque chose au plateau,
    //On ajoute une case aléatoire
    if(plateau.Mouvement(deplacement, &score))
        plateau.AjouterValeurAleatoire(&posX, &posY, &val);

    //Mise à jour de la position dans le tableau d'enregistrement des coups
    idCoup++;
    idCoupMax = idCoup;
    //Création du coup correspondant au coup actuel
    coups[idCoup] = new Coup(deplacement, posX, posY, val);

    //Affichage pour débuggage
    plateau.Print();
    std::cout<<std::endl;

    if(score>meilleurScore)//Mise à jour du meilleur score si besoin
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
    //maintenant on regarde si on est en gameover:
    //On applique à des copies du plateau les quatre coups possibles,
    //Si aucun des coups ne modifie le plateau, alors on est en GameOver
    bool gameover = true;
    for(int i = 1; i<5;i++)
    {
        Plateau plateauTemp = Plateau(plateau);//On recopie le plateau
        if(plateauTemp.Mouvement(i, &scoreDebug))//si ça change quelque chose
            gameover = false;
    }
    if(gameover)
    {
        std::cout<<"GameOver";
        gameOverVisible = true;
        gameOverVisibleChanged();
    }

}

//Ces fonctions sont appelées par le QML, et elles-mêmes appellent NouveauCoup avec le paramètre approprié
void Jeu::mvmtHaut() {NouveauCoup(HAUT);}
void Jeu::mvmtBas() {NouveauCoup(BAS);}
void Jeu::mvmtDroite() {NouveauCoup(DROITE);}
void Jeu::mvmtGauche() {NouveauCoup(GAUCHE);}

//Permet de revenir, ou d'avancer d'un coup (suivant la valeur de "reculer")
/*Le tableau "coups" contient l'ensemble des coups qui ont été joués,
 * "idCoup" contient la position dans ce tableau correspondant au plateau affiché
 * "idCoupMax" contient la position dans "coups" du dernier coup joué
 *
 * L'idée est de rejouer tous les coups depuis le début */
void Jeu::annulerCoup(bool reculer)
{
    if (reculer)
    {
        if (idCoup >= 0 && !gameOverVisible)//Pas de retour possible si le gameover est atteint
        {
            idCoup--;
            plateau.Init();
            plateau = *plateauInitial;
            score=0;
            for(int i=0; i<idCoup+1 && i<100000; i++)
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
        if (idCoup<idCoupMax && !gameOverVisible)
        {
            idCoup++;
            plateau.Init();
            plateau = *plateauInitial;
            score=0;
            for(int i=0; i<idCoup+1 && i<100000; i++)
            {
                plateau.Mouvement(coups[i]->mouvement, &score);
                plateau.Set(coups[i]->positionNouvelleTuilleX, coups[i]->positionNouvelleTuilleY, coups[i]->valeurNouvelleTuille);
            }
            plateauChanged();
            colorChanged();
            scoreChanged();
        }
    }
    /*
    //maintenant on regarde si on est en gameover
    bool gameover = true;
    for(int i = 1; i<5;i++)
    {
        Plateau plateauTemp = Plateau(plateau);//On recopie le plateau
        if(plateauTemp.Mouvement(i, &scoreDebug))//si ça change quelque chose
            gameover = false;
    }
    if(gameover)
    {
        std::cout<<"GameOver";
        gameOverVisible = true;
        gameOverVisibleChanged();
    }
    else
    {
        gameOverVisible = false;
        gameOverVisibleChanged();
    }*/
}
