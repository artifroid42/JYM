#include "player.h"

Player::Player()
{

}

Player::Player(QVector3D spawnPos, QVector3D colliderPt1, QVector3D colliderPt2, QVector3D _color) : Shooter(spawnPos, colliderPt1, colliderPt2, _color)
{

}
