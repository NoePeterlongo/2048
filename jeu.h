#ifndef JEU_H
#define JEU_H

#include <QObject>

class Jeu : public QObject
{
    Q_OBJECT
public:
    explicit Jeu(QObject *parent = nullptr);

signals:

public slots:
};

#endif // JEU_H