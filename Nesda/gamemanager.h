#include <QVector2D>
#include "player.h"
#include "ennemy.h"
#include "iostream"
#include <QObject>
#include <QThread>
using namespace std;

#ifndef GAMEMANAGER_H
#define GAMEMANAGER_H



class GameManager : public QObject
{
    Q_OBJECT
public:
    GameManager() {
        m_thread.reset(new QThread);
        moveToThread(m_thread.get());
        m_thread->start();
    };
    ~GameManager()
    {
      //  QMetaObject::invokeMethod()
    }

    void BoucleDeJeu();
private :
    std::unique_ptr<QThread> m_thread;

};


#endif // GAMEMANAGER_H
