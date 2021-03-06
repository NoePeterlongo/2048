#ifndef PLATEAU_H
#define PLATEAU_H

#define HAUT 1
#define BAS 2
#define GAUCHE 3
#define DROITE 4

class Plateau
{
private:
    int taille;//Cette classe est conçue pour fonctionner avec plusieurs tailles
    int **table;//Tableau représentant le plateau actuel
    int pourcentageDe2 = 90;
public:
    Plateau();//constructeur classique
    Plateau(const Plateau &autrePlateau);//constructeur de recopie
    ~Plateau();

    void Init();

    //Applique un mouvement au plateau, le paramètre peut être BAS, HAUT, GAUCHE, ou DROITE, des constantes prédéfinies
    //Cette fonction renvoie un booléen : true si le mouvement a modifié le plateau
    bool Mouvement(int mouvement, int* score);


    bool Set(int ligne, int colonne, int valeur);
    int getCase(int ligne, int colonne);
    int getTaille();
    void AjouterValeurAleatoire(int* positionX, int* positionY, int* valeur);
    void Print();

    void operator=(const Plateau& autrePlateau);
};

#endif // PLATEAU_H
