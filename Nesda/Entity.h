#ifndef ENTITY_H
#define ENTITY_H
#include "rectcollider.h"
#include "circlecollider.h"

class Entity
{

public:
    Entity(QVector3D, QVector3D, QVector3D, QVector3D); // Rect
    Entity(QVector3D, float, QVector3D); // Circle
    Entity();
    Collider collider;
    QVector3D worldPosition;
    QVector3D color;
};

#endif // ENTITY_H
