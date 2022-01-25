#include <QVector2D>
#include "player.h"
#include "ennemy.h"
#include "iostream"
using namespace std;

#ifndef GAMEMANAGER_H
#define GAMEMANAGER_H



class GameManager
{


public:
    GameManager();
    void BoucleDeJeu();
    Player player;
    Enemy enemy;
private :


};


#endif // GAMEMANAGER_H
