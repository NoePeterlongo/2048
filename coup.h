#ifndef COUP_H
#define COUP_H


class Coup
{
public:
    Coup(int mvmt, int posX, int posY, int valeur);
    int mouvement;
    int positionNouvelleTuilleX;
    int positionNouvelleTuilleY;
    int valeurNouvelleTuille;
};

#endif // COUP_H
