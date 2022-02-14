#ifndef CHARACTERCONTROLLER_H
#define CHARACTERCONTROLLER_H
#include "QVector3D"
#include "entity.h"
#include "player.h"

class CharacterController
{
public:
    CharacterController(Player &player);
    CharacterController();
    ~CharacterController();
    void ResetDirection();
    void applyMovements();
    float speed = 0.1;
    QVector3D direction;
    Player player;
private :
};

#endif // CHARACTERCONTROLLER_H
