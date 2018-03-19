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
    Q_PROPERTY(QList<QString> plateauQML READ readPlateau NOTIFY plateauChanged);
    Q_PROPERTY(QString scoreQML READ readScore NOTIFY scoreChanged);

    QList<QString> readPlateau();
    QString readScore();
    void NouveauCoup(int deplacement);

    Q_INVOKABLE void mvmtHaut();
    Q_INVOKABLE void mvmtBas();
    Q_INVOKABLE void mvmtDroite();
    Q_INVOKABLE void mvmtGauche();

private:
    int score = 11;
    Plateau plateau;


signals:

    void plateauChanged();
    void scoreChanged();

public slots:
};

#endif // JEU_H
