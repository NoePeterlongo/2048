#ifndef JEU_H
#define JEU_H

#include <QObject>

class Jeu : public QObject
{
    Q_OBJECT
public:
    explicit Jeu(QObject *parent = nullptr);
    Q_INVOKABLE void InitialiserPartie();

private:
    int score = 0;


signals:

public slots:
};

#endif // JEU_H
