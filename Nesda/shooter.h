#include "entity.h"
#ifndef SHOOTER_H
#define SHOOTER_H


class Shooter : public Entity
{
public:
    Shooter(QVector3D, QVector3D);
    Shooter();
};

#endif // SHOOTER_H
