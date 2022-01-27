#ifndef CHARACTERCONTROLLER_H
#define CHARACTERCONTROLLER_H
#include "QVector3D"
#include "entity.h"

class CharacterController
{
public:
    CharacterController(Entity &player);
    CharacterController();
    ~CharacterController();
    void ResetDirection();
    void applyMovements();
    float speed = 0.1;
    QVector3D direction;
    Entity entity;
private :
};

#endif // CHARACTERCONTROLLER_H
