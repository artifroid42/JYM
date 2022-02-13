#ifndef PROJECTILEBEHAVIOUR_H
#define PROJECTILEBEHAVIOUR_H
#include <QVector3D>


class ProjectileBehaviour
{
public:
    float _speed;
    QVector3D _forward;

    ProjectileBehaviour();
    void SetFoward(QVector3D);
    void MoveForward();
};

#endif // PROJECTILEBEHAVIOUR_H
