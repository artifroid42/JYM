#ifndef COLLISIONMANAGER_H
#define COLLISIONMANAGER_H
#include "rectcollider.h"


class CollisionManager
{
public:
    CollisionManager();
    int IsRectCollidingWithRect(Collider collider, Collider other);
    bool AreSegmentsCrossing(QVector3D, QVector3D, QVector3D, QVector3D);
};

#endif // COLLISIONMANAGER_H