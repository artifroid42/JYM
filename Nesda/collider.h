#include <QVector3D>
#include <vector>
#ifndef COLLIDER_H
#define COLLIDER_H

using namespace std;

class Collider
{
public:
    Collider(QVector3D, QVector3D); // Rect
    Collider(float radius); //Circle
    Collider();

    QVector3D localPt1;
    QVector3D localPt2;
    QVector3D worldPt1;
    QVector3D worldPt2;

    //Circle
    QVector3D worldPt3;
    QVector3D worldPt4;

    bool IsCircle = false;
    float Radius;

    vector<vector<QVector3D>> GetSides();

    void SetWorldPosition(QVector3D);
};

#endif // COLLIDER_H
