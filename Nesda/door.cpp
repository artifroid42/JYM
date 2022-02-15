#include "door.h"

Door::Door()
{

}

Door::Door(QVector3D spawnPos, QVector3D colliderPt1, QVector3D colliderPt2, QVector3D _color, int _doorID) : Entity(spawnPos, colliderPt1, colliderPt2, _color)
{
    doorID = _doorID;
}
