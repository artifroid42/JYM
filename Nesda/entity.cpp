#include "entity.h"

Entity::Entity() {}

Entity::Entity(QVector3D spawnPosition, QVector3D colliderPt1, QVector3D colliderPt2, QVector3D _color)
{
    collider = Collider(colliderPt1 , colliderPt2);
    worldPosition = spawnPosition;
    collider.SetWorldPosition(worldPosition);
    color = _color;
}
