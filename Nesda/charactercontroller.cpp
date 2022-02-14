#include "charactercontroller.h"

CharacterController::CharacterController() {}

CharacterController::CharacterController(Player &_player)
{
    player = _player;
    ResetDirection();
}

void CharacterController::applyMovements()
{
    if(direction.x() != 0 && direction.y() != 0)
        direction *= 0.7;
    player.worldPosition += direction*speed;
    player.collider.SetWorldPosition(player.worldPosition);
}

void CharacterController::ResetDirection()
{
    direction = QVector3D(0, 0, 0);
}


CharacterController::~CharacterController()
{

}
