#include "ennemy.h"

Enemy::Enemy() {}

Enemy::Enemy(QVector3D spawnPos, QVector3D colliderPt1, QVector3D colliderPt2, QVector3D _color) : Shooter(spawnPos, colliderPt1, colliderPt2, _color)
{
}
