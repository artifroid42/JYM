#include "mainwindow.h"
#include "gamemanager.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    GameManager gamemanager;
    gamemanager.BoucleDeJeu();

    MainWindow w;
    w.show();

    return a.exec();
}
