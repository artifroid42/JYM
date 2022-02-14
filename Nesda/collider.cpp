#include "collider.h"
#include "entity.h"
#include "iostream"

Collider::Collider() {}

Collider::Collider(QVector3D pt1 , QVector3D pt2)
{
    localPt1 = pt1;
    localPt2 = pt2;
}

Collider::Collider(float a_radius)
{
    IsCircle = true;
    Radius = a_radius;
}


void Collider::SetWorldPosition(QVector3D worldPosition) {
    if(IsCircle) {
        worldPt1 = worldPosition;
    } else {
        worldPt1 = localPt1 + worldPosition;
        worldPt2 = localPt2 + worldPosition;
    }
}

