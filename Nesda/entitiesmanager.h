#ifndef ENTITIESMANAGER_H
#define ENTITIESMANAGER_H
#include "entity.h"
#include "player.h"

class EntitiesManager
{
public:
    EntitiesManager();
    vector<Entity> rectObstacles = vector<Entity>();
    vector<Entity> circleObstacles = vector<Entity>();
    Entity doorTop;
    Entity doorLeft;
    Entity doorRight;
    Entity doorBottom;
    void CreateObstacles();
};

#endif // ENTITIESMANAGER_H
