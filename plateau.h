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
    Plateau();//constructeur classique
    Plateau(const Plateau &autrePlateau);//constructeur de recopie
    ~Plateau();
    void Init();

    //Applique un mouvement au plateau, le paramètre peut être BAS, HAUT, GAUCHE, ou DROITE, des constantes prédéfinies
    //Cette fonction renvoie un booléen : true si le mouvement a modifié le plateau
    bool Mouvement(int mouvement);


    bool Set(int ligne, int colonne, int valeur);
    int getCase(int ligne, int colonne);
    int getTaille();
    void AjouterValeurAleatoire();
    void Print();

};

#endif // PLATEAU_H
