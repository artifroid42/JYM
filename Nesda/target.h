#ifndef TARGET_H
#define TARGET_H
#include "entity.h"

class Target : public Entity
{
public:
    Target();
    Target(QVector3D, QVector3D, QVector3D, QVector3D); // Rect
};

#endif // TARGET_H
