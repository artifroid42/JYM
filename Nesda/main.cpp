#include "mainwindow.h"
#include "gamemanager.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    Collider col = Collider(QVector3D(0, 0, 0), QVector3D(0, 0, 0));
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    GameManager gamemanager;
    gamemanager.BoucleDeJeu();
    return a.exec();
}
