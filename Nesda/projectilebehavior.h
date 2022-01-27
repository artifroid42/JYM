#ifndef PROJECTILEBEHAVIOR_H
#define PROJECTILEBEHAVIOR_H
#include <QVector2D>


class ProjectileBehavior
{
public:
    float _speed;
    QVector2D _forward;

    ProjectileBehavior();
    void Init();
    void MoveForward();
};

#endif // PROJECTILEBEHAVIOR_H
