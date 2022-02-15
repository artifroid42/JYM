#include "Entity.h"
#ifndef DOOR_H
#define DOOR_H


class Door : public Entity
{
public:
    Door();
    Door(QVector3D spawnPos, QVector3D colliderPt1, QVector3D colliderPt2, QVector3D _color, int doorID);

    int doorID;
};

#endif // DOOR_H
