#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <iostream>
#include "plateau.h"

using namespace std;

int main(int argc, char *argv[])
{
#if defined(Q_OS_WIN)
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
#endif

    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
    if (engine.rootObjects().isEmpty())
        return -1;

    Plateau p(4);
    p.Set(0,0,2);
    p.Set(1,0,4);
    p.Set(3,0,4);
    p.Set(0,1,0);
    p.Set(1,1,4);
    p.Set(3,1,4);
    p.Set(0,2,0);
    p.Set(1,2,4);
    p.Set(3,2,8);
    p.Print();
    cout<<endl;
    p.Mouvement(HAUT);
    p.Print();

    return app.exec();
}
