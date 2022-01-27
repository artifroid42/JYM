#include "collider.h"
#include "iostream"

Collider::Collider() {}

Collider::Collider(QVector3D pt1 , QVector3D pt2)
{
    vecPt1 = pt1;
    vecPt2 = pt2;
    std::cout<<AreSegmentsCrossing(QVector3D(0, 0, 0), QVector3D(1, 1, 0), QVector3D(0, 1, 0), QVector3D(1, 0, 0));
}

bool Collider::IsColliding(Collider otherCollider, QVector3D otherPosition)
{

    return false;
}



bool Collider::AreSegmentsCrossing(QVector3D A, QVector3D B, QVector3D X, QVector3D Y)
{
    QVector3D XY = Y-X;
    QVector3D XA = A-X;
    QVector3D XB = B-X;
    QVector3D AB = B-A;
    if(QVector3D::dotProduct(AB, XY) == 0)
        return false;
    QVector3D u = QVector3D::crossProduct(XY, XA);
    QVector3D v = QVector3D::crossProduct(XB, XY);
    return QVector3D::dotProduct(u, v)/(u.length()/v.length())> 0;
}

//QVector3D[] Collider::GetSides() {
////     [vecPt1, , vecPt2, ]
//}
