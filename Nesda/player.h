#include "shooter.h"
#ifndef PLAYER_H
#define PLAYER_H


class Player : public Shooter
{
public:
    Player(QVector3D, QVector3D, QVector3D);
    Player();
};

#endif // PLAYER_H
