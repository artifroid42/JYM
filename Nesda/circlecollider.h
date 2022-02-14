#ifndef CIRCLECOLLIDER_H
#define CIRCLECOLLIDER_H
#include "QVector3D"
#include "collider.h"

class CircleCollider : public Collider
{
public:
    CircleCollider();
    CircleCollider(float radius);
};

#endif // CIRCLECOLLIDER_H
