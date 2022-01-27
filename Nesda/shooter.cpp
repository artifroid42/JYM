#include "shooter.h"

Shooter::Shooter() {}

Shooter::Shooter(QVector3D spawnPos, QVector3D colliderPt1, QVector3D colliderPt2) : Entity(spawnPos, colliderPt1, colliderPt2)
{
}
