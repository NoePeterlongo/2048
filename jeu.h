#ifndef JEU_H
#define JEU_H

#include <QObject>
#include <plateau.h>
#include <coup.h>
#include <vector>

class Jeu : public QObject
{
    Q_OBJECT
public:
    explicit Jeu(QObject *parent = nullptr);
    Q_INVOKABLE void initialiserPartie();
    Q_PROPERTY(QList<QString> plateauQML READ readPlateau NOTIFY plateauChanged);
    Q_PROPERTY(QList<QString> colorQML READ readColor NOTIFY colorChanged);
    Q_PROPERTY(QString scoreQML READ readScore NOTIFY scoreChanged);

    QList<QString> readPlateau();
    QList<QString> readColor();
    QString readScore();
    void NouveauCoup(int deplacement);

    Q_INVOKABLE void mvmtHaut();
    Q_INVOKABLE void mvmtBas();
    Q_INVOKABLE void mvmtDroite();
    Q_INVOKABLE void mvmtGauche();

    Q_INVOKABLE void annulerCoup();

private:
    int score = 0;
    int scoreDebug = 0;
    Plateau plateau;
    QList<QString> Lcolor={"#F4CA99", "#FCFBFA","#E2BB8E", "#ED9530", "#DE5116", "#B10406", "#BE0933", "#AC28FE", "#4F24FD"};

    Coup* coups[1000];
    Plateau* plateauInitial;
    int idCoup = -1;
    int posX, posY, val;

signals:

    void plateauChanged();
    void scoreChanged();
    void colorChanged();

public slots:
};

#endif // JEU_H
