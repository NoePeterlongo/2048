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
    Q_PROPERTY(QString meilleurScoreQML READ readMeilleurScore NOTIFY meilleurScoreChanged);

    QList<QString> readPlateau();
    QList<QString> readColor();
    QString readScore();
    QString readMeilleurScore();
    void NouveauCoup(int deplacement);

    Q_INVOKABLE void mvmtHaut();
    Q_INVOKABLE void mvmtBas();
    Q_INVOKABLE void mvmtDroite();
    Q_INVOKABLE void mvmtGauche();

    Q_INVOKABLE void annulerCoup(bool reculer = true);

private:
    int score = 0;
    int scoreDebug = 0;
    Plateau plateau;
    QList<QString> Lcolor={"#F4CA99", "#FCFBFA","#E2BB8E", "#ED9530", "#DE5116", "#B10406", "#BE0933", "#AC28FE", "#4F24FD", "#138CBC", "#43D4C6", "#7ABE90"};

    Coup* coups[100000];
    Plateau* plateauInitial;
    int idCoup = -1, idCoupMax = -1;
    int posX, posY, val;

    FILE* fichierSauvegarde;
    int meilleurScore = 0;
    const char * chemin = "sauvegarde.zgh";

signals:

    void plateauChanged();
    void scoreChanged();
    void meilleurScoreChanged();
    void colorChanged();

public slots:
};

#endif // JEU_H
