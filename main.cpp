#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QtQml>
#include <iostream>
#include "plateau.h"
#include "jeu.h"

using namespace std;

int main(int argc, char *argv[])
{

    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;

    Jeu jeu();
    //engine.rootContext()->setContextProperty("jeu", &jeu);

    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));


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



    return app.exec();
}
