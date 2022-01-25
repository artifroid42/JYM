#include <QVector3D>

#ifndef COLLIDER_H
#define COLLIDER_H

class Collider
{
public:
    Collider(QVector3D, QVector3D);
    Collider();
    QVector3D vecPt1;
    QVector3D vecPt2;
    bool IsColliding(Collider, QVector3D);

private :
    bool AreSegmentsCrossing(QVector3D, QVector3D, QVector3D, QVector3D);

};

#endif // COLLIDER_H
