#ifndef COLLISIONMANAGER_H
#define COLLISIONMANAGER_H
#include "rectcollider.h"
#include "circlecollider.h"

class CollisionManager
{
public:
    CollisionManager();
    int IsRectCollidingWithRect(Collider collider, Collider other);
    bool AreSegmentsCrossing(QVector3D, QVector3D, QVector3D, QVector3D);
    int IsCircleCollidingWithRect(Collider circleCollider, Collider rectCollider);
    vector<int> IsRectCollidingWithCircle(Collider rectCollider, Collider circleCollider);
    vector<vector<QVector3D>> GetSides(Collider);
    QVector3D IsCircleCollidingWithCircle(Collider collider, Collider otherCollider);
};

#endif // COLLISIONMANAGER_H
