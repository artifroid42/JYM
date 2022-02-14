#include "collider.h"
#include "entity.h"
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
    if(IsCircle){
        worldPt1 = QVector3D(worldPosition.x(), worldPosition.y() + Radius, 0);
        worldPt2 = QVector3D(worldPosition.x() + Radius, worldPosition.y(), 0);
        worldPt3 = QVector3D(worldPosition.x(), worldPosition.y() - Radius, 0);
        worldPt4 = QVector3D(worldPosition.x() - Radius, worldPosition.y(), 0);
    }
    else{
        worldPt1 = localPt1 + worldPosition;
        worldPt2 = localPt2 + worldPosition;
    }
}
