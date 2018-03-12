#ifndef PLATEAU_H
#define PLATEAU_H

#define HAUT 8
#define BAS 2
#define GAUCHE 4
#define DROITE 6

class Plateau
{
private:
    int taille;
    int **table;
    int pourcentageDe2 = 90;
public:
    Plateau(int Taille);//constructeur classique
    Plateau(const Plateau &autrePlateau);//constructeur de recopie
    //~Plateau();


    bool Mouvement(int mouvement);//est appelée avec un paramètre HAUT,BAS... et renvoie true si cela a changé quelque chose
    bool Set(int ligne, int colonne, int valeur);
    void AjouterValeurAleatoire();
    //int** GetTable();
    void Print();

};

#endif // PLATEAU_H
