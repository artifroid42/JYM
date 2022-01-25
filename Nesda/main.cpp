#include "mainwindow.h"
#include "gamemanager.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    GameManager gamemanager;
    gamemanager.BoucleDeJeu();
    return a.exec();
}
