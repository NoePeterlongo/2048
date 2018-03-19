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
    Q_PROPERTY(QString plateauQML READ readCase NOTIFY plateauChanged);

    QString readCase(i,j);


private:
    int score = 0;
    Plateau plateau;


signals:

    void plateauChanged();

public slots:
};

#endif // JEU_H
