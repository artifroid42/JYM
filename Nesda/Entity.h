#ifndef ENTITY_H
#define ENTITY_H
#include <collider.h>

class Entity
{

public:
    Entity(QVector3D, QVector3D);
    Collider collider;
    int x;
};

#endif // ENTITY_H
