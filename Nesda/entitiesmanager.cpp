#include "entitiesmanager.h"
#include <iostream>

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

    vector<Entity> circleWalls = vector<Entity>();
    circleWalls.insert(circleWalls.cend(), Entity(QVector3D(-3,2,0), 1.5, QVector3D(0, 0, 1)));
    circleWalls.insert(circleWalls.cend(), Entity(QVector3D(-2.5,-0.5,0), 0.35, QVector3D(0, 0, 1)));

    for(Entity circleWall : circleWalls) {
        circleWall.collider.SetWorldPosition(circleWall.worldPosition);
        circleObstacles.insert(circleObstacles.cend(), circleWall);
    }
}

void EntitiesManager::AddBall(ProjectileBehaviour &ball){
    if(balls.size()>0)
        cout << balls.begin()->_speed << " " << balls.begin()->worldPosition.y() << endl;
    balls.insert(balls.cend(), ball);
}

void EntitiesManager::RemoveBall(){

}

void EntitiesManager::checkBallsToDelete(int currentTime) {
    if(balls.size() == 0) {return;}
    if(currentTime - balls.begin()->spawnTime >= ballsLifeTime)
        balls.erase(balls.begin());
}

