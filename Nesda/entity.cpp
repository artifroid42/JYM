#include "entity.h"

Entity::Entity(QVector3D colliderPt1, QVector3D colliderPt2)
{
    collider = Collider(colliderPt1 , colliderPt2);
}
