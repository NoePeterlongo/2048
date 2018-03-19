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
    //Q_PROPERTY(QString caseQML READ readCase(i,j) NOTIFY caseChanged(i,j));
    Q_PROPERTY(QString scoreQML READ readScore NOTIFY scoreChanged);

    QString readCase(int i, int j);
    QString readScore();



private:
    int score = 11;
    Plateau plateau;


signals:

    void caseChanged(int i, int j);
    void scoreChanged();

public slots:
};

#endif // JEU_H
