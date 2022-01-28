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
    ProjectileBehaviour(QVector3D, float, QVector3D);
    void SetFoward(QVector3D);
    void MoveForward();
};

#endif // PROJECTILEBEHAVIOUR_H
