#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <iostream>
#include "plateau.h"
#include "jeu.h"

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

    /*
    Plateau p(4);

    //Tests des mouvements
    p.Set(0,0,4);
    p.Set(1,0,4);
    p.Set(3,0,4);
    p.Set(0,1,8);
    p.Set(1,1,4);
    p.Set(3,1,4);
    p.Set(0,2,0);
    p.Set(1,2,4);
    p.Set(3,2,8);
    p.Set(3,0,8);
    p.Set(3,1,16);
    p.Set(3,3,8);
    p.Print();
    cout<<endl;
    p.Mouvement(BAS);
    p.AjouterValeurAleatoire();
    p.Print();
    p.Mouvement(DROITE);
    p.Print();
    cout<<endl;
    cout<<p.getCase(3,3);*/

    //Jeu jeu();
    //engine.rootContext()->setContextProperty("jeu", &jeu);


    return app.exec();
}
