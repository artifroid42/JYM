#ifndef ENTITIESMANAGER_H
#define ENTITIESMANAGER_H
#include "entity.h"
#include "player.h"
#include "projectilebehaviour.h"

class EntitiesManager
{
public:
    EntitiesManager();
    vector<Entity> rectObstacles = vector<Entity>();
    vector<Entity> circleObstacles = vector<Entity>();
    vector<Entity> doorsAvailable = vector<Entity>();
    vector<ProjectileBehaviour> balls = vector<ProjectileBehaviour>();
    void AddBall(ProjectileBehaviour &ball);
    void RemoveBall();
    Entity doorTop;
    Entity doorLeft;
    Entity doorRight;
    Entity doorBottom;
    void CreateObstacles();
};

#endif // ENTITIESMANAGER_H
