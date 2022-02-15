#ifndef ENTITIESMANAGER_H
#define ENTITIESMANAGER_H
#include "entity.h"
#include "player.h"
#include "projectilebehaviour.h"
#include "target.h"

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
    Entity target;
    void CreateObstacles();
    void checkBallsToDelete(int);
    void SetTarget(Target);
    void RemoveTarget();
    bool hasTarget = false;
    void RemoveBall(Entity);
private:
    int ballsLifeTime = 3000;
};

#endif // ENTITIESMANAGER_H
