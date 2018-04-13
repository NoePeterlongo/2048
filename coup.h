#ifndef COUP_H
#define COUP_H

//Classe utilisée pour simplifier le code de l'enregistrement des coups
//Contient le mouvement réalisé ainsi que les informations sur la case ajoutée

class Coup
{
public:
    Coup(int mvmt, int posX, int posY, int valeur);
    Coup();
    int mouvement;
    int positionNouvelleTuilleX;
    int positionNouvelleTuilleY;
    int valeurNouvelleTuille;

    //Coup& operator=(Coup& cp);
};

#endif // COUP_H
