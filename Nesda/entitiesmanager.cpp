#include "entitiesmanager.h"

EntitiesManager::EntitiesManager(){}

void EntitiesManager::CreateObstacles() {
    vector<Entity> walls = vector<Entity>();
    walls.insert(walls.cend(), Entity(QVector3D(1,2,0),QVector3D(0,0,0),QVector3D(2.4,2,0), QVector3D(0, 0, 1)));
    walls.insert(walls.cend(), Entity(QVector3D(-2,-2,0),QVector3D(0,0,0),QVector3D(1,2,0), QVector3D(0, 0, 1)));
    walls.insert(walls.cend(), Entity(QVector3D(1.4,0.5,0),QVector3D(0,0,0),QVector3D(1.5,1.5,0), QVector3D(0, 0, 1)));


    walls.insert(walls.cend(), Entity(QVector3D(-8,4,0),QVector3D(0,0,0),QVector3D(14,0.3,0), QVector3D(0.7, 0.7, 0.7)));
    walls.insert(walls.cend(), Entity(QVector3D(-8,-4,0),QVector3D(0,0,0),QVector3D(14,0.3,0), QVector3D(0.7, 0.7, 0.7)));
    walls.insert(walls.cend(), Entity(QVector3D(-5.7,-4,0),QVector3D(0,0,0),QVector3D(0.3,8,0), QVector3D(0.7, 0.7, 0.7)));
    walls.insert(walls.cend(), Entity(QVector3D(5.2,-4,0),QVector3D(0,0,0),QVector3D(0.3,8,0), QVector3D(0.7, 0.7, 0.7)));

    for(Entity wall : walls) {
        wall.collider.SetWorldPosition(wall.worldPosition);
        rectObstacles.insert(rectObstacles.cend(), wall);
    }
}
