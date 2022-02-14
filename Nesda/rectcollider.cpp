#include "rectcollider.h"
#include "iostream"


RectCollider::RectCollider(){}

RectCollider::RectCollider(QVector3D pt1 , QVector3D pt2)
{
    localPt1 = pt1;
    localPt2 = pt2;
}

void RectCollider::SetWorldPosition(QVector3D worldPosition) {
    worldPt1 = localPt1 + worldPosition;
    worldPt2 = localPt2 + worldPosition;
}
