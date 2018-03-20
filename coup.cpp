#include "coup.h"

Coup::Coup(int mvmt, int posX, int posY, int valeur)
{
    mouvement = mvmt;
    positionNouvelleTuilleX = posX;
    positionNouvelleTuilleY = posY;
    valeurNouvelleTuille = valeur;
}

Coup::Coup()
{
    mouvement = 0;
    positionNouvelleTuilleX = 0;
    positionNouvelleTuilleY = 0;
    valeurNouvelleTuille = 0;
}

/*Coup& Coup::operator =(const Coup& cp)
{
    mouvement = cp.mouvement;
    positionNouvelleTuilleX = cp.positionNouvelleTuilleX;
    positionNouvelleTuilleY = cp.positionNouvelleTuilleY;
    valeurNouvelleTuille = cp.valeurNouvelleTuille;
    return *this;
}*/
