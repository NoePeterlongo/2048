#ifndef JEU_H
#define JEU_H

#include <QObject>
#include <plateau.h>

class Jeu : public QObject
{
    Q_OBJECT
public:
    explicit Jeu(QObject *parent = nullptr);
    Q_INVOKABLE void InitialiserPartie();
    Q_INVOKABLE void afficherPlateau();
    Q_PROPERTY(QString caseQML READ readCase(i,j) NOTIFY caseChanged(i,j));

    QString readCase(int i, int j);


private:
    int score = 0;
    Plateau plateau;


signals:

    void caseChanged(int i, int j);

public slots:
};

#endif // JEU_H
