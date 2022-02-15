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
    vector<Entity> doors = vector<Entity>();
    vector<ProjectileBehaviour> balls = vector<ProjectileBehaviour>();
    void AddBall(ProjectileBehaviour &ball);
    void RemoveBall();
    Entity doorTop;
    Entity doorLeft;
    Entity doorRight;
    Entity doorBottom;
    void CreateObstacles();
    void CreateDoors();
    vector<int> CreateRoom(); // Renvoie un vector composé de 5 variblaes : les portes ouvertes et l'ID de la room
    int _roomsIDs;
    vector<int> _doorsopen; //  vers de 4 variables : 0 porte Top, 1 Porte Right , 2 Porte Bot, 3 Porte Left. Si une de ces variabels est a 1 c'est qu'une des portes est présentes.
};

#endif // ENTITIESMANAGER_H
