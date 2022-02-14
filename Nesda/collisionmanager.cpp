#include "collisionmanager.h"
#include "iostream"

CollisionManager::CollisionManager(){}

bool CollisionManager::AreSegmentsCrossing(QVector3D A, QVector3D B, QVector3D X, QVector3D Y)
{
    QVector3D XY = Y-X;
    QVector3D XA = A-X;
    QVector3D XB = B-X;
    QVector3D AB = B-A;
    if(QVector3D::crossProduct(AB, XY) == QVector3D(0, 0, 0))
        return false;
    QVector3D u = QVector3D::crossProduct(XY, XA);
    QVector3D v = QVector3D::crossProduct(XB, XY);
    cout<<QVector3D::dotProduct(u, v)/(u.length()*v.length())<<endl;
    return QVector3D::dotProduct(u, v)/(u.length()*v.length())> 0;
}

int CollisionManager::IsRectCollidingWithRect(Collider collider, Collider other) {
    // COLLIDE LEFT
    if((collider.worldPt1.x() < other.worldPt2.x() && other.worldPt1.x() < collider.worldPt1.x())) {
        if(other.worldPt1.y() < collider.worldPt2.y() && collider.worldPt2.y() < other.worldPt2.y()) {        // collide left-top
            if(collider.worldPt2.y()-other.worldPt1.y() < other.worldPt2.x() - collider.worldPt1.x())
                return 2;   //bot
            else
                return 1;   //right
        }
        else if(collider.worldPt1.y() < other.worldPt2.y() && other.worldPt1.y() < collider.worldPt1.y()) {   // collide left-bot
            if(other.worldPt2.y()-collider.worldPt1.y() < other.worldPt2.x()-collider.worldPt1.x())
                return 0;   //top
            else
                return 1;   //right
        }
        else if((other.worldPt1.y() < collider.worldPt1.y() && collider.worldPt2.y() < other.worldPt2.y()) ||
                (collider.worldPt1.y() < other.worldPt1.y() && other.worldPt2.y() < collider.worldPt2.y()))
            return 1;   //right
    }

    // COLLIDE RIGHT
    if(other.worldPt1.x() < collider.worldPt2.x() && collider.worldPt2.x() < other.worldPt2.x()) {
        if(other.worldPt1.y() < collider.worldPt2.y() && collider.worldPt2.y() < other.worldPt2.y()) {        // collide right-top
            if(collider.worldPt2.y()-other.worldPt1.y() < collider.worldPt2.x()-other.worldPt1.x())
                return 2;   //bot
            else
                return 3;   //left
        }
        else if(collider.worldPt1.y() < other.worldPt2.y() && other.worldPt1.y() < collider.worldPt1.y()) {      // collide right-bot
            if(other.worldPt2.y()-collider.worldPt1.y() < collider.worldPt2.x()-other.worldPt1.x())
                return 0;   //top
            else
                return 3;   //left
        }
        else if((other.worldPt1.y() < collider.worldPt1.y() && collider.worldPt2.y() < other.worldPt2.y()) ||
                (collider.worldPt1.y() < other.worldPt1.y() && other.worldPt2.y() < collider.worldPt2.y()))
            return 3;   //left
    }
    return -1;
}

int CollisionManager::IsCircleCollidingWithRect(Collider a_circleCollider, Collider a_rectCollider){
    QVector3D largeWorldPt1 = a_rectCollider.worldPt1 + QVector3D(-a_circleCollider.Radius, -a_circleCollider.Radius, 0);
    QVector3D largeWorldPt2 = a_rectCollider.worldPt2 + QVector3D(a_circleCollider.Radius, a_circleCollider.Radius, 0);

    if(largeWorldPt1.x() < a_circleCollider.worldPt1.x() && a_circleCollider.worldPt1.x() < largeWorldPt2.x() &&
       largeWorldPt1.y() < a_circleCollider.worldPt1.y() && a_circleCollider.worldPt1.y() < largeWorldPt2.y())
    {
        if(a_circleCollider.worldPt1.x() < a_rectCollider.worldPt1.x()){
            return 3; // Left
        }
        else if(a_circleCollider.worldPt1.x() > a_rectCollider.worldPt2.x()){
            return 1; // Right
        }
        else if (a_circleCollider.worldPt1.y() > a_rectCollider.worldPt1.y()){
            return 0; // Top
        }
        else if (a_circleCollider.worldPt1.y() < a_rectCollider.worldPt2.y()){
            return 2; // Bottom
        }
    }
    return -1;
}

vector<int> CollisionManager::IsRectCollidingWithCircle(Collider a_rectCollider, Collider a_circleCollider){
    QVector3D largeWorldPt1 = a_rectCollider.worldPt1 + QVector3D(-a_circleCollider.Radius, -a_circleCollider.Radius, 0);
    QVector3D largeWorldPt2 = a_rectCollider.worldPt2 + QVector3D(a_circleCollider.Radius, a_circleCollider.Radius, 0);

    vector<int> collisions = vector<int>();

    if(a_rectCollider.worldPt1.y() <= a_circleCollider.worldPt1.y()-a_circleCollider.Radius &&
            a_circleCollider.worldPt1.y()+a_circleCollider.Radius <= a_rectCollider.worldPt2.y()) {
        if(a_rectCollider.worldPt2.x() >= a_circleCollider.worldPt1.x()-a_circleCollider.Radius &&
                a_rectCollider.worldPt2.x() < a_circleCollider.worldPt1.x()+a_circleCollider.Radius)
            collisions.insert(collisions.cend(), 1);
        else if(a_circleCollider.worldPt1.x()+a_circleCollider.Radius >= a_rectCollider.worldPt1.x() &&
                a_circleCollider.worldPt1.x()-a_circleCollider.Radius < a_rectCollider.worldPt1.x())
            collisions.insert(collisions.cend(), 3);
    }
    else if(a_rectCollider.worldPt1.x() <= a_circleCollider.worldPt1.x()-a_circleCollider.Radius &&
              a_circleCollider.worldPt1.x()+a_circleCollider.Radius <= a_rectCollider.worldPt2.x()) {
        if(a_circleCollider.worldPt1.y()-a_circleCollider.Radius <= a_rectCollider.worldPt2.y() &&
                a_circleCollider.worldPt1.y()+a_circleCollider.Radius > a_rectCollider.worldPt2.y())
            collisions.insert(collisions.cend(), 2);
        else if(a_rectCollider.worldPt1.y() <= a_circleCollider.worldPt1.y() + a_circleCollider.Radius &&
                a_rectCollider.worldPt1.y() > a_circleCollider.worldPt1.y() - a_circleCollider.Radius)
            collisions.insert(collisions.cend(), 0);
    }

    if(largeWorldPt1.x() < a_circleCollider.worldPt1.x() && a_circleCollider.worldPt1.x() < largeWorldPt2.x() &&
       largeWorldPt1.y() < a_circleCollider.worldPt1.y() && a_circleCollider.worldPt1.y() < largeWorldPt2.y())
    {
        bool collide = false;
        for(QVector3D corner : vector<QVector3D>{a_rectCollider.worldPt1, a_rectCollider.worldPt2, QVector3D(a_rectCollider.worldPt1.x(), a_rectCollider.worldPt2.y(), 0), QVector3D(a_rectCollider.worldPt2.x(), a_rectCollider.worldPt1.y(), 0)}) {
            if(a_circleCollider.worldPt1.distanceToPoint(corner) <= a_circleCollider.Radius)
                collide = true;
        }
        if(!collide) {return collisions;}

        if(a_circleCollider.worldPt1.x() < a_rectCollider.worldPt1.x()){
            collisions.insert(collisions.cend(), 3); // Left
        }
        if(a_circleCollider.worldPt1.x() > a_rectCollider.worldPt2.x()){
            collisions.insert(collisions.cend(), 1); // Right
        }
        if (a_circleCollider.worldPt1.y() > a_rectCollider.worldPt2.y()){
            collisions.insert(collisions.cend(), 2); // Top
        }
        if (a_circleCollider.worldPt1.y() < a_rectCollider.worldPt1.y()){
            collisions.insert(collisions.cend(), 0); // Bottom
        }
    }
    return collisions;
}

QVector3D CollisionManager::IsCircleCollidingWithCircle(Collider collider, Collider otherCollider) {
    if(collider.worldPt1.distanceToPoint(otherCollider.worldPt1) <= collider.Radius + otherCollider.Radius) {
        return (collider.worldPt1 - otherCollider.worldPt1).normalized();
    }
    return QVector3D(0, 0, 0);
}

vector<vector<QVector3D>> CollisionManager::GetSides(Collider collider) {
    vector<QVector3D> side1 = {collider.worldPt1, QVector3D(collider.worldPt2.x(), collider.worldPt1.y(), 0)};
    vector<QVector3D> side2 = {QVector3D(collider.worldPt2.x(), collider.worldPt1.y(), 0), collider.worldPt2};
    vector<QVector3D> side3 = {collider.worldPt2, QVector3D(collider.worldPt1.x(), collider.worldPt2.y(), 0)};
    vector<QVector3D> side4 = {QVector3D(collider.worldPt1.x(), collider.worldPt2.y(), 0), collider.worldPt1};

    vector<vector<QVector3D>> sides;
    sides.insert(sides.end(), {side1, side2, side3, side4});
    return sides;
}

//QVector3
