#ifndef COUP_H
#define COUP_H


class Coup
{
public:
    Coup(int mvmt, int posX, int posY, int valeur);
    Coup();
    int mouvement;
    int positionNouvelleTuilleX;
    int positionNouvelleTuilleY;
    int valeurNouvelleTuille;

    Coup& operator=(Coup& cp);
};

#endif // COUP_H
