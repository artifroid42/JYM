#ifndef ENTITY_H
#define ENTITY_H
#include <collider.h>

class Entity
{

public:
    Entity(QVector3D, QVector3D, QVector3D, QVector3D);
    Entity();
    Collider collider;
    QVector3D worldPosition;
    QVector3D color;
};

#endif // ENTITY_H
