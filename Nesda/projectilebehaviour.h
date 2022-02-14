#ifndef PROJECTILEBEHAVIOUR_H
#define PROJECTILEBEHAVIOUR_H
#include <QVector3D>
#include "Entity.h"


class ProjectileBehaviour : public Entity
{
public:
    float _speed;
    QVector3D _forward;

    ProjectileBehaviour();
    ProjectileBehaviour(QVector3D spawnPos, float radius, float speed, QVector3D color, QVector3D forward);
    void SetForward(QVector3D);
    void MoveForward();
    void RectBounce(int sideID);
    void NormalBounce(QVector3D normal);
};

#endif // PROJECTILEBEHAVIOUR_H
