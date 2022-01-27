#include "mainwindow.h"
#include "gamemanager.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    //TODO: collider.setWorldPosition at each movement
    QApplication a(argc, argv);
    GameManager gamemanager;
    gamemanager.BoucleDeJeu();
    MainWindow w;
    w.show();
    return a.exec();
}
