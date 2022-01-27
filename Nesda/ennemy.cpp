#include "ennemy.h"

Enemy::Enemy() {}

Enemy::Enemy(QVector3D spawnPos, QVector3D colliderPt1, QVector3D colliderPt2) : Shooter(spawnPos, colliderPt1, colliderPt2)
{
}
