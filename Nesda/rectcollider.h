#include "collider.h"
#ifndef RECTCOLLIDER_H
#define RECTCOLLIDER_H

using namespace std;

class RectCollider : public Collider
{
public:
    RectCollider();
    RectCollider(QVector3D, QVector3D);
    int getCollidingDirection(Collider other);
};
#endif
