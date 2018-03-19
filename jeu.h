#ifndef JEU_H
#define JEU_H

#include <QObject>
#include "plateau.h"

class Jeu : public QObject
{
    Q_OBJECT
public:
    explicit Jeu(QObject *parent = nullptr);
    Q_INVOKABLE void afficherPlateau();

    Q_PROPERTY(QString plateauQML READ readCase NOTIFY plateauChanged);

    QString readCase(int i, int j);

signals:

    void plateauChanged();

private:

    Plateau plateau;

public slots:
};

#endif // JEU_H
