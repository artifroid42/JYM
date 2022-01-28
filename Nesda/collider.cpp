#include "collider.h"
#include "iostream"

Collider::Collider() {}

Collider::Collider(QVector3D pt1 , QVector3D pt2)
{
    localPt1 = pt1;
    localPt2 = pt2;
    IsCircle = false;
}

Collider::Collider(float a_radius)
{
    IsCircle = true;
    Radius = a_radius;
}

bool Collider::IsColliding(Collider otherCollider)
{
    vector<vector<QVector3D>> sides = GetSides();
    vector<vector<QVector3D>> otherSides = otherCollider.GetSides();
    for(vector<vector<QVector3D>>::iterator side = sides.begin(); side != sides.end(); side++) {
        for(vector<vector<QVector3D>>::iterator otherSide = otherSides.begin(); otherSide != otherSides.end(); otherSide++) {
            if(AreSegmentsCrossing((*side)[0], (*side)[1], (*otherSide)[0], (*otherSide)[1]))
                return true;
        }
    }
    return false;
}

bool Collider::AreSegmentsCrossing(QVector3D A, QVector3D B, QVector3D X, QVector3D Y)
{
    QVector3D XY = Y-X;
    QVector3D XA = A-X;
    QVector3D XB = B-X;
    QVector3D AB = B-A;
    if(QVector3D::crossProduct(AB, XY) == QVector3D(0, 0, 0))
        return false;
    QVector3D u = QVector3D::crossProduct(XY, XA);
    QVector3D v = QVector3D::crossProduct(XB, XY);
    return QVector3D::dotProduct(u, v)/(u.length()/v.length())> 0;
}

vector<vector<QVector3D>> Collider::GetSides() {
    vector<QVector3D> side1 = {worldPt1, QVector3D(worldPt2.x(), worldPt1.y(), 0)};
    vector<QVector3D> side2 = {QVector3D(worldPt2.x(), worldPt1.y(), 0), worldPt2};
    vector<QVector3D> side3 = {worldPt2, QVector3D(worldPt1.x(), worldPt2.y(), 0)};
    vector<QVector3D> side4 = {QVector3D(worldPt1.x(), worldPt2.y(), 0), worldPt1};

    vector<vector<QVector3D>> sides;
    sides.insert(sides.end(), {side1, side2, side3, side4});
    return sides;
}

void Collider::SetWorldPosition(QVector3D worldPosition) {
    worldPt1 = localPt1 + worldPosition;
    worldPt2 = localPt2 + worldPosition;
}
