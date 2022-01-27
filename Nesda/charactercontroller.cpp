#include "charactercontroller.h"

CharacterController::CharacterController() {}

CharacterController::CharacterController(Entity &_entity)
{
    entity = _entity;
    ResetDirection();
}

void CharacterController::applyMovements()
{
    if(direction.x() != 0 && direction.y() != 0)
        direction *= 0.7;
    entity.worldPosition += direction*speed;
}

void CharacterController::ResetDirection()
{
    direction = QVector3D(0, 0, 0);
}


CharacterController::~CharacterController()
{

}
