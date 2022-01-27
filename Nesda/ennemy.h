#include "shooter.h"

#ifndef ENNEMY_H
#define ENNEMY_H


class Enemy : public Shooter
{
public:
    Enemy(QVector3D, QVector3D, QVector3D);
    Enemy();
};

#endif // ENNEMY_H
